#pragma once

#include <list>
#include <cstring>
#include <fstream>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

class Node;
class FunctionNode;

using namespace std;

class Environment
{
public:
  map<string, string> vars;
  map<string, FunctionNode *> funcs;
  map<string, vector<string>*> arrays;

  Environment();
  Environment(const Environment &env);

  void declare(string var, string val = "");

  void declareFunc(string name, FunctionNode *func);

  void declareArray(string name, vector<string>* vec);

  bool varIsDeclared(string var);

  bool funcIsDeclared(string var);

  bool arrayIsDeclared(string var);

  string get(string var);

  FunctionNode* getFunc(string name);

  vector<string>* getArray(string name);
};