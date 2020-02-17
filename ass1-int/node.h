#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

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
};

class StdNode : public Node
{
public:
	string value;
	StdNode(string t, string v, int i) : Node(t, i), value(v) {}

	string getValue() { return value; }
};

class ExpNode : public Node
{
public:
	ExpNode *left;
	ExpNode *right;

	ExpNode(string t, ExpNode *left, ExpNode *right, int i) : Node(t, i), left(left), right(right) {}

	virtual float eval() = 0;
	virtual string getValue() = 0;
};

class PlusNode : public ExpNode
{
public:
	PlusNode(string t, ExpNode *left, ExpNode *right, int i) : ExpNode(t, left, right, i) {}

	string getValue() { return "PLUS"; }

	float eval()
	{
		return left->eval() + right->eval();
	}
};

class IntNode : public ExpNode
{
public:
	int value;
	IntNode(string t, string v, int i) : ExpNode(t, nullptr, nullptr, i), value(stoi(v)) {}

	string getValue() { return to_string(value); }

	float eval()
	{
		return value;
	}
};
