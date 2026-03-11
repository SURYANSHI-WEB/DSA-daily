#include <iostream>      // For input-output operations (cout, cin)
#include <vector>        // For using STL vector container
#include <algorithm>     // For STL algorithms: reverse, max_element, min_element
using namespace std;     // Allows using std names directly

// ── Main Function ────────────────────────────────────────────────────────────
int main() {

    vector<int> v = {16, 11, 7, 5, 3};   // Initialize vector with 5 elements

    // reverse(v.begin(), v.end());        // Reverses elements in-place — commented out for now

    // max_element() returns an iterator pointing to the largest element
    // * dereferences the iterator to get the actual value
    cout << "largest element = "  << *max_element(v.begin(), v.end()) << endl;  // Output: 16

    // min_element() returns an iterator pointing to the smallest element
    // * dereferences the iterator to get the actual value
    cout << "smallest element = " << *min_element(v.begin(), v.end()) << endl;  // Output: 3

    // Range-based for loop — 'auto' deduces type as int automatically
    // Iterates through each element without needing index
    cout << "elements: ";
    for (auto i : v) {
        cout << i << " ";                 // Output: 16 11 7 5 3
    }
    cout << endl;                         // Newline after all elements are printed

    return 0;
}