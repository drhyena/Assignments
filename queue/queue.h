#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int arr[100];
    int front;
    int rear;
    int size;

public:
    Queue(int s);
    void enqueue(int value);
    void dequeue();
    void peek_front();
    void print_queue();
};

#endif
