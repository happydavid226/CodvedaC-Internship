#include <iostream>
#include "stack.h"
#include "queue.h"

using namespace std;

int main() {
    int size;
    cout << "Enter size of stack/queue: ";
    cin >> size;

    Stack stack(size);
    Queue queue(size);

    int choice, value;

    do {
        cout << "\n--- Data Structure Menu ---\n";
        cout << "1. Stack Push\n";
        cout << "2. Stack Pop\n";
        cout << "3. Stack Display\n";
        cout << "4. Queue Enqueue\n";
        cout << "5. Queue Dequeue\n";
        cout << "6. Queue Display\n";
        cout << "0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.display();
                break;
            case 4:
                cout << "Enter value: ";
                cin >> value;
                queue.enqueue(value);
                break;
            case 5:
                queue.dequeue();
                break;
            case 6:
                queue.display();
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}
