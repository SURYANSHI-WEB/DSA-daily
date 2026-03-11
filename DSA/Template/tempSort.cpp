#include <iostream>      // For input-output operations (cout, cin)
using namespace std;     // Allows using std names directly

// ── Template Bubble Sort ─────────────────────────────────────────────────────
// Works with any data type that supports > operator (int, double, string, etc.)
// Sorts array in ascending order by repeatedly swapping adjacent elements
// Time complexity: O(n²) — not efficient for large arrays but simple to understand
template <typename T>
void bubbleSort(T arr[], int n) {
    for (int i = 0; i < n - 1; i++) {           // Outer loop: n-1 passes needed
        for (int j = 0; j < n - 1 - i; j++) {   // Inner loop: shrinks each pass — last i elements are already sorted
            if (arr[j] > arr[j + 1])             // If current element is greater than next
                swap(arr[j], arr[j + 1]);        // Swap them — bubbles larger element rightward
        }
    }
}

// ── Template Add Function ────────────────────────────────────────────────────
// Returns sum of two values of any type that supports + operator
// T is deduced automatically from the arguments passed
template <typename T>
T add(T a, T b) {
    return a + b;        // Works for int, double, string (concatenation), etc.
}

// ── Main Function ────────────────────────────────────────────────────────────
int main() {
    int nums[5]       = {91, 17, 120, 80, 15};                      // Unsorted integer array
    string names[5]   = {"John", "Alice", "Bob", "Diana", "Charlie"}; // Unsorted string array

    bubbleSort(nums, 5);     // Sort integers in ascending order    → 15 17 80 91 120
    bubbleSort(names, 5);    // Sort strings alphabetically         → Alice Bob Charlie Diana John

    cout << "Sorted numbers: ";
    for (int i = 0; i < 5; i++) cout << nums[i] << " ";     // Print sorted integers

    cout << "\nSorted names: ";
    for (int i = 0; i < 5; i++) cout << names[i] << " ";    // Print sorted strings

    cout << "\nAdd result: " << add(30.0, 12.5);             // T deduced as double → Output: 42.5

    return 0;
}