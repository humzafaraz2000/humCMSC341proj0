/*
*File:    proj0.cpp
*Author:  Humza Faraz
*Date:    2/4/2020
*E-mail:  hfaraz1@umbc.edu
*Description:
*Tests rule of three with templated linked lists.
*/

#include <iostream>
#include "stack.h"

using namespace std;

int main(){
  Stack<int> intStack;
  for (int i = 1; i <= 5; i++) {
    intStack.push(i);
  }
  cout << "Test original list." << endl;
  intStack.dump();
  
  cout << "Test copy constructor." << endl;
  Stack<int> copy(intStack);
  copy.dump();
  
  cout << "Test deep copy (copy contructor is popped then original is printed, should be no change)." << endl;
  copy.pop();
  intStack.dump();
  
  cout << "Test assignment operator." << endl;
  Stack<int> assign = intStack;
  assign.dump();
  
  cout << endl << "Edge case tests:" << endl;
  cout << "Tests if copy and assignment work if source stack is empty, nothing should print." << endl;
  Stack<int> newStack;
  Stack<int> copyStack(newStack);
  Stack<int> assignStack = newStack;
  newStack.dump();
  copyStack.dump();
  assignStack.dump();
  
  //test popping from all empty stacks
  cout << endl;
  cout << "Test popping from empty original stack" << endl;
  try {
    newStack.pop();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }
  cout << "Test popping from empty copy contructor stack" << endl;
  try {
    copyStack.pop();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }
  cout << "Test popping from empty assignment operator stack" << endl;
  try {
    assignStack.pop();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }  
  
  //test getting top from empty stack
  cout << endl;
  cout << "Test getting top from empty stack" << endl;
  try {
    newStack.top();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }
  cout << "Test getting top from empty copy contructor stack" << endl;
  try {
    copyStack.pop();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }
  cout << "Test getting top from empty assignment operator stack" << endl;
  try {
    assignStack.pop();
  } catch (exception &e) {
    cout << "Caught exception:\n" << e.what() << endl;
  }  
  
  cout << endl << "Test self-assignment ('no self-assignment!' should be printed)." << endl;
  Stack<int> self = intStack;
  self = self;
}