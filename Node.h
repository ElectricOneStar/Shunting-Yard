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
private:
  Node* next = NULL;
  Node* right = NULL;
  Node* left = NULL;
  char* data = NULL;
};
