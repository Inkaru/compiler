#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map> 

using namespace std;

class Environment {
	public:
		map<string, string> vars;

		Environment(){}

		void declare(string var, string val = ""){
			if(isDeclared(var)) {
				vars.find(var)->second = val;
			}
			else {
				vars.insert({var,val}); 
			}
		}

		bool isDeclared(string var){
			return vars.find(var) != vars.end();
		}
		
		string get(string var){
			return vars.find(var)->second;
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

	virtual string execute(Environment& env) =0;

};

class StdNode : public Node
{
public:
	string value;
	StdNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue() { return value; }

	string execute(Environment& env) {
		cout << "stdnode;";
		for (auto n: children){
			n->execute(env);
		}
		return "0";
	}

};

class VarNode : public Node
{
public:
	string value;
	VarNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue() { return value; }

	string execute(Environment& env) {
		cout << "varnode;";
		return env.get(value);
	}

};

class ExpNode : public Node
{
public:
	Node *left;
	Node *right;

	ExpNode(string t, Node *left, Node *right, int i) : Node(t, i), left(left), right(right) {}

	string childEval(Environment& env, Node* node){
		if(dynamic_cast<VarNode*>(node) != nullptr){
			return env.get(node->getValue());
		}

		if(dynamic_cast<ExpNode*>(node) != nullptr){
			return node->execute(env);
		}
	}

};

class ExpNodeImpl : public ExpNode
{
public:
	ExpNodeImpl(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i) {}

	string getValue() { return "EXP"; }

	string execute(Environment& env){
		cout << "expImplNode;";
		return "0";
	}

};

class PlusNode : public ExpNode
{
public:
	PlusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "PLUS"; }

	string execute(Environment& env){
		return to_string(stof(childEval(env,left)) + stof(childEval(env,right)));
	}

};

class MinusNode : public ExpNode
{
public:
	MinusNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MINUS"; }

	string execute(Environment& env){
		return to_string(stof(childEval(env,left)) - stof(childEval(env,right)));
	}
};

class MultNode : public ExpNode
{
public:
	MultNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MULT"; }

	string execute(Environment& env){
		return to_string(stof(childEval(env,left)) * stof(childEval(env,right)));
	}
};

class DivNode : public ExpNode
{
public:
	DivNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "DIV"; }

	string execute(Environment& env){
		return to_string(stof(childEval(env,left)) / stof(childEval(env,right)));
	}
};

class ModNode : public ExpNode
{
public:
	ModNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "MOD"; }

	string execute(Environment& env){
		float a = stof(childEval(env,left));
		float b = stof(childEval(env,right));
		return to_string(a - floor(a/b)*b);
	}
};

class ExpoNode : public ExpNode
{
public:
	ExpoNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "EXPO"; }

	string execute(Environment& env){
		return to_string(pow(stof(childEval(env,left)), stof(childEval(env,right))));
	}
};

class EquNode : public ExpNode
{
public:
	EquNode(string t, Node *left, Node *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "EQU"; }

	string execute(Environment& env){
		if(stof(childEval(env,left)) == stof(childEval(env,right)))
			return "1";
		else
			return "0";
	}
};

class NegNode : public ExpNode
{
public:
	NegNode(string t, Node *right, int i) : ExpNode(t, nullptr, right, i) {}

	string getValue() { return "NEG"; }

	string execute(Environment& env){
		return to_string( - stof(childEval(env,right)));
	}
};

class IntNode : public ExpNode
{
public:
	int value;
	IntNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(stoi(v)) {}

	string getValue() { return to_string(value); }

	string execute(Environment& env){
		return to_string(value);
	}
};

class TrueNode : public ExpNode
{
public:
	int value = 1;
	TrueNode(int i) : ExpNode("TRUE", nullptr, nullptr, i) {}

	string getValue() { return to_string(value); }

	string execute(Environment& env){
		return to_string(value);
	}
};

class FalseNode : public ExpNode
{
public:
	int value = 0;
	FalseNode(int i) : ExpNode("TRUE", nullptr, nullptr, i) {}

	string getValue() { return to_string(value); }

	string execute(Environment& env){
		return to_string(value);
	}
};

class StringNode : public ExpNode
{
public:
	string value;
	StringNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(v) {}

	string getValue() { return value; }

	string execute(Environment& env){ return value; }
};

class ArgsNode : public Node {
	public:
		ArgsNode(string t, int i): Node(t,i){}

		string getValue(){return "";}

