#include <iostream>      // For input-output operations (cout, cin)
#include <cstdlib>       // For exit() function
using namespace std;     // Allows using std names directly

// ── Node Structure ───────────────────────────────────────────────────────────
// Template node — works with any data type (int, float, string, etc.)
template <typename T>
class Node {
public:
    T data;              // The value stored in this node
    Node<T>* next;       // Pointer to the next node in the list

    // Constructor: initializes node with given value, next set to null
    Node(T val) : data(val), next(nullptr) {}
};

// ── Queue Using Linked List ──────────────────────────────────────────────────
// FIFO structure — elements inserted at rear, removed from front
// Template class — works with any data type
template <typename T>
class Queue {
private:
    Node<T>* front;      // Pointer to the first node (dequeue happens here)
    Node<T>* rear;       // Pointer to the last node (enqueue happens here)

public:
    // Constructor: initializes empty queue with no nodes
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor: frees all dynamically allocated nodes to prevent memory leaks
    ~Queue() {
        while (front != nullptr) {
            Node<T>* temp = front;   // Store current front node
            front = front->next;     // Move front to next node
            delete temp;             // Free the old front node
        }
    }

    // Function to check if queue is empty — O(1)
    bool isEmpty() {
        return front == nullptr;     // Queue is empty if front points to nothing
    }

    // Function to insert an element at the rear of the queue — O(1)
    void enqueue(T data) {
        Node<T>* newNode = new Node<T>(data);  // Create new node with given value

        if (rear == nullptr) {
            // Queue is empty — new node is both front and rear
            front = rear = newNode;
        } else {
            // Link new node after current rear
            rear->next = newNode;    // Current rear points to new node
            rear = newNode;          // Update rear to new node
        }

        cout << "Data inserted into queue!" << endl;
    }

    // Function to remove an element from the front of the queue — O(1)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!!!" << endl;   // Cannot remove from empty queue
            return;
        }

        Node<T>* temp = front;                      // Hold current front node
        cout << "Deleted element: " << front->data << endl;

        front = front->next;                        // Move front to next node

        if (front == nullptr)
            rear = nullptr;                         // Queue is now empty, reset rear too

        delete temp;                                // Free the removed node's memory
    }

    // Function to return front element without removing it — O(1)
    T peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return T();              // Returns default value of type T (0 for int, "" for string etc.)
        }
        return front->data;          // Return value at front without modifying queue
    }

    // Function to display all elements from front to rear — O(n)
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node<T>* temp = front;           // Start traversal from front
        cout << "Queue elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";   // Print each node's data
            temp = temp->next;           // Move to next node
        }
        cout << endl;
    }
};

// ── Main Function ────────────────────────────────────────────────────────────
int main() {
    Queue<int> que;      // Create an integer queue (change int to use other types)

    while (true) {
        // Display menu options
        cout << "\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int data;
                cout << "Enter data: ";
                cin >> data;
                que.enqueue(data);       // Insert element at rear
                break;
            }
            case 2:
                que.dequeue();           // Remove element from front
                break;
            case 3:
                cout << "Front element: " << que.peek() << endl;  // View front without removing
                break;
            case 4:
                que.display();           // Print all elements
                break;
            case 5:
                exit(0);                 // Terminate program
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}