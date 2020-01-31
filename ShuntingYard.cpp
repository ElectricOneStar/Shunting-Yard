#include <cstring>
#include<iostream>
#include "Node.h"
using namespace std;
char* ShuntingYard(char* infix, char* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* tail);
void CheckState(char* currentState, char* currentData);
void Parce(char* infix, int* token, int* counterOne, char* currentData, int* counterTwo);
void sizeList(char* infix, int* listSize);
void Push(Node* stack, Node* add);
Node* GetEnd(Node* header);
Node* Pop(Node* stack, Node* tail);
void Print(Node* header);
Node* Dequeue(Node* queue, Node* tail);

int main(){
  //char* input = new char[20];
  cout << "Welcome to Shunting Yard Please enter an mathematical expression in infix notation" << endl;
  char* infix = new char[20];
  char* prefix = new char[20];
  char* postfix = new char[20];
  char* currentState = new char[20];
  /*
  Node* tree(NULL);
  Node* queue(NULL);
  Node* stack(NULL);
  Node* tail(NULL);
  */
  cout << "here" << endl;
  Node* tree = new Node(NULL);
  Node* queue = new Node(NULL);
  Node* stack = new Node(NULL);
  Node* tail = new Node(NULL);
  cout << "here2" << endl;
  //char* currentState = new char[20];
  int* tokenIndex = new int;
  (*tokenIndex) = 1;
  int* counterOne = new int;
  (*counterOne) = 0;
  int*counterTwo = new int;
  (*counterTwo) = 0;
  int* listSize = new int;
  (*listSize) = 0;
  char* currentData = new char[20];
  
  //Node* tree(NULL);
  //Node* tree = new Node();
  cin.get(infix, 20);
  
  postfix = ShuntingYard(infix, postfix, currentState, tokenIndex, counterOne, currentData, counterTwo, listSize, stack, queue, tail);
return 0;
}
char* ShuntingYard(char* infix, char* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* tail){
  
  //do{
  sizeList(infix, listSize);
  (*listSize) = (*listSize) + 1;
  // cout << "hi" << endl;
  do{
  Parce(infix, tokenIndex, counterOne, currentData, counterTwo);
  //cout << "a" << endl;
  //cout << strlen(currentData) << endl;
  //cout << "here" << endl;
  for(int i = 0; i < strlen(currentData); i++){
   cout << currentData[i];
  }
  //  cout << "here2 " << endl;
  Node* create = new Node(currentData);
  // cout << (*create).getData()[0];
  //  Node* create(NULL); // watch identity problem
  //(*create).setData(currentData);
 // cout << (*create).getData()[0];
  CheckState(currentState, currentData);
  if(strcmp(currentState , "Number") == 0){
    cout << "Number" << endl;
    //(*queue).setData(currentData);
    //cout << (*create).getData()[0];
    Push(queue, create);
    //cout << (*(*queue).getNext()).getData()[0];
    // Print((*queue).getNext());
    // cout << "here" << endl;
  }
  if(strcmp(currentState, "Basic Operation") == 0){
    cout << "Basic Operation" << endl;
  }
  if(strcmp(currentState, "Left Paraenthesis") == 0){
    cout << "Left Paraenthesis" << endl;
  }
  if(strcmp(currentState, "Right Paraenthesis") == 0){
    cout << "Right Paraenthesis" << endl;
  }
  if(strcmp(currentState, "Power") == 0){
    cout << "Power" << endl;
  }
  currentState[0] = '\0';
  cout << endl;
  //cout << (*tokenIndex);
  //currentData[0] = '\0';
  (*counterOne) = 0;
  (*counterTwo) = 0;
  
  (*tokenIndex)++;
  //  cout << (*create).getData()[0] << endl;
    //  Print(create);
  // cout << (*create).getData()[0];
  //Print((*queue).getNext());
  }
  while((*tokenIndex) != (*listSize));
  Print((*queue).getNext());
  // Print(create)
  // return postfix
  //tokenIndex++;
  //(*counterOne) = 0;
  //currentData = NULL;
  //}
  //while((*tokenIndex) != 3);
  return postfix;
}
void Parce(char* infix, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo){
  //cout << strlen(infix) << endl;
  for(int i = 0; i < strlen(infix); i++){
    if(infix[i] != ' '){
      //cout << "here1" << endl;
      //cout << (*counterTwo) << endl;
      currentData[(*counterTwo)] = infix[i];
      currentData[(*counterTwo)+1] = '\0';
      (*counterTwo)++;
      //cout << "here" << endl;
      //cout << "Here z" << endl;
    if(infix[i+1] == ' '){
      //cout << "here2" << endl;
      (*counterTwo) = 0;
      (*counterOne)++;
      if((*counterOne) == (*tokenIndex)){
	//cout << "here3" << endl;
	return;
      }
      //cout << "here4" << endl;
      currentData[0] = '\0';
      //  cout << "here5" << endl;
    }
    }
  }
  //cout << "here not" <<endl;
  //cout << (*counterOne) << endl;
  // cout << (*tokenIndex) << endl;
}
void sizeList(char* infix, int* listSize){
  for(int i = 0; i < strlen(infix); i++){
      if(infix[i] == ' '){
	(*listSize)++;
  }
}
  (*listSize)++;
}
void CheckState(char* currentState, char* currentData){
  if(currentData[0] == '1' || currentData[0] == '2' || currentData[0] == '3' || currentData[0] == '4' || currentData[0] == '5' || currentData[0] == '6' || currentData[0] == '7' || currentData[0] == '8' || currentData[0] == '9'){
    strcpy(currentState, "Number");
  }
  if(currentData[0] == '+' || currentData[0] == '-' || currentData[0] == '%' || currentData[0] == '*'){
    strcpy(currentState, "Basic Operation");
  }
  if(currentData[0] == ')'){
    strcpy(currentState, "Right Paraenthesis");
  }
  if(currentData[0] == '('){
    strcpy(currentState, "Left Paraenthesis");
  }
  if(currentData[0] == '^'){
    strcpy(currentState, "Power");
  }
}

void Push(Node* stack, Node* add){
  //cout << "here1" << endl;
  //cout << (*add).getData()[0];
  //cout << "here2" << endl;
  (*GetEnd(stack)).setNext(add);
}
Node* GetEnd(Node* header){
  if((*header).getNext() != NULL){
    GetEnd((*header).getNext());
  }
  else{
    return header;
  }
}

Node* Pop(Node* stack, Node* tail){
  if((*(*stack).getNext()).getNext() == NULL){
    tail = (*stack).getNext();
    (*stack).setNext(NULL);
    return tail;
  }
    
}
void Print(Node* header){
  cout << (*header).getData() << " ";
  if((*header).getNext() != NULL){
    Print((*header).getNext());
  }
  else{
    cout << endl;
    return;
  }
}
void Enqueue(Node* queue, Node* add){
  
}
Node* Dequeue(Node* queue, Node* tail){
  if((*(*queue).getNext()).getNext() == NULL){
    tail = (*queue).getNext();
    (*queue).setNext(NULL);
    return tail;
  }

}

