#include <iostream>      // For input-output operations (cout, cin)
using namespace std;     // Allows using std names directly

// ── Stack Using Array ────────────────────────────────────────────────────────
// Fixed-size stack — capacity set at creation, cannot grow dynamically
class Stack {
    int *arr;            // Pointer to dynamically allocated array holding stack elements
    int topIndex;        // Index of the top element (-1 means stack is empty)
    int capacity;        // Maximum number of elements the stack can hold

public:
    // Constructor: allocates array of given size and initializes empty stack
    Stack(int size) {
        capacity = size;             // Store max capacity
        arr = new int[capacity];     // Allocate array on heap
        topIndex = -1;               // -1 indicates stack is empty
    }

    // Destructor: frees dynamically allocated array to prevent memory leaks
    ~Stack() {
        delete[] arr;                // Release heap memory when object is destroyed
    }

    // Function to check if stack has no elements — O(1)
    bool isEmpty() {
        return topIndex == -1;       // Stack is empty when topIndex hasn't moved from initial value
    }

    // Function to check if stack has reached max capacity — O(1)
    bool isFull() {
        return topIndex == capacity - 1;   // Top is at last valid index means array is full
    }

    // Function to insert an element at the top of the stack — O(1)
    void push(int value) {
        if (isFull()) {
            cout << "Stack is full!" << endl;    // Overflow check
            return;
        }
        topIndex++;                  // Move top up by one position
        arr[topIndex] = value;       // Place new value at top position
        cout << "Pushed " << value << " to stack." << endl;
    }

    // Function to remove the top element from the stack — O(1)
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;   // Underflow check
            return;
        }
        cout << "Popped " << arr[topIndex] << " from stack." << endl;
        topIndex--;                  // Move top down by one — element is not erased but unreachable
    }

    // Function to return top element without removing it — O(1)
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;               // Returns -1 as sentinel value when stack is empty
        }
        return arr[topIndex];        // Return value at current top index
    }

    // Function to display all elements from top to bottom — O(n)
    void showStack() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = topIndex; i >= 0; i--) {   // Traverse from top down to bottom
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// ── Main Function ────────────────────────────────────────────────────────────
int main() {
    Stack s(5);          // Create stack with max capacity of 5

    s.push(10);          // Stack: 10
    s.push(20);          // Stack: 20 10
    s.push(30);          // Stack: 30 20 10

    s.showStack();       // Output: 30 20 10

    cout << "Top element: " << s.peek() << endl;   // Output: 30

    s.pop();             // Removes 30 — Stack: 20 10
    s.showStack();       // Output: 20 10

    return 0;
}