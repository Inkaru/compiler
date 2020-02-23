#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>
#include <map> 

using namespace std;

class Environment {
	public:
		map<string, string> env;

		Environment(){}

		void declare(string var, string val = ""){
			env.insert({var,val});
		}

		bool isDeclared(string var){
			return env.find(var) != env.end();
		}
		
		string get(string var){
			return env.find(var)->second;
		}
};

class Node
{
public:
	std::string tag;
	int node_id;
	std::list<Node *> children;
	Node(std::string t, int i) : tag(t), node_id(i) {}
	Node()
	{
		tag = "uninitialised";
	} // Bison needs this.

	~Node()
	{
		for (auto n : children)
			delete n;
	}

	void dump(int depth = 0)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << tag << std::endl;
		for (auto i : children)
			i->dump();
	}

	void dumpRoot()
	{
		ofstream MyFile("source.md");
		MyFile << "```graphviz" << std::endl;
		MyFile << "digraph {" << std::endl;
		dumpDot(MyFile);
		MyFile << "}" << endl;
		MyFile << "```";
		MyFile.close();
	}

	void dumpDot(ofstream &file)
	{
		file << node_id << " [label=\"" << tag << ": " << getValue() << "\"];" << '\n';
		for (auto i : children)
			file << node_id << " -> " << (*i).node_id << '\n';
		for (auto i : children)
			i->dumpDot(file);
	}

	virtual string getValue() = 0;

	virtual string eval(Environment& env) =0;
	virtual void execute(Environment& env) =0;
};

class StdNode : public Node
{
public:
	string value;
	StdNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue() { return value; }

	void execute(Environment& env) {
		cout << "stdnode;";
		for (auto n: children){
			n->execute(env);
		}
	}

	string eval(Environment& env){}
};

class ExpNode : public Node
{
public:
	Node *left;
	Node *right;

	ExpNode(string t, Node *left, Node *right, int i) : Node(t, i), left(left), right(right) {}

};

class ExpNodeImpl : public ExpNode
{
public:
	ExpNodeImpl(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i) {}

	string getValue() { return "EXP"; }

	void execute(Environment& env){
		cout << "expImplNode;";
	}

	string eval(Environment& env){ return "0";}
};

class PlusNode : public ExpNode
{
public:
	PlusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "PLUS"; }

	void execute(Environment& env){
		cout << "PLUS" << eval(env) ;
	}

	string eval(Environment& env)
	{
		return to_string(stof(left->eval(env)) + stof(right->eval(env)));
	}
};

class MinusNode : public ExpNode
{
public:
	MinusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MINUS"; }

	void execute(Environment& env){
		cout << "MINUS" << eval(env) ;
	}

	string eval(Environment& env)
	{
		return to_string(stof(left->eval(env)) - stof(right->eval(env)));
	}
};

class MultNode : public ExpNode
{
public:
	MultNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MULT"; }

	void execute(Environment& env){
		cout << "MULT" << eval(env) ;
	}

	string eval(Environment& env)
	{
		return to_string(stof(left->eval(env)) * stof(right->eval(env)));
	}
};

class DivNode : public ExpNode
{
public:
	DivNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "DIV"; }

	void execute(Environment& env){
		cout << "DIV" << eval(env) ;
	}

	string eval(Environment& env)
	{
		return to_string(stof(left->eval(env)) / stof(right->eval(env)));
	}
};

class ModNode : public ExpNode
{
public:
	ModNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MOD"; }

	void execute(Environment& env){
		cout << "MOD" << eval(env) ;
	}

	string eval(Environment& env)
	{
		float a = stof(left->eval(env));
		float b = stof(right->eval(env));
		return to_string(a - floor(a/b)*b);
	}
};

class ExpoNode : public ExpNode
{
public:
	ExpoNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "EXPO"; }

	void execute(Environment& env){
		cout << "EXPO" << eval(env) ;
	}

	string eval(Environment& env)
	{
		return to_string(pow(stof(left->eval(env)), stof(right->eval(env))));
	}
};

