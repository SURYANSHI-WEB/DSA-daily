#include <iostream>
#include <cstdlib>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty() {
        return front == nullptr;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Data inserted into queue!" << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!!!" << endl;
            return;
        }

        Node* temp = front;
        cout << "Deleted element: " << front->data << endl;

        front = front->next;

        if (front == nullptr)
            rear = nullptr;

        delete temp;
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
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue que;

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice, data, result;
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
                result = que.peek();
                if (result != -1)
                    cout << "Front element: " << result << endl;
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
