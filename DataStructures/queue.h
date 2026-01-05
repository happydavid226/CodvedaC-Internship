#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    int* arr;
    int front, rear, capacity;

public:
    Queue(int size);
    ~Queue();

    void enqueue(int x);
    void dequeue();
    void display();
};

#endif
