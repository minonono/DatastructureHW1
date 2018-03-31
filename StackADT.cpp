#include "Stack.h"
#include <iostream>
#include <cstdio>


Stack::Stack() : top(-1){}

void Stack::push(Position val){
    if(this->isFull()){
        std::cout << "Stack is Full!" << std::endl;
        exit(-1);
    }else{
        stack[++top] = val;
    }
}
Position Stack::pop(){
    if(this->isEmpty()){
        std::cout << "Stack is Empty!" << std::endl;
        exit(-1);
    }else{
        return stack[top--];
    }
}
bool Stack::isEmpty(){
    if(top == -1)
        return true;
    else
        return false;
}
bool Stack::isFull(){
    if(top == STACK_SIZE - 1)
        return true;
    else
        return false;
}
Position Stack::peek(){
    return stack[top];
}

void Stack::displayStack(){
    int sp = top;
    while(sp != -1){
        std::cout << '[' << stack[sp].g << ", " <<stack[sp].h << ']'<< std::endl;
        --sp;
    }
}