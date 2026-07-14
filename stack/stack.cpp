#include <iostream>
#include "stack.h"
using namespace std;


Stack::Stack(T s) {
    size = s;
    top = -1;
}

void Stack::push(T value) {
    if (top == size - 1) {
        cout << "Overflow! Stack is full, cannot push " << value << "\n";
        return;
    }
    top = top + 1;
    arr[top] = value;
}

void Stack::pop() {
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot pop" << "\n";
        return;
    }
    cout << "Popped: " << arr[top] << "\n";
    top = top - 1;
}

void Stack::peek() {
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot peek" << "\n";
        return;
    }
    cout << "Top element is: " << arr[top] << "\n";
}

Stack Stack::operator+(T n) 
    {	
    	Stack temp = *this;
    	temp.push(n);
    	return temp;
        
    }
    
Stack Stack::operator-(T n) 
    {	
    	Stack temp = *this;
    	temp.pop(n);
    	return temp;
        
    }


void Stack::print_stack() {
    if (top == -1) {
        cout << "Stack is empty" << "\n";
        return;
    }
    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