		string execute(Environment& env){ return "0"; }

		Node* get(int i){
			list<Node*>::iterator it = next(children.begin(), i);
			return (*it);
		}
};

class ExpListNode : public Node {
	public:
	ExpListNode(string t, int i): Node(t,i){}

	string getValue(){return "";}

	string execute(Environment& env){ return "0"; }

	Node* get(int i){
		list<Node*>::iterator it = next(children.begin(), i);
		return (*it);
	}
};

class VarListNode : public Node {
	public:
	VarListNode(string t, int i): Node(t,i){}

	string getValue(){return "";}

	string execute(Environment& env){ return "0"; }

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

		string execute(Environment& env){
			if(left->getValue() == "print" || left->getValue() == "io.write"){

				bool doesReturn = left->getValue() == "print";

				if(dynamic_cast<ArgsNode*>(right) != nullptr){
					ArgsNode* args = dynamic_cast<ArgsNode*>(right);
					Node* res = args->get(0);

					if(dynamic_cast<ExpNode *>(res) != nullptr){
						cout << "debug : exp" << endl;
						cout << res->execute(env);
					}

					if(dynamic_cast<StringNode *>(res) != nullptr){
						cout << "debug : string" << endl;
						cout << res->getValue();
					}

					if(dynamic_cast<ExpListNode *>(res) != nullptr){
						cout << "debug : explist" << endl;

						for(auto n: res->children){
							cout << n->execute(env) << " " ;
						}
					}

					if(doesReturn){
						cout << endl;
					}

				}

				if(dynamic_cast<StringNode*>(right) != nullptr){
					StringNode* str = dynamic_cast<StringNode*>(right);
					cout << "debug : string" << endl;
					cout << str->getValue() << endl;
				}

			} else if (left->getValue() == "io.read") {

				// ArgsNode* args = dynamic_cast<ArgsNode*>(right);
				// ExpListNode* explist = dynamic_cast<ExpListNode*>(args->get(0));
				// StringNode* str = dynamic_cast<StringNode*>(explist->get(0));

				string val;

				// cin.ignore();
				// cin.sync(); cin.get(); cin.clear();
        // getline(cin, val); 

				// if (cin.fail ()){
				// 	cout << "error" << endl;
				// }

				// int iValid = 1;
				// while (iValid == 1)
				// {
				// 	if (cin.fail())
				// 	{
				// 					cin.ignore();
				// 					cout<<"Wrong! Enter a #!"<<endl;
				// 					cin>>val;
				// 	} //closes if
				// 	else
				// 					iValid = 0;
				// }

				return "1";

			} else {
				cout << "func not implemented yet" << endl;
			}

			return "0";
		}

};

class AssignNode : public Node
{
public:
	Node *left;
	Node *right;

	AssignNode(string t, VarListNode *left, ExpListNode *right, int i) : Node(t, i), left(left), right(right){}

	string getValue() { return "Assign"; }

	string execute(Environment& env) {
		cout << "Assign Node;";

		auto itVar = left->children.begin();
		auto itExp = right->children.begin();

		string var;
		string exp;

		while(itVar != left->children.end() && itExp != left->children.end()){

			var = (*itVar)->getValue();
			exp = (*itExp)->execute(env);
			cout << "debug : " << var << "=" << exp << endl;

			env.declare(var,exp);

			itVar++;
			itExp++;
		}

		return "0";

	}

};

class ForNode : public Node
{
public:
	Node* var;
	Node* exp1;
	Node* exp2;
	Node* block;

	ForNode(string t, Node* v, Node* e1, Node* e2, Node* blo, int i) : Node(t, i), var(v), exp1(e1), exp2(e2), block(blo) {}

	string getValue() { return "FOR"; }

	string execute(Environment& env) {
		cout << "For Node;";

		env.declare(var->getValue(), exp1->execute(env));

		string lim = exp2->execute(env);

		while(env.get(var->getValue()) != lim){
			block->execute(env);
			env.declare(var->getValue(), to_string(1+stoi(env.get(var->getValue()))));
		}
		block->execute(env);

		return "0";

	}

};

class IfNode : public Node {
	public:
		Node* condition;
		Node* block;

		IfNode(string t, Node* c, Node* blo, int i) : Node(t, i), condition(c), block(blo) {}

		string getValue() { return "IF"; }

		string execute(Environment& env) {
		cout << "If Node;";

		if(condition->execute(env) != "0"){
			block->execute(env);
		}

		return "0";

	}
};