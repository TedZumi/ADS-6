// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string str = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout << "File error!" << std::endl;
    return tree;
  }
  char diff = 'a' - 'A';
  while (!file.eof()) {
    char ch = file.get();
    if (((ch >= 'a') && (ch <= 'z')) || ((ch >= 'A') && (ch <= 'Z'))) {
      if ((ch >= 'A') && (ch <= 'Z'))
        ch += diff;
      str += ch;
    } else if (str != "") {
        tree.add(str);
        str = "";
    }
  }
  file.close();
  return tree;
}
