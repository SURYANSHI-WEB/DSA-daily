#include <iostream>      // For input-output operations (cout, cin)
using namespace std;     // Allows using std names directly

// ── Template Swap Function ───────────────────────────────────────────────────
// Works with any data type — int, double, string, etc.
// Takes both arguments by reference so original variables are modified directly
template <typename T>
void Swap(T &a, T &b) {
    T temp = a;          // Store value of a in temporary variable
    a = b;               // Overwrite a with b's value
    b = temp;            // Overwrite b with original a's value (saved in temp)
}

// ── Main Function ────────────────────────────────────────────────────────────
int main() {
    // Swap two integers
    int a = 5, b = 10;
    cout << "Before Swap a = " << a << ", b = " << b << endl;
    Swap(a, b);                                                   // T deduced as int
    cout << "After Swap a = " << a << ", b = " << b << endl;

    // Swap two doubles
    double x = 1.5, y = 2.5;
    cout << "Before Swap x = " << x << ", y = " << y << endl;
    Swap(x, y);                                                   // T deduced as double
    cout << "After Swap x = " << x << ", y = " << y << endl;

    // Swap two strings
    string s1 = "Delhi", s2 = "Mohali";
    cout << "Before Swap s1 = " << s1 << ", s2 = " << s2 << endl;  // fixed: was showing x, y
    Swap(s1, s2);                                                    // T deduced as string
    cout << "After Swap s1 = " << s1 << ", s2 = " << s2 << endl;   // fixed: was showing x, y

    return 0;
}