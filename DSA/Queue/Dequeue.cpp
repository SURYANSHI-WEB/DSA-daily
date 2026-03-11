#include <iostream>
#include <cstdlib>
using namespace std;

class Node{
    int data;
    Node* next;
};
class Deque {
    Node* front, *rear;
public:
    Deque(): front(nullptr), rear(nullptr) {};
    bool isEmpty() {
        return front == nullptr && rear == nullptr ? true : false;
    }
    void insert_front(int val) {
        Node* newNode = new Node();
        if (newNode == nullptr) {
            cout<<"Queue Overflow!!!";
        } else {
            newNode->next = front;
            front = newNode;
        }
        cout << "Inserted " << val << " at front of deque." << endl;
    }
};
