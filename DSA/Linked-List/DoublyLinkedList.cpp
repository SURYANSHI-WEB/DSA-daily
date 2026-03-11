
#include <iostream>
using namespace std;

class Node {
public:
    Node* prev;
    int data;
    Node* next;
    Node(int val) :prev(nullptr), data(val), next(nullptr) {}
};

class DoublyLinkedList {
    Node* head=nullptr, *tail=nullptr;
public:

    void InsertInBeg(int val) {
        Node* newNode = new Node(val);
        if(head==nullptr && tail==nullptr){
            head = tail = newNode;
        }else{
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }cout<<"Node Inserted In Beginning!"<<endl;}

    void InsertInEnd(int val){
        Node* newNode = new Node(val);
        if(head==nullptr && tail==nullptr){
            head = tail = newNode;
        }else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }cout<<"Node Inserted In End!"<<endl;
    }

    void InsertAtAnyPosition(int val, int pos){
        if(pos==1){
            InsertInBeg(val);
            return;
        }
        Node* temp = head;
        for(int i=1;i<pos-1 && temp;i++)
            temp = temp->next;
        if(!temp){
            cout<<"Position not found!"<<endl;
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        newNode->prev = temp;
        if(temp->next)
            temp->next->prev = newNode;
        temp->next = newNode;
        if(newNode->next==nullptr)
            tail = newNode;
        cout<<"Node Inserted!"<<endl;
    }

    void DeleteFromBeg() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        if(head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        cout << "Node Deleted From Beginning!" << endl;
    }

    void DeleteFromEnd() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if(tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        cout << "Node Deleted From End!" << endl;
        
    }

    void DeleteNodeFromAnyPosition(int pos) {
        if(pos==1){
            DeleteFromBeg();
            return;
        }
        Node* temp = head;
        for(int i=1;i<pos && temp;i++)
            temp = temp->next;
        if(!temp){
            cout<<"Position not found!"<<endl;
            return;
        }
        if(temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        if(temp->prev)
            temp->prev->next = temp->next;
        delete temp;
        cout<<"Node Deleted From Any Position!"<<endl;
    }

    void DeleteByValue(int val) {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp && temp->data != val)
            temp = temp->next;
        if (!temp) {
            cout << "Value not found!" << endl;
            return;
        }
        if(temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
        if(temp->prev)
            temp->prev->next = temp->next;
        else
            head = temp->next;
        delete temp;
        cout << "Value Deleted!" << endl;
    }

    void Search(int val) {
        int pos = 1;
        Node* temp = head;
        while (temp) {
            if (temp->data == val) {
                cout << "Element found at position " << pos << endl;
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << "Element not found!" << endl;
    }

    void CountElements() {
        int count = 0;
        Node* temp = head;
        while (temp) {
            count++;
            temp = temp->next;
        }
        cout << "Total Nodes: " << count << endl;
    }

    void Sort() {
        if (!head) return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->data > j->data) {
                    swap(i->data, j->data);
                }
            }
        }
        cout << "List Sorted!" << endl;
    }

    void Display() {
        if (!head) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
 int main() {
    DoublyLinkedList list;
    int choice, val, pos;

    while (true) {
        cout << "\n1. Insert Node In Beginning";
        cout << "\n2. Insert Node At End";
        cout << "\n3. Insert Node At Any Position";
        cout << "\n4. Display List";
        cout << "\n5. Delete Node From Beginning";
        cout << "\n6. Delete Node From End";
        cout << "\n7. Delete Node From Any Position";
        cout << "\n8. Delete Given Value";
        cout << "\n9. Search Element";
        cout << "\n10. Count Elements";
        cout << "\n11. Sort List";
        cout << "\n12. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: cin >> val; 
        list.InsertInBeg(val); break;
        case 2: cin >> val; 
        list.InsertInEnd(val); break;
        case 3: cin >> val >> pos; 
        list.InsertAtAnyPosition(val, pos); break;
        case 4: 
        list.Display(); break;
        case 5: 
        list.DeleteFromBeg(); break;
        case 6: 
        list.DeleteFromEnd(); break;
        case 7: cin >> pos; 
        list.DeleteNodeFromAnyPosition(pos); break;
        case 8: cin >> val; 
        list.DeleteByValue(val); break;
        case 9: cin >> val; 
        list.Search(val); break;
        case 10: 
        list.CountElements(); break;
        case 11: 
        list.Sort(); break;
        case 12: exit(0);
        default: cout << "Invalid Choice!" << endl;
        }
    }
}
