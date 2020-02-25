#include <string>
#include <list>

class Node {
	public:
		unsigned int identifier;
		std::string tag, value;
		std::list<Node*> children;

		Node(unsigned i, std::string t, std::string v) : identifier(i), tag(t), value(v) {}
		Node() { identifier = -1; tag="uninitialised"; value="uninitialised"; }

		void dump(int depth=0) {
			for(int i=0; i<depth; i++) {
				std::cout << "  ";
			}
			std::cout << tag << ":" << value << endl;
			for(auto i=children->begin(); i!=children->end(); i++) {
				(*i).dump(depth+1);
			}
		}

		void toDotFile(int depth=0) {
			ofstream outfile;
			outfile.open("dotFile.md");
			outfile << "```graphviz" << endl;
			outfile << "digraph {" << endl;
			toDotFileRec(outfile, 0);
			outfile << "}" << endl;
			outfile.close();
		}

		void toDotFileRec(ofstream &outfile, int depth) {
			outfile << identifier << " [label=\"" << tag<< " " << value << "\"];" << endl;
			for(auto i=children.begin(); i!=children.end(); i++) {
				outfile << identifier << " -> " << (*i).identifier << ";" << endl;
				(*i).toDotFileRec(outfile, depth+1);
			}
		}

		virtual string execute(Environment &environment) = 0;
};

class Chunk : public Node {
	public:
		Chunk(unsigned id) : Node(id, "chunk", "") {}
		Chunk() : Node() {}

		string execute(Environment &environment) override {
			std::cout << "Chunk";
			string destination, source, return_val;
			auto childrenIter = children.begin();
			destination = (*childrenIter).execute(environment);
			childrenIter++;
			source = (*childrenIter).execute(environment);
			childrenIter++;
			environment.setVariableValue(destination, source);

			if (!children.empty()) {
				for (childrenIter; childrenIter != children.end(); childrenIter++) {
					return_val += (*childrenIter).execute(environment);
				}
			}
			return return_val;
		}
};

class Statements : public Node {
	public:
		Statements(unsigned id) : Node(id, "statements", "") {}

		string execute(Environment &environment) override {
			for(auto i=children.begin(); i!=children.end(); i++) {
			}
			return "";
		}
};

class FunctionCall : public Node {
	public:
		FunctionCall(unsigned id) : Node(id, "functioncall", "") {}

		string execute(Environment &environment) override {
			for(auto i=children.begin(); i!=children.end(); i++) {
			}
			return "";
		}
};

class Identifier : public Node {
	public:
		Identifier(unsigned id, string value) : Node(id, "functioncall", value) {}

		string execute(Environment &environment) override {
			for(auto i=children.begin(); i!=children.end(); i++) {
			}
			return "";
		}
};

class Expressions : public Node {
	public:
		Expressions(unsigned id) : Node(id, "expressions", "") {}

		string execute(Environment &environment) override {
			for(auto i=children.begin(); i!=children.end(); i++) {
			}
			return "";
		}
};

class Number : public Node {
	public:
		Number(unsigned id, string value) : Node(id, "number", value) {}

		string execute(Environment &environment) override {
			for(auto i=children.begin(); i!=children.end(); i++) {
			}
			return "";
		}
};


class Assignment : public Node {
	public:
		Assignment(unsigned id) : Node(id, "assignment", "") {}

		string execute(Environment &environment) override {
			string destination, source, return_val;
			auto childrenIter = children.begin();
			destination = (*childrenIter).execute(environment);
			childrenIter++;
			source = (*childrenIter).execute(environment);
			childrenIter++;
			environment.setVariableValue(destination, source);

			if (!children.empty()) {
				for (childrenIter; childrenIter != children.end(); childrenIter++) {
					return_val += (*childrenIter).execute(environment);
				}
			}
			return return_val;
		}
};

class If : public Node {
	public:
		If(unsigned id) : Node(id, "if", "") {}

		string execute(Environment &environment) override {
			string destination, source, return_val;
			auto childrenIter = children.begin();
			destination = (*childrenIter).execute(environment);
			childrenIter++;
			source = (*childrenIter).execute(environment);
			childrenIter++;
			environment.setVariableValue(destination, source);

			if (!children.empty()) {
				for (childrenIter; childrenIter != children.end(); childrenIter++) {
					return_val += (*childrenIter).execute(environment);
				}
			}
			return return_val;
		}
};