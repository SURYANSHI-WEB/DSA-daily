#include <iostream>
#include <cstdlib>
using namespace std;

class Queue {
    int front, rear, size;
    int* queueArr;

public:
    Queue(int size) {
        this->size = size;     
        front = rear = -1;
        queueArr = new int[size];
    }

    bool isEmpty() {
        return front == -1;    
    }

    bool isFull() {
        return rear == size - 1;
    }

    void enqueue(int data) {
        if (isFull()) {
            cout << "Queue Overflow!!!" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queueArr[rear] = data;
        cout << "Data inserted into queue!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!!!" << endl;
            return;
        }

        cout << "Deleted element: " << queueArr[front] << endl;
        front++;

        if (front > rear)
            front = rear = -1;
    }

    void peek() {
        if (isEmpty())
            cout << "Queue is empty!" << endl;
        else
            cout << "Front element: " << queueArr[front] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++)
            cout << queueArr[i] << " ";
        cout << endl;
    }

    ~Queue() {
        delete[] queueArr;
    }
};

int main() {
    int size;
    cout << "Enter size of queue: ";
    cin >> size;

    Queue q(size);

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice, data;
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter data: ";
                cin >> data;
                q.enqueue(data);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                q.display();
                break;
            case 5:
                exit(0);
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
