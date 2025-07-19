#include <iostream>
#include <chrono>

// Compile-time Fibonacci
constexpr int fib_constexpr(int n) {
    int a = 0, b = 1;
    for (int i = 0; i < n; ++i) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return a;
}


// Runtime Fibonacci
int fib_runtime(int n) {
    if (n <= 1) return n;
    return fib_runtime(n - 1) + fib_runtime(n - 2);
}

int main() {
    // Runtime
    auto start1 = std::chrono::high_resolution_clock::now();
    volatile int result1 = fib_runtime(30); // prevent optimization
    auto end1 = std::chrono::high_resolution_clock::now();
    std::cout << "Runtime Fibonacci: " << (end1 - start1).count() << " ns\n";

    // Compile-time
    constexpr int result2 = fib_constexpr(30); // done at compile time
    auto start2 = std::chrono::high_resolution_clock::now();
    volatile int dummy = result2; // force usage
    auto end2 = std::chrono::high_resolution_clock::now();
    std::cout << "Compile-time Fibonacci: " << (end2 - start2).count() << " ns\n";
}
