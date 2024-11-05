#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

typedef char infotype;

struct Stack {
    infotype info[15];
    int Top;
};

// Fungsi dan Prosedur untuk ADT Stack
void createStack(Stack &S);
bool isEmpty(Stack S);
bool isFull(Stack S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S, int num_to_pop);

#endif