class IntNode : public ExpNode
{
public:
	int value;
	IntNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(stoi(v)) {}

	string getValue() { return to_string(value); }

	void execute(Environment& env){}

	string eval(Environment& env)
	{
		return to_string(value);
	}
};

class TrueNode : public ExpNode
{
public:
	int value = 1;
	TrueNode(int i) : ExpNode("TRUE", nullptr, nullptr, i) {}

	string getValue() { return to_string(value); }

	void execute(Environment& env){}

	string eval(Environment& env)
	{
		return to_string(value);
	}
};

class FalseNode : public ExpNode
{
public:
	int value = 0;
	FalseNode(int i) : ExpNode("TRUE", nullptr, nullptr, i) {}

	string getValue() { return to_string(value); }

	void execute(Environment& env){}

	string eval(Environment& env)
	{
		return to_string(value);
	}
};

class StringNode : public ExpNode
{
public:
	string value;
	StringNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(v) {}

	string getValue() { return value; }

	void execute(Environment& env){}

	string eval(Environment& env){ return value; }
};

class ArgsNode : public Node {
	public:
		ArgsNode(string t, int i): Node(t,i){}

		string getValue(){return "";}

		void execute(Environment& env){}

		string eval(Environment& env){}

		Node* get(int i){
			list<Node*>::iterator it = next(children.begin(), i);
			return (*it);
		}
};

class ExpListNode : public Node {
	public:
	ExpListNode(string t, int i): Node(t,i){}

	string getValue(){return "";}

	void execute(Environment& env){}

	string eval(Environment& env){}

	Node* get(int i){
		list<Node*>::iterator it = next(children.begin(), i);
		return (*it);
	}
};

class VarListNode : public Node {
	public:
	VarListNode(string t, int i): Node(t,i){}

	string getValue(){return "";}

	void execute(Environment& env){}

	string eval(Environment& env){}

	Node* get(int i){
		list<Node*>::iterator it = next(children.begin(), i);
		return (*it);
	}
};

class FuncCallNode : public Node {
	public:
		Node* left;
		Node* right;
		FuncCallNode(string t, Node* left, Node* right, int i) : Node(t,i), left(left), right(right) {} 

		string getValue(){ return "";}

		void execute(Environment& env){
			if(left->getValue() == "print"){

				if(dynamic_cast<ArgsNode*>(right) != nullptr){
					ArgsNode* args = dynamic_cast<ArgsNode*>(right);
					Node* res = args->get(0);

					if(dynamic_cast<ExpListNode *>(res) != nullptr){
						cout << "debug : explist" << endl;
						for(auto n: res->children){
							cout << n->eval(env) << " ";
						}

						cout << endl ;
					}

					if(dynamic_cast<ExpNode *>(res) != nullptr){
						cout << "debug : exp" << endl;
						cout << res->eval(env) << endl;
					}

					if(dynamic_cast<StringNode *>(res) != nullptr){
						cout << "debug : string" << endl;
						cout << res->getValue() << endl;
					}
				}

				if(dynamic_cast<StringNode*>(right) != nullptr){
					StringNode* str = dynamic_cast<StringNode*>(right);
					cout << "debug : string" << endl;
					cout << str->getValue() << endl;
				}

			} else {
				cout << "func not implemented yet" << endl;
			}
		}

		string eval(Environment& env){}
};



class AssignNode : public Node
{
public:
	Node *left;
	Node *right;

	AssignNode(string t, VarListNode *left, ExpListNode *right, int i) : Node(t, i), left(left), right(right){}

	string getValue() { return "Assign"; }

	void execute(Environment& env) {
		cout << "Assign Node;";

		auto itVar = left->children.begin();
		auto itExp = right->children.begin();

		string var;
		string exp;

		while(itVar != left->children.end() && itExp != left->children.end()){

			var = (*itVar)->getValue();
			exp = (*itExp)->eval(env);
			cout << "debug : " << var << "=" << exp << endl;

			env.declare(var,exp);

			itVar++;
			itExp++;
		}

	}

	string eval(Environment& env){}
};