#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularSinglyLinkedList {
    Node* head;
    Node* tail;

public:
    CircularSinglyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at Beginning
    void InsertInBeg(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        cout << "Node Inserted In Beginning!" << endl;
    }

    // Insert at End
    void InsertInEnd(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            newNode->next = head;
        } else {
            tail->next = newNode;
            newNode->next = head;
            tail = newNode;
        }
        cout << "Node Inserted In End!" << endl;
    }

    // Insert at Any Position
    void InsertAtAnyPosition(int val, int pos) {
        if (pos <= 0) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if (pos == 1) {
            InsertInBeg(val);
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        if (temp->next == head && pos > 2) {
            cout << "Position not found!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if (temp == tail)
            tail = newNode;

        cout << "Node Inserted!" << endl;
    }

    // Display
    void Display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);

        cout << endl;
    }

    // Delete from Beginning
    void DeleteFromBeg() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            head = head->next;
            tail->next = head;
            delete temp;
        }
        cout << "Node Deleted From Beginning!" << endl;
    }

    // Delete from End
    void DeleteFromEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }

        if (head == tail) {
            delete head;
            head = tail = nullptr;
        } else {
            Node* temp = head;
            while (temp->next != tail)
                temp = temp->next;

            temp->next = head;
            delete tail;
            tail = temp;
        }
        cout << "Node Deleted From End!" << endl;
    }

    // Delete from Any Position
    void DeleteNodeFromAnyPosition(int pos) {
        if (!head || pos <= 0) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if (pos == 1) {
            DeleteFromBeg();
            return;
        }

        Node* temp = head;
        Node* prev = nullptr;

        for (int i = 1; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == head) {
            cout << "Position not found!" << endl;
            return;
        }

        prev->next = temp->next;
        if (temp == tail)
            tail = prev;

        delete temp;
        cout << "Node Deleted From Position!" << endl;
    }
};

int main() {
    CircularSinglyLinkedList list;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Display";
        cout << "\n5. Delete Beginning\n6. Delete End\n7. Delete Position\n8. Exit\n";

        cin >> choice;

        switch (choice) {
        case 1: cin >> val; list.InsertInBeg(val); break;
        case 2: cin >> val; list.InsertInEnd(val); break;
        case 3: cin >> val >> pos; list.InsertAtAnyPosition(val, pos); break;
        case 4: list.Display(); break;
        case 5: list.DeleteFromBeg(); break;
        case 6: list.DeleteFromEnd(); break;
        case 7: cin >> pos; list.DeleteNodeFromAnyPosition(pos); break;
        case 8: return 0;
        default: cout << "Invalid Choice!" << endl;
        }
    }
}
