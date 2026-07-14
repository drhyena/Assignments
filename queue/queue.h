#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
using namespace std;

const int MAXN = 100;

template <typename T = int>
class Queue {
private:
    int size;
    int front;
    int rear;
    T arr[MAXN];

public:
    Queue(int s = MAXN);

    void enqueue(T value);
    void dequeue();
    void peek_front();
    void print_queue();

    Queue<T> operator+(const Queue<T>& other) const;
    Queue<T> operator-(const Queue<T>& other) const;
};

template <typename T>
Queue<T>::Queue(int s) {
    size = (s > MAXN) ? MAXN : s;
    front = -1;
    rear = -1;
}

template <typename T>
void Queue<T>::enqueue(T value) {
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

template <typename T>
void Queue<T>::dequeue() {
    if (front == -1 || front > rear) {
        cout << "Underflow! Queue is empty, cannot dequeue" << "\n";
        return;
    }
    cout << "Dequeued: " << arr[front] << "\n";
    front = front + 1;
}

template <typename T>
void Queue<T>::peek_front() {
    if (front == -1 || front > rear) {
        cout << "Underflow! Queue is empty, cannot peek" << "\n";
        return;
    }
    cout << "Front element is: " << arr[front] << "\n";
}

template <typename T>
void Queue<T>::print_queue() {
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

template <typename T>
Queue<T> Queue<T>::operator+(const Queue<T>& other) const {
    int new_size = size + other.size;
    Queue<T> result(new_size);

    if (front != -1) {
        for (int i = front; i <= rear; i++) {
            result.enqueue(arr[i]);
        }
    }
    if (other.front != -1) {
        for (int i = other.front; i <= other.rear; i++) {
            result.enqueue(other.arr[i]);
        }
    }

    return result;
}

template <typename T>
Queue<T> Queue<T>::operator-(const Queue<T>& other) const {
    Queue<T> result(size);

    if (front == -1) {
        return result;
    }

    for (int i = front; i <= rear; i++) {
        bool found = false;
        if (other.front != -1) {
            for (int j = other.front; j <= other.rear; j++) {
                if (other.arr[j] == arr[i]) {
                    found = true;
                    break;
                }
            }
        }
        if (!found) {
            result.enqueue(arr[i]);
        }
    }

    return result;
}

#endif