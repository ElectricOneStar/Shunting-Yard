// Node class by Andrew Thomas. This is the node used in stack, queue and tree
#include <iostream>
#include <cstdlib>
#include <cstring>
#include "Node.h"
using namespace std;
Node::Node(char* inputData){ // constructor
  data = inputData;
  next = NULL;
  right = NULL;
  left = NULL;
//data = inputData;
//Node::Node(char* inputData){
//data = inputData;
}
/*
Node::~Node(){
  delete data;
    delete right;
    delete left;
    delete next;
}
*/
void Node::setRight(Node* inputRight){ // set and get right
  right = inputRight;
}
Node* Node::getRight(){
  return right;
}
void Node::setLeft(Node* inputLeft){ // set and get left
  left = inputLeft;
}
Node* Node::getLeft(){
  return left;
}
void Node::setNext(Node* inputNext){ // set and get next
  next = inputNext;
}
Node* Node::getNext(){
  return next;
}

void Node::setData(char* inputData){ // set and get data
  data = inputData;
}

char* Node::getData(){
  return data;
}
char* Node::getAssociativity(){ // set and get associativity
  return associativity;
}
void Node::setAssociativity(char* inputAssociativity){
  associativity = inputAssociativity;
}
int* Node::getPrecedence(){ // set and get precedencre
  return precedence;
}
void Node::setPrecedence(int* inputPrecedence){
  precedence = inputPrecedence;
}
/*
char Node::getData(){
  return data;
}
void Node::setData(char* inputData){
  data = (*inputData);
}
*/
