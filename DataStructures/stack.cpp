#include "stack.h"
#include <iostream>

using namespace std;

Stack::Stack(int size) {
    capacity = size;
    arr = new int[capacity];
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (top == capacity - 1) {
        cout << "Stack Overflow!\n";
        return;
    }
    arr[++top] = x;
    cout << "Pushed " << x << " onto stack\n";
}

void Stack::pop() {
    if (top == -1) {
        cout << "Stack Underflow!\n";
        return;
    }
    cout << "Popped " << arr[top--] << " from stack\n";
}

void Stack::display() {
    if (top == -1) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements: ";
    for (int i = top; i >= 0; i--)
        cout << arr[i] << " ";
    cout << "\n";
}
