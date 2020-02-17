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

class IntNode : public Node {
	public : 

        int value;
		IntNode(string t, int v, int i): Node(t,i), value(v) {}

        void dumpDot(ofstream& file){
            file << node_id << " [label=\"" << tag << ": " << value << "\"];" << '\n';
            for (auto i: children)
                file << node_id << " -> " << (*i).node_id << '\n';
            for (auto i: children)
                i->dumpDot(file);
        }

		int eval() {
			return value;
		}
};


