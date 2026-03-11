#include <iostream>      // For input-output operations (cout, cin)
#include <queue>         // For using STL queue container
using namespace std;     // Allows using std names directly

// Class to implement Stack using two Queues
class MyStack {
private:
    queue<int> q1;       // Main queue: front of q1 represents top of stack
    queue<int> q2;       // Helper queue used during push operation

public:
    // Constructor (initializes empty stack)
    MyStack() {}

    // Function to push an element onto the stack
    void push(int x) {
        q2.push(x);      // Step 1: Insert new element into helper queue q2

        // Step 2: Move all existing elements from q1 to q2
        // This ensures the newly inserted element stays at the front
        while (!q1.empty()) {
            q2.push(q1.front()); // Copy front element of q1 to q2
            q1.pop();            // Remove that element from q1
        }

        // Step 3: Swap q1 and q2
        // Now q1 contains elements in stack order (LIFO)
        swap(q1, q2);
    }

    // Function to remove and return the top element of stack
    int pop() {
        int val = q1.front();  // Store the front element (top of stack)
        q1.pop();              // Remove the top element
        return val;            // Return removed element
    }

    // Function to return the top element without removing it
    int top() {
        return q1.front();     // Front of q1 is the top of stack
    }

    // Function to check if the stack is empty
    bool empty() {
        return q1.empty();     // Stack is empty if q1 has no elements
    }
};
