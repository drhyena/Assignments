#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int arr[100];
    int top;
    int size;

public:
    Stack(int s);
    void push(int value);
    void pop();
    void peek();
    void print_stack();
};

#endif
