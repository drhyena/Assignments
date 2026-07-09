#include <iostream>
#include "stack.h"
using namespace std;

Stack::Stack(int s) {
    size = s;
    top = -1;
}

void Stack::push(int value) {
    if (top == size - 1) {
        cout << "Overflow! Stack is full, cannot push " << value << endl;
        return;
    }
    top = top + 1;
    arr[top] = value;
}

void Stack::pop() {
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot pop" << endl;
        return;
    }
    cout << "Popped: " << arr[top] << endl;
    top = top - 1;
}

void Stack::peek() {
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot peek" << endl;
        return;
    }
    cout << "Top element is: " << arr[top] << endl;
}

void Stack::print_stack() {
    if (top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
