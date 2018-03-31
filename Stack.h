#ifndef __STACK_H__
#define __STACK_H__
#include "Position.h"
const int STACK_SIZE = 6*6; // Stacksize < Mazesize

class Stack{
private:
    Position stack[STACK_SIZE]; 
    int top;
public:
    Stack();
    void push(Position val);
    Position pop();
    bool isEmpty();
    bool isFull();
    void displayStack();
    Position peek();
};
#endif