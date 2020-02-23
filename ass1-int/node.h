#include <list>
#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Environment {
	public:

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

	virtual string eval() =0;
	virtual void execute() =0;
};

class StdNode : public Node
{
public:
	string value;
	StdNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue() { return value; }

	void execute() {
		cout << "stdnode;";
		for (auto n: children){
			n->execute();
		}
	}

	string eval(){}
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

	void execute(){
		cout << "expImplNode;";
	}

	string eval(){}
};

class PlusNode : public ExpNode
{
public:
	PlusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "PLUS"; }

	void execute(){
		cout << "PLUS" << eval() ;
	}

	string eval()
	{
		return to_string(stof(left->eval()) + stof(right->eval()));
	}
};

class MinusNode : public ExpNode
{
public:
	MinusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MINUS"; }

	void execute(){
		cout << "MINUS" << eval() ;
	}

	string eval()
	{
		return to_string(stof(left->eval()) - stof(right->eval()));
	}
};

class MultNode : public ExpNode
{
public:
	MultNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MULT"; }

	void execute(){
		cout << "MULT" << eval() ;
	}

	string eval()
	{
		return to_string(stof(left->eval()) * stof(right->eval()));
	}
};

class DivNode : public ExpNode
{
public:
	DivNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "DIV"; }

	void execute(){
		cout << "DIV" << eval() ;
	}

	string eval()
	{
		return to_string(stof(left->eval()) / stof(right->eval()));
	}
};

class ModNode : public ExpNode
{
public:
	ModNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MOD"; }

	void execute(){
		cout << "MOD" << eval() ;
	}

	string eval()
	{
		float a = stof(left->eval());
		float b = stof(right->eval());
		return to_string(a - floor(a/b)*b);
	}
};

class ExpoNode : public ExpNode
{
public:
	ExpoNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "EXPO"; }

	void execute(){
		cout << "EXPO" << eval() ;
	}

	string eval()
	{
		return to_string(pow(stof(left->eval()), stof(right->eval())));
	}
};

class IntNode : public ExpNode
{
public:
	int value;
	IntNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(stoi(v)) {}

	string getValue() { return to_string(value); }

	void execute(){}

	string eval()
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

	void execute(){}

	string eval(){ return value; }
};

class ArgsNode : public Node {
	public:
		ArgsNode(string t, int i): Node(t,i){}

		string getValue(){return "";}

		void execute(){}

		string eval(){}

		Node* get(int i){
			list<Node*>::iterator it = next(children.begin(), i);
			return (*it);
		}
};

class ExpListNode : public Node {
	public:
	ExpListNode(string t, int i): Node(t,i){}

	string getValue(){return "";}

	void execute(){}

	string eval(){}

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

		void execute(){
			if(left->getValue() == "print"){

				if(dynamic_cast<ArgsNode*>(right) != nullptr){
					ArgsNode* args = dynamic_cast<ArgsNode*>(right);
					Node* res = args->get(0);

					if(dynamic_cast<ExpListNode *>(res) != nullptr){
						cout << "debug : explist" << endl;
						for(auto n: res->children){
							cout << n->eval() << " ";
						}

						cout << endl ;
					}

					if(dynamic_cast<ExpNode *>(res) != nullptr){
						cout << "debug : exp" << endl;
						cout << res->eval() << endl;
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

		string eval(){}
};
