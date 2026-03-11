#include <iostream>      // For input-output operations (cout, cin)
#include <vector>        // For using STL vector container
using namespace std;     // Allows using std names directly

// ── Main Function ────────────────────────────────────────────────────────────
int main() {

    // ── Vector Initialization Methods ────────────────────────────────────────

    vector<int> vec;              // Empty vector — size 0, no elements
    vector<int> vec1(10);         // Vector of size 10 — all elements initialized to 0
    vector<int> vec2(5, 2);       // Vector of size 5 — all elements initialized to 2

    // Print sizes of each vector
    cout << "Size of vec: "  << vec.size()  << endl;    // Output: 0
    cout << "Size of vec1: " << vec1.size() << endl;    // Output: 10
    cout << "Size of vec2: " << vec2.size() << endl;    // Output: 5

    // ── Initializing Vector from Array ────────────────────────────────────────

    int arr[5] = {12, 45, 90, 23, 98};                  // Regular array with 5 elements
    vector<int> vec3(begin(arr), end(arr));              // Copy array elements into vector
                                                         // begin(arr) → pointer to first element
                                                         // end(arr)   → pointer past last element

    // Print all elements of vec3
    cout << "vec3 elements: ";
    for (int i = 0; i < vec3.size(); i++) {
        cout << vec3[i] << " ";                          // Access elements using index operator
    }
    cout << endl;                                        // Newline after all elements are printed

    return 0;
}