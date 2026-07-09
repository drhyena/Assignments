#include <iostream>
#include "stack.h"
using namespace std;

int main() {
    Stack s(5);

    s.push(10);
    s.push(20);
    s.push(30);
    s.print_stack();

    s.peek();

    s.pop();
    s.print_stack();

    s.push(40);
    s.push(50);
    s.push(60);
    s.print_stack();

    s.push(70);

    s.pop();
    s.pop();
    s.pop();
    s.pop();
    s.pop();

    s.pop();
    s.peek();

    return 0;
}
