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
	std::list<Node*> children;
	Node(std::string t, int i) : tag(t), node_id(i) {}
	Node()
	{
		tag = "uninitialised";
	} // Bison needs this.

    ~Node(){
        for(auto n: children)
            delete n;
    }

	void dump(int depth = 0)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << tag << std::endl;
		for (auto i: children)
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

	virtual void dumpDot(ofstream &file) =0;
};

class StdNode : public Node {
	public : 

        string value;
		StdNode(string t, string v, int i): Node(t,i), value(v) {}

        void dumpDot(ofstream& file){
            file << node_id << " [label=\"" << tag << ": " << value << "\"];" << '\n';
            for (auto i: children)
                file << node_id << " -> " << (*i).node_id << '\n';
            for (auto i: children)
                i->dumpDot(file);
        }
};

class CalcNode : public Node {
    public: 
        CalcNode* left;
        CalcNode* right;

        CalcNode(string t, CalcNode* left, CalcNode* right, int i): Node(t,i), left(left), right(right) {}

        virtual float eval() =0;
};

class PlusNode : public CalcNode {
    public:
        PlusNode(string t, CalcNode* left, CalcNode* right, int i): CalcNode(t,left,right,i) {}

        float eval(){
            return left->eval() + right->eval();
        }
};

class IntNode : public CalcNode {
	public : 

        int value;
		IntNode(string t, int v, int i): CalcNode(t,nullptr,nullptr,i), value(v) {}

        void dumpDot(ofstream& file){
            file << node_id << " [label=\"" << tag << ": " << value << "\"];" << '\n';
            for (auto i: children)
                file << node_id << " -> " << (*i).node_id << '\n';
            for (auto i: children)
                i->dumpDot(file);
        }

		float eval() {
			return value;
		}
};


