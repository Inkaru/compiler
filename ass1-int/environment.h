#pragma once

#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map> 

class Node;
class FunctionNode;

using namespace std;

class Environment {
	public:
		map<string, string> vars;
    map<string, FunctionNode*> funcs;

		Environment();
    Environment(const Environment &env);

		void declare(string var, string val = "");

		bool varIsDeclared(string var);

    bool funcIsDeclared(string var);
		
		string get(string var);

    FunctionNode* getFunc(string name);

    void declareFunc(string name, FunctionNode* func);
};