#pragma once
#include <string>
#include <list>
#include <set>
#include <map>
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

extern set<string> names;
extern map<string, int> arrays;

/************* Three Address Instructions *************/
class ThreeAd
{
public:
	string name, lhs, rhs;
	char op;

	ThreeAd(string name, char op, string lhs, string rhs) : name(name), op(op), lhs(lhs), rhs(rhs) {}

	void dump(ofstream &file);
};

class BBlock
{
private:
	static int nCounter;

public:
	list<ThreeAd> instructions;
	list<string> code;
	BBlock *tExit, *fExit;
	string name;
	bool isFinal;

	BBlock() : tExit(NULL), fExit(NULL), name("blk" + to_string(nCounter++)), isFinal(true)
	{
	}

	void dumpRec(ofstream &file);
	void dumpDot(ofstream &file);
};

void dumpToCode(BBlock* start);
void dumpToDot(BBlock* start);