#include "queue.h"
#include <iostream>

using namespace std;

Queue::Queue(int size) {
    capacity = size;
    arr = new int[capacity];
    front = 0;
    rear = -1;
}

Queue::~Queue() {
    delete[] arr;
}

void Queue::enqueue(int x) {
    if (rear == capacity - 1) {
        cout << "Queue Overflow!\n";
        return;
    }
    arr[++rear] = x;
    cout << "Enqueued " << x << " into queue\n";
}

void Queue::dequeue() {
    if (front > rear) {
        cout << "Queue Underflow!\n";
        return;
    }
    cout << "Dequeued " << arr[front++] << " from queue\n";
}

void Queue::display() {
    if (front > rear) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements: ";
    for (int i = front; i <= rear; i++)
        cout << arr[i] << " ";
    cout << "\n";
}
