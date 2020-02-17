#include <iostream>
#include "binary.tab.hh"

extern Node root;

void yy::parser::error(std::string const&err)
{
  std::cout << "It's one of the bad ones... " << err << std::endl;
}

int main(int argc, char **argv)
{
yy::parser parser;
  if(!parser.parse()){
  	root.dump();
    root.dumpRoot();
  }
  return 0;
}