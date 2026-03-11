#include <iostream>      // Provides input-output stream support
#include <stack>         // Allows use of STL stack container
using namespace std;     // Avoids writing std:: repeatedly

// Class to implement Queue using two Stacks
class MyQueue {
private:
    stack<int> stackIn;   // Stack used for enqueue (push) operation
    stack<int> stackOut;  // Stack used for dequeue (pop) and peek operations

    // Transfers elements from stackIn to stackOut
    // This reverses the order to maintain FIFO behavior
    void transfer() {
        while (!stackIn.empty()) {          // Continue until stackIn becomes empty
            stackOut.push(stackIn.top());   // Move top element of stackIn to stackOut
            stackIn.pop();                  // Remove the moved element from stackIn
        }
    }

public:
    // Constructor to initialize an empty queue
    MyQueue() {}

    // Function to insert an element at the back of the queue
    void push(int x) {
        stackIn.push(x);   // Push element onto stackIn
    }

    // Function to remove and return the front element of the queue
    int pop() {
        if (stackOut.empty()) {  // If stackOut has no elements
            transfer();          // Move elements from stackIn to stackOut
        }
        int val = stackOut.top(); // Store the front element of queue
        stackOut.pop();           // Remove the front element
        return val;               // Return the removed element
    }

    // Function to return the front element without removing it
    int peek() {
        if (stackOut.empty()) {  // If stackOut is empty
            transfer();          // Transfer elements to maintain FIFO order
        }
        return stackOut.top();   // Top of stackOut is the front of the queue
    }

    // Function to check if the queue is empty
    bool empty() {
        return stackIn.empty() && stackOut.empty(); // Queue empty if both stacks are empty
    }
};
