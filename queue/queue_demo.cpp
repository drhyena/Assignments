#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue<int> q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.print_queue();

    q.peek_front();

    q.dequeue();
    q.print_queue();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    q.print_queue();

    q.enqueue(70);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.dequeue();
    q.peek_front();

    return 0;
}
