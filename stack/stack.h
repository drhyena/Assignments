#ifndef STACK_H
#define STACK_H
#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    T arr[100];
    int top;
    int size;

public:
    Stack(int s);
    void push(T value);
    void pop();
    void peek();
    void print_stack();
    Stack<T> operator+(T n);
    Stack<T> operator-();
    
};




template<typename T>
Stack<T>::Stack(int s)
{
    size = s;
    top = -1;
}

template<typename T>
void Stack<T>::push(T value)
{
    if (top == size - 1) {
        cout << "Overflow! Stack is full, cannot push " << value << "\n";
        return;
    }
    top = top + 1;
    arr[top] = value;
}

template<typename T>
void Stack<T>::pop()
{
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot pop\n";
        return;
    }
    cout << "Popped: " << arr[top] << "\n";
    top = top - 1;
}

template<typename T>
void Stack<T>::peek()
{
    if (top == -1) {
        cout << "Underflow! Stack is empty, cannot peek\n";
        return;
    }
    cout << "Top element is: " << arr[top] << "\n";
}

template<typename T>
Stack<T> Stack<T>::operator+(T n)
{
    Stack<T> temp = *this;
    temp.push(n);
    return temp;
}

template<typename T>
Stack<T> Stack<T>::operator-()
{
    Stack<T> temp = *this;
    temp.pop();
    return temp;
}

template<typename T>
void Stack<T>::print_stack()
{
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }

    cout << "Stack: ";
    for (int i = top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

#endif
