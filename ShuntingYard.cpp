/*
Shunting Yard by Andrew Thomas 2/14/20 Mr.Galbraith Data structure class. Shunting yard is a code that asks the user for an algorith in infix notation. Then it figures out the postfix notation, prints postfix and infix, and builds the tree. Then it asks the user if they want postfix, infix, or prefix which is gotten by a recursive print from the tree.
 */
#include <cstring> // libraries
#include<iostream>
#include "Node.h"
using namespace std; // functions
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
void createInfix(Node* tree, Node* previous, char* currentData, char* currentState,  int* counterThree, Node* origionalTree);
void createPrefix(Node* tree, int* counterThree, Node* origionalTree);
void createPostfix(Node tree, int* counterThree, Node* origionalTree, Node linearTree);
int main(){
  //char* input = new char[20];
  cout << "Welcome to Shunting Yard. Please enter an mathematical expression in infix notation" << endl;
  char* infix = new char[50]; // initalizations
  Node* prefix = new Node(NULL);
  // char* postfix = new char[50];
  Node* postfix = new Node(NULL);
  Node* realInfix = new Node(NULL);
  char* currentState = new char[50];
  Node* tree = new Node(NULL);
  Node* queue = new Node(NULL);
  Node* stack = new Node(NULL);
  Node* previous = new Node(NULL);
  Node* tail = new Node(NULL);
  //cout << "here2" << endl;
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
  ShuntingYard(infix, postfix, currentState, tokenIndex, counterOne, currentData, counterTwo, listSize, stack, queue, previous, tail); // turns infix to postfix
  //cout << "here this" << endl;
  cout << "Infix: ";
  cout << infix << endl; // prints input infix
  cout << "Postfix: ";
  Print((*postfix).getNext()); // prints created postfix
  createTree(infix, postfix, currentState, tokenIndex, counterOne, currentData, counterTwo, listSize, stack, queue, previous, tail, tree); // with created postfix create the tree
  //cout << "Here that" << endl;
  //Print(postfix);
  char* input = new char[50];
  bool quit;
  quit = false;
  do{
    cout << "The Tree is now build please enter the form you want to see(infix, prefix or postfix,) or if you want to exit the program type quit" << endl; // asks for user input (infix, postfix, prefix)
  cin.get(input, 50);
  cin.clear();
  cin.ignore();
  if(strcmp(input, "infix") == 0){ // infix
    //cout << "infix" << end;
    (*counterThree) = 0;
    (*realInfix).setNext(NULL);
    cout << "Infix: ";
    createInfix(tree, previous, currentData, currentState, counterThree, tree);
    cout << endl;
  }
  if(strcmp(input, "prefix") == 0){ // prefix
    //cout << "infix" << end;
    cout << "Prefix: ";
    (*prefix).setNext(NULL);
    (*counterThree) = 0;
    createPrefix(tree, counterThree, tree);
    cout << endl;
  }
  if(strcmp(input, "postfix") == 0){ // postfix
    //cout << "infix" << end;
    cout << "Postfix: ";
    (*postfix).setNext(NULL);
    createPostfix((*tree), counterThree, tree, (*tree));
    cout << endl;
    (*counterThree) = 0;
  }
  if(strcmp(input, "quit") == 0){ // set quit as true because user wants to quit
    quit = true;
  }
  }
  while(quit == false);
return 0;
}
void ShuntingYard(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail){ // turns infix to postfix notation
  
  //do{
  sizeList(infix, listSize);
  (*listSize) = (*listSize) + 1;
  // cout << "hi" << endl;
  while((*tokenIndex) != (*listSize)){ // when the size of the list matches the size of the infix
  Parce(infix, tokenIndex, counterOne, currentData, counterTwo);
  char* newData = new char[20];
  (*newData) = (*currentData);
  Node* create = new Node(newData); // creates a new node with the parced infix character
    int* precedence = new int;
  char* associativity = new char;
  CheckState(currentState, currentData); // checks the state of token
  if(strcmp(currentState , "Number") == 0){
    Enqueue(queue, create);
  }
  if(strcmp(currentState, "Addition or Subtraction") == 0 || strcmp(currentState, "Power") == 0 || strcmp(currentState, "Division or Multiplication") == 0){ // operator
    if(strcmp(currentState, "Addition or Subtraction") == 0){ // sets the precedence and accociative value 
      //cout << "Addition or Subtraction" << endl;
      (*precedence) = 2;
      (*associativity) = 'L';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);
    }
    if(strcmp(currentState, "Power") == 0){ // sets the precedence and accociative value 
      //cout << "Power" << endl;
          (*precedence) = 4;
      (*associativity) = 'R';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);

    }
    if(strcmp(currentState, "Division or Multiplication") == 0){ // sets the precedence and accociative value 
      //cout << "Division or Multiplication" << endl;
      (*precedence) = 3;
      (*associativity) = 'L';
      (*create).setPrecedence(precedence);
      (*create).setAssociativity(associativity);

    }
    
    while(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getPrecedence()) > (*(*create).getPrecedence()) || CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getPrecedence()) == (*(*create).getPrecedence()) && (*(*create).getAssociativity()) == 'L' && CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) != '('){ // checks if one should pop from stack
      //cout << "Here" << endl;
      //(*previous) = NULL;
      //(*tail) = NULL;
      //if(CheckEmpty(stack) == false){
	previous = NULL;
	Enqueue(queue, Pop(stack, previous, tail)); // pop from stack and enqueue to queue
      //  cout << "here2" << endl;
      }
      //}
    
    //    Push()
    Push(stack, create); // push operator to stack
  }
  if(strcmp(currentState, "Left Paraenthesis") == 0){ // pushes left paraenthesis to stack
    //cout << "Left Paraenthesis" << endl;
    Push(stack, create);
  }
  if(strcmp(currentState, "Right Paraenthesis") == 0){ // right parenthesis
    //cout << "Right Paraenthesis" << endl;
    // cout << ((*Peek(stack, previous, tail)).getData()) << endl;
    while(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) != '('){ // checks if need to pop from stack
      //  cout << ((*Peek(stack, previous, tail)).getData()) << endl;
      Enqueue(queue, Pop(stack, previous, tail)); // pops from stacks and enqueues
    }
    if(CheckEmpty(stack) == false && (*(*Peek(stack, previous, tail)).getData()) == '('){
      Pop(stack, previous, tail);
    }
  }
  currentState[0] = '\0';
  // cout << endl;
  //cout << (*tokenIndex);
  currentData[0] = '\0';
  (*counterOne) = 0;
  (*counterTwo) = 0;
  
  (*tokenIndex)++;
  }
   
   while(CheckEmpty(stack) == false){
     //cout << "here" << endl;
     //Enqueue(queue, Pop(stack, tail));
     Enqueue(queue, Pop(stack, previous, tail)); // when finished pop all from stack to the queue
   }
   BuildPostfix(queue, previous, tail, postfix);
     //return postfix;
}
void Parce(char* infix, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo){ // parces the infix notation
  //cout << strlen(infix) << endl;
  for(int i = 0; i < strlen(infix); i++){
    if(infix[i] != ' '){ // parce
      //cout << "here1" << endl;
      //cout << (*counterTwo) << endl;
      currentData[(*counterTwo)] = infix[i]; // sets the current data char as the parced char
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
}
void sizeList(char* infix, int* listSize){
  for(int i = 0; i < strlen(infix); i++){
      if(infix[i] == ' '){
	(*listSize)++;
  }
}
  (*listSize)++;
}
void CheckState(char* currentState, char* currentData){ // checks the state of the char
  if(currentData[0] == '1' || currentData[0] == '2' || currentData[0] == '3' || currentData[0] == '4' || currentData[0] == '5' || currentData[0] == '6' || currentData[0] == '7' || currentData[0] == '8' || currentData[0] == '9'){
    strcpy(currentState, "Number"); // its a number
  }
  if(currentData[0] == '+' || currentData[0] == '-'){
    strcpy(currentState, "Addition or Subtraction"); // + or -
  }
  if(currentData[0] == '%' || currentData[0] == 'x'){
    strcpy(currentState, "Division or Multiplication"); // % or x
  }
  if(currentData[0] == ')'){
    strcpy(currentState, "Right Paraenthesis"); // right )
  }
  if(currentData[0] == '('){
    strcpy(currentState, "Left Paraenthesis"); // left (
  }
  if(currentData[0] == '^'){ // power
    strcpy(currentState, "Power");
  }
}

void Push(Node* stack, Node* add){ // pushes the node to the stack
  (*GetEnd(stack)).setNext(add);
}
Node* GetEnd(Node* header){ // gets end of data structure
  if((*header).getNext() != NULL){
    GetEnd((*header).getNext());
  }
  else{
    return header;
  }
}
// fix pop and peek
Node* Pop(Node* stack, Node* previous, Node* tail){ // takes from the top of the stack
  //previous = stack;
  if((*stack).getNext() == NULL){
    tail = stack;
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
Node* Peek(Node* stack, Node* previous, Node* tail){ // looks at the top of the stack
    //previous = stack;
    if((*stack).getNext() == NULL){
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

void Print(Node* header){ // prints the list
  cout << (*header).getData() << " ";
  if((*header).getNext() != NULL){
    Print((*header).getNext());
  }
  else{
    cout << endl;
    return;
  }
}
void Enqueue(Node* queue, Node* add){ // add the node to the beginning of the queue
  if((*queue).getNext() == NULL){
    (*queue).setNext(add);
    return;
  }
  (*add).setNext((*queue).getNext());
  (*queue).setNext(add);
}
Node* Dequeue(Node* queue, Node* previous, Node* tail){ // takes from end of queue
    if((*queue).getNext() == NULL){
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
Node* takefromBeg(Node* header, Node* get){ // can be used for debugging
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
Node* checkfromBeg(Node* header, Node* get){ // can be used for debugging
  if((*header).getNext() != NULL){
    get = (*header).getNext();
    return get;
  }
}

bool CheckEmpty(Node* header){ // checks if the list is empty
  if((*header).getNext() == NULL){
    return true;
  }
  else{
    return false;
      }
}
//bool CheckOperator(){

//}
void PrintQueue(Node* queue, Node* previous, Node* tail){ // prints the queue for debuging
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
void createTree(char* infix, Node* postfix, char* currentState, int* tokenIndex, int* counterOne, char* currentData, int* counterTwo, int* listSize, Node* stack, Node* queue, Node* previous, Node* tail, Node* tree){ // creates the tree using the postfix from shunting yard
  //cout << "BUILD THE TREE" << endl;
   // Node* getTwo = new Node;
  while(CheckEmpty(postfix) == false){ // while the postfix is not empty
     //Print((*postfix).getNext());
     (*currentData) =  (*(*checkfromBeg(postfix, previous)).getData());
   CheckState(currentState, currentData);
   if(strcmp(currentState , "Number") == 0){ // if token is number
    // cout << "Number" << endl;
     Push(tree ,takefromBeg(postfix, previous)); // push to tree
  }
   else{ // if operator pop 2 from tree and put it in the left and right of the operator
    //cout << "Operator" << endl;
    Node* Operator = new Node(NULL);
    (*Operator) = (*takefromBeg(postfix, previous));
    if(CheckEmpty(tree) == false){
    (*Operator).setRight(Pop(tree, previous, tail));
    }
    if(CheckEmpty(tree) == false){
    (*Operator).setLeft(Pop(tree, previous, tail));
    }
    Push(tree, Operator);
    
  }
   }
  cout << "Tree: ";
  Print((*tree).getNext());
  // Print((*postfix).getNext());
}
void createInfix(Node* tree, Node* previous, char* currentData, char* currentState, int* counterThree, Node* origionalTree){ // creates the infix notation from the tree
  // cout << "infix" << endl;
  //cout << "here" << endl;
  if((*counterThree) == 0){ // gets the first node
    //cout << "Here" << endl;
    //cout << "here1" << endl;
    (*counterThree)++;
   createInfix((*tree).getNext(), previous, currentData, currentState, counterThree, origionalTree);
    }
  //cout << "here2" << endl;
   if(CheckEmpty(origionalTree) == false){
     if((*tree).getLeft() != NULL){ // left
	 //cout << "here4" << endl;
	 createInfix((*tree).getLeft(), previous, currentData, currentState, counterThree, origionalTree);
       //cout << "here3" << endl;
       }
     if((*tree).getData() != NULL){ // currrent
	 cout << (*(*tree).getData()) << " ";
       // cout << "here5" << endl;
       }
     if((*tree).getRight() != NULL){ // right
	 //cout << "here6" << endl;
	 createInfix((*tree).getRight(), previous, currentData, currentState, counterThree, origionalTree);
       
       }
  }
  //return;
  //  cout << "here9" << endl;
}
void createPrefix(Node* tree, int* counterThree, Node* origionalTree){ // creates the prefix using the tree
  //  cout << "Prefix" << endl;
  if((*counterThree) == 0){
    //cout << "Here" << endl;
    (*counterThree)++;
    createPrefix((*tree).getNext(), counterThree, origionalTree);
  }
  if(CheckEmpty(origionalTree) == false){ // gets the first node
    if((*tree).getData() != NULL){ // current
	 cout << (*(*tree).getData()) << " ";
       // cout << "here5" << endl;
       }
    if((*tree).getLeft() != NULL){ // left
	createPrefix((*tree).getLeft(), counterThree, origionalTree);
      }
      if((*tree).getRight() != NULL){ // right
	createPrefix((*tree).getRight(), counterThree, origionalTree);
      }
  }

}
void createPostfix(Node tree, int* counterThree, Node* origionalTree, Node linearTree){ // creates postfix from the tree using recursive print
  // cout << "Postfix" << endl;
  if((*counterThree) == 0){ // gets the first node
    //cout << "Here" << endl;
    (*counterThree)++;
    createPostfix((*tree.getNext()), counterThree, origionalTree, (*linearTree.getNext()));
    // (*counterThree)++;
  }
  
  //createPostfix((*tree).getNext(), postfix);
  if(CheckEmpty(origionalTree) == false){ 
    if(tree.getLeft() != NULL){ // left
	//	cout << "here1" << endl;
	createPostfix((*tree.getLeft()), counterThree, origionalTree, linearTree);
      }

    if(tree.getRight() != NULL){ // right
	//cout << "here2" << endl;
	createPostfix((*tree.getRight()), counterThree, origionalTree, linearTree);
      }
    if(tree.getData() != NULL){ // current
	//	cout << "here1" << endl;
      cout << (*tree.getData()) << " ";
      }
    }
}
