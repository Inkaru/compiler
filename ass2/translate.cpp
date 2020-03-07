#include "translate.h"

set<string> names{};
map<string, int> arrays{};

void ThreeAd::dump(ofstream &file)
{
  cout << name << " := ";
  cout << lhs << " " << op << " " << rhs << endl;
  file << name << ":=" << lhs << " " << op << " " << rhs << '\n';
}

void BBlock::dumpDot(ofstream &file)
{
  cout << "BBlock @ " << this << endl;
  cout << name << endl;
  file << "BB" << this << " [label=\"" << name + '\n';
  for (auto i : code)
  {
    file << i << endl;
  }
  file << "\"];" << '\n';
  cout << "True:  " << tExit << endl;
  cout << "False: " << fExit << endl;

  if (tExit != NULL)
  {
    file << "BB" << this << " -> "
         << "BB" << tExit << '\n';
  }
  if (fExit != NULL)
  {
    file << "BB" << this << " -> "
         << "BB" << fExit << '\n';
  }
}

void BBlock::dumpRec(ofstream &file)
{

  file << name << ":" << endl;

  for (string i : code)
  {
    file << i << endl;
  }

  file << endl;

  if (isFinal)
  {
    file << "exit(0);\n\n";
  }
}

int BBlock::nCounter = 0;

void dumpToCode(BBlock *start)
{
  ofstream Source("source.cc");
  Source << "#include <iostream>" << endl
         << "#include <cmath>" << endl
         << endl
         << "int main() {" << endl
         << endl;

  for (auto n : names)
  {
    Source << "double " << n << " = 0;\n";
  }

  Source << endl;

  list<BBlock *> done, todo;
  todo.push_back(start);
  while (todo.size() > 0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->dumpRec(Source);
    done.push_back(next);
    if (next->tExit != NULL && find(done.begin(), done.end(), next->tExit) == done.end() && find(todo.begin(), todo.end(), next->tExit) == todo.end())
      todo.push_back(next->tExit);
    if (next->fExit != NULL && find(done.begin(), done.end(), next->fExit) == done.end() && find(todo.begin(), todo.end(), next->fExit) == todo.end())
      todo.push_back(next->fExit);
  }

  Source << "}" << endl;
  Source.close();
}


void dumpToDot(BBlock *start)
{
  ofstream MyFile("CFG.md");
  MyFile << "```graphviz" << std::endl;
  MyFile << "digraph {" << std::endl;
  MyFile << "node [shape=box];" << endl;

  set<BBlock *> done, todo;
  todo.insert(start);
  while (todo.size() > 0)
  {
    // Pop an arbitrary element from todo set
    auto first = todo.begin();
    BBlock *next = *first;
    todo.erase(first);
    next->dumpDot(MyFile);
    done.insert(next);
    if (next->tExit != NULL && done.find(next->tExit) == done.end())
      todo.insert(next->tExit);
    if (next->fExit != NULL && done.find(next->fExit) == done.end())
      todo.insert(next->fExit);
  }

  MyFile << "}" << endl;
  MyFile << "```";
  MyFile.close();
}
