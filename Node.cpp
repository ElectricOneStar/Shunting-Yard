#include <iostream>
#include <cstring>
#include "Node.h"
using namespace std;
Node::Node(char* inputData){
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
void Node::setRight(Node* inputRight){
  right = inputRight;
}
Node* Node::getRight(){
  return right;
}
void Node::setLeft(Node* inputLeft){
  left = inputLeft;
}
Node* Node::getLeft(){
  return left;
}
void Node::setNext(Node* inputNext){
  next = inputNext;
}
Node* Node::getNext(){
  return next;
}

void Node::setData(char* inputData){
  data = inputData;
}

char* Node::getData(){
  return data;
}
/*
char Node::getData(){
  return data;
}
void Node::setData(char* inputData){
  data = (*inputData);
}
*/
