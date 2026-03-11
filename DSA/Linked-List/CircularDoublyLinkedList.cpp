#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;

    Node(int val) : prev(nullptr), data(val), next(nullptr) {}
};

class CircularDoublyLinkedList {
    Node* head;
    Node* tail;

public:
    CircularDoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at Beginning
    void InsertInBeg(int val) {
        Node* newNode = new Node(val);

        if (!head) {
            head = tail = newNode;
            head->next = head;
            head->prev = head;
        } else {
            newNode->next = head;
            newNode->prev = tail;
            head->prev = newNode;
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
            head->next = head;
            head->prev = head;
        } else {
            newNode->prev = tail;
            newNode->next = head;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        cout << "Node Inserted In End!" << endl;
    }

    // Insert at Position
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
        for (int i = 1; i < pos - 1 && temp->next != head; i++)
            temp = temp->next;

        if (temp->next == head && pos > 2) {
            cout << "Position not found!" << endl;
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
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
            head->prev = tail;
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
            Node* temp = tail;
            tail = tail->prev;
            tail->next = head;
            head->prev = tail;
            delete temp;
        }
        cout << "Node Deleted From End!" << endl;
    }

    // Delete at Position
    void DeleteNodeFromAnyPosition(int pos) {
        if (pos <= 0 || !head) {
            cout << "Invalid Position!" << endl;
            return;
        }

        if (pos == 1) {
            DeleteFromBeg();
            return;
        }

        Node* temp = head;
        for (int i = 1; i < pos && temp->next != head; i++)
            temp = temp->next;

        if (temp == head) {
            cout << "Position not found!" << endl;
            return;
        }

        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        if (temp == tail)
            tail = temp->prev;

        delete temp;
        cout << "Node Deleted From Position!" << endl;
    }

int main() {
    CircularDoublyLinkedList list;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Display";
        cout << "\n5. Delete Beginning\n6. Delete End\n7. Delete Position";
        cout << "\n8. Delete Value\n9. Search\n10. Count\n11. Sort\n12. Exit\n";

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
    return 0;
}
};
