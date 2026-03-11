#include <iostream>       // For input-output operations (cout, cin)
using namespace std;      // Allows using std names directly

// ── Node Structure ───────────────────────────────────────────────────────────
// Each node holds a value and a pointer to the next node
struct Node {
    int data;             // The value stored in this node
    Node* next;           // Pointer to the next node in the list

    // Constructor: initializes node with given value, next set to null
    Node(int val) : data(val), next(nullptr) {}
};

// ── Stack Using Linked List ──────────────────────────────────────────────────
// Top of stack = head of linked list (most recently pushed node)
class MyStack {
private:
    Node* head;           // Pointer to the top of the stack (head of list)
    int size;             // Tracks number of elements in the stack

public:
    // Constructor: initializes empty stack
    MyStack() : head(nullptr), size(0) {}

    // Destructor: frees all dynamically allocated nodes to prevent memory leaks
    ~MyStack() {
        while (head != nullptr) {
            Node* temp = head;   // Store current head
            head = head->next;   // Move head to next node
            delete temp;         // Free the old head
        }
    }

    // Function to push an element onto the stack
    // New node is inserted at the head — O(1)
    void push(int x) {
        Node* newNode = new Node(x);  // Create new node with given value
        newNode->next = head;         // New node points to current head
        head = newNode;               // Head now points to new node (new top)
        size++;                       // Increment size
    }

    // Function to remove and return the top element
    // Removes head node — O(1)
    int pop() {
        int val = head->data;    // Store top value before removing
        Node* temp = head;       // Temporarily hold the head node
        head = head->next;       // Move head to next node
        delete temp;             // Free the removed node's memory
        size--;                  // Decrement size
        return val;              // Return removed value
    }

    // Function to return the top element without removing it — O(1)
    int top() {
        return head->data;       // Head node holds the top of stack
    }

    // Function to check if the stack is empty — O(1)
    bool empty() {
        return head == nullptr;  // Stack is empty if head points to nothing
    }

    // Function to return current number of elements — O(1)
    int getSize() {
        return size;             // Return tracked size
    }
};

// ── Main Function ────────────────────────────────────────────────────────────
int main() {
    MyStack s;

    s.push(10);                                          // Stack: 10
    s.push(20);                                          // Stack: 20 -> 10
    s.push(30);                                          // Stack: 30 -> 20 -> 10

    cout << "Top: "   << s.top()     << endl;            // Output: 30
    cout << "Pop: "   << s.pop()     << endl;            // Output: 30
    cout << "Top: "   << s.top()     << endl;            // Output: 20
    cout << "Size: "  << s.getSize() << endl;            // Output: 2
    cout << "Empty: " << s.empty()   << endl;            // Output: 0 (false)

    return 0;
}