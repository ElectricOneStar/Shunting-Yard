#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <cstring>
using namespace std;

class Node{
public:
  Node(char* inputData);
  void setRight(Node* inputRight);
  void setLeft(Node* inputLeft);
  void setNext(Node* inputNext);

  void setData(char* inputData);
  Node* getRight();
  Node* getLeft();
  Node* getNext();
  char* getData();
  //char getData();
  int* getPrecedence();
  char* getAssociativity();
  void setPrecedence(int* inputPrecedence);
  void setAssociativity(char* inputAssociativity);
private:
  Node* next;
  Node* right;
  Node* left;
  char* data = new char[20];
  char* associativity = new char;
  int* precedence = new int;
  //char data;
};
#endif
