#pragma once

#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map> 

class Node;

using namespace std;

class Environment {
	public:
		map<string, string> vars;
    map<string, Node*> funcs;

		Environment();

		void declare(string var, string val = "");

		bool isDeclared(string var);
		
		string get(string var);

    void declareFunc(string name, Node* func);
};