#include <iostream>
#include "queue.h"
using namespace std;

Queue::Queue(int s) {
    size = s;
    front = -1;
    rear = -1;
}

void Queue::enqueue(int value) {
    if (rear == size - 1) {
        cout << "Overflow! Queue is full, cannot enqueue " << value << "\n";
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    arr[rear] = value;
}

void Queue::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Underflow! Queue is empty, cannot dequeue" << "\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << "\n";
    front = front + 1;
}

void Queue::peek_front() {
    if (front == -1 || front > rear) {
        cout << "Underflow! Queue is empty, cannot peek" << "\n";
        return;
    }
    cout << "Front element is: " << arr[front] << "\n";
}

void Queue::print_queue() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty" << "\n";
        return;
    }
    cout << "Queue: ";
    for (int i = front; i <= rear; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}
