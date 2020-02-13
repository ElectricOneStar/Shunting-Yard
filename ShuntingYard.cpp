#include <cstring>
#include<iostream>
#include "Node.h"
using namespace std;
void ShuntingYard(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail);
void CheckState(char* currentState, char* currentData);
void Parce(char* infix, int* token, int* counterOne, char* currentData, int* counterTwo);
void sizeList(char* infix, int* listSize);
void Push(Node* stack, Node* add);
Node* GetEnd(Node* header);
Node* Pop(Node* stack, Node* previous, Node* tail);
void Print(Node* header);
Node* Peek(Node* stack, Node* previous, Node* tail);
Node* Dequeue(Node* queue, Node* previous, Node* tail);
void Enqueue(Node* queue, Node* add);
bool CheckEmpty(Node* header);
void PrintQueue(Node* queue, Node* previous, Node* tail);
void BuildPostfix(Node* queue, Node* previous, Node* tail, Node* postfix);
void createTree(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail, Node* tree);
Node* takefromBeg(Node* header, Node* get);
Node* checkfromBeg(Node* header, Node* get);
//void createTree(Node* postfix, Node* tree);
void createInfix(Node* tree, Node* realInfix, Node* previous, char* currentData, char* currentState);
void createPrefix(Node* tree, Node* prefix);
void createPostfix(Node* tree, Node* postfix, int* counterThree, Node* origionalTree);
int main(){
  //char* input = new char[20];
  cout << "Welcome to Shunting Yard Please enter an mathematical expression in infix notation" << endl;
  char* infix = new char[50];
  Node* prefix = new Node(NULL);
  // char* postfix = new char[50];
  Node* postfix = new Node(NULL);
  Node* realInfix = new Node(NULL);
  char* currentState = new char[50];
  /*
  Node* tree(NULL);
  Node* queue(NULL);
  Node* stack(NULL);
  Node* tail(NULL);
  */
  // int* precedence = new int;
  //char* associativity = new char;
  cout << "here" << endl;
  Node* tree = new Node(NULL);
  Node* queue = new Node(NULL);
  Node* stack = new Node(NULL);
  Node* previous = new Node(NULL);
  Node* tail = new Node(NULL);
  cout << "here2" << endl;
  //char* currentState = new char[20];
  int* tokenIndex = new int;
  (*tokenIndex) = 1;
  int* counterOne = new int;
  (*counterOne) = 0;
  int* counterTwo = new int;
  (*counterTwo) = 0;
  int* counterThree = new int;
  (*counterThree) = 0;
  int* listSize = new int;
  (*listSize) = 0;
  char* currentData = new char[50];
  //bool* Empty = new bool;
  //Node* tree(NULL);
  //Node* tree = new Node();
  cin.get(infix, 50);
  cin.clear();
  cin.ignore();
  ShuntingYard(infix, postfix, currentState, tokenIndex, counterOne, currentData, counterTwo, listSize, stack, queue, previous, tail);
  //cout << "here this" << endl;
  cout << "Infix: ";
  cout << infix << endl;
  cout << "Postfix: ";
  Print((*postfix).getNext());
  createTree(infix, postfix, currentState, tokenIndex, counterOne, currentData, counterTwo, listSize, stack, queue, previous, tail, tree);
  //cout << "Here that" << endl;
  //Print(postfix);
  char* input = new char[50];
  bool quit;
  quit = false;
  do{
  cout << "The Tree is now build please enter the form you want to see(infix, prefix or postfix,) or if you want to exit the program type quit" << endl;
  cin.get(input, 50);
  cin.clear();
  cin.ignore();
  if(strcmp(input, "infix") == 0){
    //cout << "infix" << end;
    (*realInfix).setNext(NULL);
    createInfix(tree, realInfix, previous, currentData, currentState);
  }
  if(strcmp(input, "prefix") == 0){
    //cout << "infix" << end;
    (*prefix).setNext(NULL);
    createPrefix(tree, prefix);
  }
  if(strcmp(input, "postfix") == 0){
    //cout << "infix" << end;
    cout << "Postfix: ";
    (*postfix).setNext(NULL);
    createPostfix(tree, postfix, counterThree, tree);
    cout << endl;
  }
  if(strcmp(input, "quit") == 0){
    quit = true;
  }
  }
  while(quit == false);
return 0;
}
void ShuntingYard(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail){
  
  //do{
  sizeList(infix, listSize);
  (*listSize) = (*listSize) + 1;
  // cout << "hi" << endl;
   while((*tokenIndex) != (*listSize)){
  Parce(infix, tokenIndex, counterOne, currentData, counterTwo);
  //cout << "a" << endl;
  //cout << strlen(currentData) << endl;
  //cout << "here" << endl;
  for(int i = 0; i < strlen(currentData); i++){
   cout << currentData[i];
  }
  //  cout << "here2 " << endl;
  char* newData = new char[20];
  (*newData) = (*currentData);
    Node* create = new Node(newData);
    int* precedence = new int;
  char* associativity = new char;
  // cout << (*create).getData()[0];
  //  Node* create(NULL); // watch identity problem
  //(*create).setData(currentData);
 // cout << (*create).getData()[0];
  CheckState(currentState, currentData);
  if(strcmp(currentState , "Number") == 0){
    cout << "Number" << endl;
    //(*queue).setData(currentData);
    //cout << (*create).getData()[0];
    //Push(queue, create);
    Enqueue(queue, create);
    //cout << (*(*queue).getNext()).getData()[0];
    // Print((*queue).getNext());
    // cout << "here" << endl;
  }
  if(strcmp(currentState, "Addition or Subtraction") == 0 || strcmp(currentState, "Power") == 0 || strcmp(currentState, "Division or Multiplication") == 0){
    if(strcmp(currentState, "Addition or Subtraction") == 0){
      cout << "Addition or Subtraction" << endl;
      (*precedence) = 2;
      (*associativity) = 'L';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);
    }
    if(strcmp(currentState, "Power") == 0){
    cout << "Power" << endl;
          (*precedence) = 4;
      (*associativity) = 'R';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);

    }
    if(strcmp(currentState, "Division or Multiplication") == 0){
      cout << "Division or Multiplication" << endl;
      (*precedence) = 3;
      (*associativity) = 'L';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);

    }
    cout << (*(*create).getPrecedence()) << endl;
    cout << (*(*create).getAssociativity()) << endl;
    cout << "data" << endl;
    cout << (*(*Peek(stack, previous, tail)).getPrecedence()) << endl;
    cout << (*(*create).getPrecedence()) << endl;
    
    while(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getPrecedence()) > (*(*create).getPrecedence()) || CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getPrecedence()) == (*(*create).getPrecedence()) && (*(*create).getAssociativity()) == 'L' && CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) != '('){
      cout << "Here" << endl;
      //(*previous) = NULL;
      //(*tail) = NULL;
      //if(CheckEmpty(stack) == false){
	previous = NULL;
	Enqueue(queue, Pop(stack, previous, tail));
      //  cout << "here2" << endl;
      }
      //}
    
    //    Push()
     Push(stack, create);
  }
  if(strcmp(currentState, "Left Paraenthesis") == 0){
    cout << "Left Paraenthesis" << endl;
    Push(stack, create);
  }
  if(strcmp(currentState, "Right Paraenthesis") == 0){
    cout << "Right Paraenthesis" << endl;
    // cout << ((*Peek(stack, previous, tail)).getData()) << endl;
    while(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) != '('){
      cout << ((*Peek(stack, previous, tail)).getData()) << endl;
      Enqueue(queue, Pop(stack, previous, tail));
    }
    if(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) == '('){
      Pop(stack, previous, tail);
    }
  }
  currentState[0] = '\0';
  cout << endl;
  //cout << (*tokenIndex);
  currentData[0] = '\0';
  (*counterOne) = 0;
  (*counterTwo) = 0;
  
  (*tokenIndex)++;
  //  cout << (*create).getData()[0] << endl;
    //  Print(create);
  // cout << (*create).getData()[0];
  //Print((*queue).getNext());
  }
   
   while(CheckEmpty(stack) == false){
     //cout << "here" << endl;
     //Enqueue(queue, Pop(stack, tail));
     Enqueue(queue, Pop(stack, previous, tail));
   }
   /*
   if(CheckEmpty(queue) == false){
     //   Print((*queue).getNext());
     // PrintQueue((*queue).getNext(), previous, tail);
     PrintQueue(queue, previous, tail);
     
   }
   else{
     cout << "Queue is Empty" << endl;
   }

   if(CheckEmpty(stack) == false){
  Print((*stack).getNext());
   }
   else{
     cout << "Stack is Empty" << endl;
   }
   */
  // Print(create)
  // return postfix
  //tokenIndex++;
  //(*counterOne) = 0;
  //currentData = NULL;
  //}
  //while((*tokenIndex) != 3);
   BuildPostfix(queue, previous, tail, postfix);
     //return postfix;
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
  if(currentData[0] == '+' || currentData[0] == '-'){
    strcpy(currentState, "Addition or Subtraction");
  }
  if(currentData[0] == '%' || currentData[0] == '*'){
    strcpy(currentState, "Division or Multiplication");
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
// fix pop and peek
Node* Pop(Node* stack, Node* previous, Node* tail){ // ??
  //previous = stack;
  if((*stack).getNext() == NULL){
    //Node* tempOne = new Node(NULL);
    //(*tempOne) = (*(*stack).getNext());
    //tail = (*stack).getNext();
    //  if(previous != NULL){
    tail = stack;
    //(*tail) = (*stack);
    // if(previous != NULL){
    //cout << "Here1" << endl;
    (*previous).setNext(NULL);
    //}
    return tail;
    //return tempOne;
  
    // tail = stack
  }  
   else{
     //cout << "Here2" << endl;
     previous = stack;
     //(*previous) = (*stack);
      Pop((*stack).getNext(), previous, tail);
    }
 
}
  Node* Peek(Node* stack, Node* previous, Node* tail){
    //previous = stack;
    if((*stack).getNext() == NULL){
    //Node* tempOne = new Node(NULL);
    //(*tempOne) = (*(*stack).getNext());
    //tail = (*stack).getNext();
    //  if(previous != NULL){
      tail = stack;
    //  (*previous).setNext(NULL);
    return tail;
    //return tempOne;
  
    // tail = stack
  }
    else{
      //previous = stack;
      Peek((*stack).getNext(), previous, tail);
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
void Enqueue(Node* queue, Node* add){ // ??
  if((*queue).getNext() == NULL){
    (*queue).setNext(add);
    return;
  }
  (*add).setNext((*queue).getNext());
  (*queue).setNext(add);
}
Node* Dequeue(Node* queue, Node* previous, Node* tail){ // fix
    if((*queue).getNext() == NULL){
    //Node* tempOne = new Node(NULL);
    //(*tempOne) = (*(*stack).getNext());
    //tail = (*stack).getNext();
    //  if(previous != NULL){
    tail = queue;
    // if(previous != NULL){
    //cout << "Here1" << endl;
    (*previous).setNext(NULL);
    //}
    return tail;
    //return tempOne;
  
    // tail = stack
  }  
   else{
     //cout << "Here2" << endl;
     previous = queue;
      Dequeue((*queue).getNext(), previous, tail);
    }
}
Node* takefromBeg(Node* header, Node* get){
  if((*header).getNext() != NULL){
    get = (*header).getNext();
    if((*(*header).getNext()).getNext() != NULL){
      (*header).setNext((*(*header).getNext()).getNext());
      (*get).setNext(NULL);
    }
    else{
      (*header).setNext(NULL);
    }
    return get;
  }
}
Node* checkfromBeg(Node* header, Node* get){
  if((*header).getNext() != NULL){
    get = (*header).getNext();
    /*
    if((*(*header).getNext()).getNext() != NULL){
      (*header).setNext((*(*header).getNext()).getNext());
    }
    else{
      (*header).setNext(NULL);
    }
    */
    return get;
  }
}

bool CheckEmpty(Node* header){
  if((*header).getNext() == NULL){
    return true;
  }
  else{
    return false;
      }
}
//bool CheckOperator(){

//}
void PrintQueue(Node* queue, Node* previous, Node* tail){
  while(CheckEmpty(queue) == false){
    cout << (*(*Dequeue( queue, previous, tail)).getData()) << " ";
  }
  cout << endl;

}
void BuildPostfix(Node* queue, Node* previous, Node* tail, Node* postfix){
  while(CheckEmpty(queue) == false){
    (*GetEnd(postfix)).setNext(Dequeue(queue, previous, tail));
 }
  // cout << endl;

}
void createTree(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail, Node* tree){
   cout << "BUILD THE TREE" << endl;
   // Node* getTwo = new Node;
   while(CheckEmpty(postfix) == false){
     //Print((*postfix).getNext());
     (*currentData) =  (*(*checkfromBeg(postfix, previous)).getData());
   CheckState(currentState, currentData);
  if(strcmp(currentState , "Number") == 0){
    cout << "Number" << endl;
    Push(tree ,takefromBeg(postfix, previous));
  }
  else{
    cout << "Operator" << endl;
    Node* Operator = new Node(NULL);
    (*Operator) = (*takefromBeg(postfix, previous));
    //    Node* Right = new Node(NULL);
    //(*Right)  (*Pop(tree, previous, tail));
    //Right = Pop(tree, previous, tail);
    // cout << (*(*Right).getData()) << endl;
    if(CheckEmpty(tree) == false){
    (*Operator).setRight(Pop(tree, previous, tail));
    }
    //Node* Left = new Node(NULL);
    // (*Left) = (*Pop(tree, previous, tail));
    //cout << (*(*Left).getData()) << endl;
    //Left = Pop(tree, previous, tail);
    if(CheckEmpty(tree) == false){
    (*Operator).setLeft(Pop(tree, previous, tail));
    }
    Push(tree, Operator);
    cout << "here" << endl;
    // both tests have worked
    // cout << "Right: " << (*(*(*Operator).getRight()).getData()) << endl;
    //cout << "Left: " << (*(*(*Operator).getLeft()).getData()) << endl;
    
    /*
cout << "Right Then Left: " << (*(*(*(*(*tree).getNext()).getRight()).getLeft()).getData()) << endl;
    cout << "Right Then Right: " << (*(*(*(*(*tree).getNext()).getRight()).getRight()).getData()) << endl;
    */
    
  }
   }
   //}
   // cout << "Right Then Left: " << (*(*(*(*(*tree).getNext()).getRight()).getLeft()).getData()) << endl;
   //cout << "Right Then Right: " << (*(*(*(*(*tree).getNext()).getRight()).getRight()).getData()) << endl;
  cout << "Tree: ";
  Print((*tree).getNext());
  // Print((*postfix).getNext());
}
void createInfix(Node* tree, Node* realInfix, Node* previous, char* currentData, char* currentState){
  // cout << "infix" << endl;
  if(CheckEmpty(tree) == false){
   (*currentData) =  (*(*checkfromBeg(tree, previous)).getData());
   CheckState(currentState, currentData);
   if(strcmp(currentState, "Addition or Subtraction") == 0 || strcmp(currentState, "Power") == 0 || strcmp(currentState, "Division or Multiplication") == 0){
     cout << "( ";
   }
   createInfix((*checkfromBeg(tree, previous)).getLeft(), realInfix, previous, currentData, currentState);
   Print(checkfromBeg(tree, previous));
   createInfix((*checkfromBeg(tree, previous)).getRight(), realInfix, previous, currentData, currentState);
   if(strcmp(currentState, "Addition or Subtraction") == 0 || strcmp(currentState, "Power") == 0 || strcmp(currentState, "Division or Multiplication") == 0){
     cout << ") ";
   }
  }
}
void createPrefix(Node* tree, Node* prefix){
  cout << "Prefix" << endl;
}
void createPostfix(Node* tree, Node* postfix, int* counterThree, Node* origionalTree){
  // cout << "Postfix" << endl;
  if((*counterThree) == 0){
    //cout << "Here" << endl;
    (*counterThree)++;
    createPostfix((*tree).getNext(), postfix, counterThree, origionalTree);
    // (*counterThree)++;
  }
  //createPostfix((*tree).getNext(), postfix);
    if(CheckEmpty(origionalTree) == false){
      if((*tree).getLeft() != NULL){
	//	cout << "here1" << endl;
	createPostfix((*tree).getLeft(), postfix, counterThree, origionalTree);
      }

      if((*tree).getRight() != NULL){
	//cout << "here2" << endl;
	createPostfix((*tree).getRight(), postfix, counterThree, origionalTree);
      }
      if((*tree).getData() != NULL){
	//	cout << "here1" << endl;
      cout << (*(*tree).getData()) << " ";
      }
}
    //cout << endl;
}
