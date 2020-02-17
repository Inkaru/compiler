#include <list>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Node
{
public:
	std::string tag, value;
	int node_id;
	std::list<Node> children;
	Node(std::string t, std::string v, int i) : tag(t), value(v), node_id(i) {}
	Node()
	{
		tag = "uninitialised";
		value = "uninitialised";
	} // Bison needs this.
	void dump(int depth = 0)
	{
		for (int i = 0; i < depth; i++)
			std::cout << "  ";
		std::cout << tag << ":" << value << std::endl;
		for (auto i = children.begin(); i != children.end(); i++)
			(*i).dump(depth + 1);
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
		file << node_id << " [label=\"" << tag << ": " << value << "\"];" << '\n';
		for (auto i = children.begin(); i != children.end(); i++)
			file << node_id << " -> " << (*i).node_id << '\n';
		for (auto i = children.begin(); i != children.end(); i++)
			(*i).dumpDot(file);
	}
};


