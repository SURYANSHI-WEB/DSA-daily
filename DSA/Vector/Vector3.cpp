#include <map>               // Ordered key-value pairs
#include <set>               // Ordered unique elements
#include <list>              // Doubly linked list
#include <cmath>             // Math functions (sqrt, pow, etc.)
#include <ctime>             // Time functions
#include <deque>             // Double-ended queue
#include <queue>             // FIFO queue
#include <stack>             // LIFO stack
#include <string>            // String operations
#include <bitset>            // Fixed-size bit array
#include <cstdio>            // C-style I/O (printf, scanf)
#include <limits>            // Numeric limits
#include <vector>            // Dynamic array
#include <climits>           // INT_MAX, INT_MIN etc.
#include <cstring>           // C-style string functions
#include <cstdlib>           // exit(), abs(), etc.
#include <fstream>           // File input/output
#include <numeric>           // Numeric algorithms (accumulate, etc.)
#include <sstream>           // String stream
#include <iostream>          // For input-output operations (cout, cin)
#include <algorithm>         // STL algorithms (sort, reverse, etc.)
#include <unordered_map>     // Hash map — faster lookup than map
using namespace std;         // Allows using std names directly

// ── Main Function ────────────────────────────────────────────────────────────
int main() {

    int n;
    cin >> n;                            // Read size of vector

    vector<int> v1(n);                   // Create vector of size n
    for (int i = 0; i < n; i++) {        // Fixed: was '1<n' (always true → infinite loop)
        cin >> v1[i];                    // Read each element into vector
    }

    // Create v2 as reverse of v1
    // rbegin() → reverse iterator pointing to last element
    // rend()   → reverse iterator pointing before first element
    vector<int> v2(v1.rbegin(), v1.rend());

    // A vector is a palindrome if it equals its own reverse
    if (v1 == v2) {
        cout << "Palindrome" << endl;        // v1 reads same forwards and backwards
    } else {
        cout << "Not a Palindrome" << endl;
    }

    return 0;
}