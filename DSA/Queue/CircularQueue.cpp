#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CircularQueue {
private:
    Node* front;
    Node* rear;

public:
    CircularQueue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (isEmpty()) {
            front = rear = newNode;
            rear->next = front;   // circular link
        } else {
            rear->next = newNode;
            rear = newNode;
            rear->next = front;   // maintain circular link
        }

        cout << "Data inserted into circular queue!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!!!" << endl;
            return;
        }

        if (front == rear) {   // single node
            cout << "Deleted element: " << front->data << endl;
            delete front;
            front = rear = nullptr;
        } else {
            Node* temp = front;
            cout << "Deleted element: " << temp->data << endl;
            front = front->next;
            rear->next = front;
            delete temp;
        }
    }

    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return front->data;
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Queue elements: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != front);
        cout << endl;
    }
};

int main() {
    CircularQueue que;
    int choice, data;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter data: ";
            cin >> data;
            que.enqueue(data);
            break;
        case 2:
            que.dequeue();
            break;
        case 3:
            data = que.peek();
            if (data != -1)
                cout << "Front element: " << data << endl;
            break;
        case 4:
            que.display();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
