#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Inefficient
unsigned long long fib_recursive(int n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// Efficient
unsigned long long fib_dynamic(int n) {
    if (n <= 1) return n;

    unsigned long long prev2 = 0, prev1 = 1, fib = 0;
    for (int i = 2; i <= n; i++) {
        fib = prev1 + prev2;
        prev2 = prev1;
        prev1 = fib;
    }
    return fib;
}

int main() {
    int n = 40;
    int n_large = 120;

    auto start = high_resolution_clock::now();
    unsigned long long result1 = fib_recursive(n);
    auto stop = high_resolution_clock::now();
    auto duration_recursive = duration_cast<milliseconds>(stop - start);

    start = high_resolution_clock::now();
    unsigned long long result2 = fib_dynamic(n_large);
    stop = high_resolution_clock::now();
    auto duration_dynamic = duration_cast<milliseconds>(stop - start);

    cout << "Fibonacci(" << n << ") using recursion: " << result1 << endl;
    cout << "Time taken (recursive for n=40): " << duration_recursive.count() << endl;

    cout << "Fibonacci(" << n_large << ") using dynamic: " << result2 << endl;
    cout << "Time taken (dynamic for n=120): " << duration_dynamic.count() << endl;

    return 0;
}
