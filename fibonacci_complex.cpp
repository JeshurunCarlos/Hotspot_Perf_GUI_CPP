#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <iomanip>

const int MATRIX_SIZE = 512;  // Large for cache misses
const int FIB_DEPTH = 42;     // Deep recursion
const int ARRAY_SIZE = 10000000;

void naive_matmul(const std::vector<std::vector<double>>& A,
                  const std::vector<std::vector<double>>& B,
                  std::vector<std::vector<double>>& C) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            double sum = 0.0;
            for (int k = 0; k < MATRIX_SIZE; ++k) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

long long fib(int n) {
    if (n <= 1) return n;
    return fib(n - 1) + fib(n - 2);
}

long long sum_loop(const std::vector<int>& vec) {
    long long sum = 0;
    for (int val : vec) {
        sum += val;
    }
    return sum;
}

int main() {
    // Matrix multiplication
    std::vector<std::vector<double>> A(MATRIX_SIZE, std::vector<double>(MATRIX_SIZE, 1.0));
    std::vector<std::vector<double>> B(MATRIX_SIZE, std::vector<double>(MATRIX_SIZE, 2.0));
    std::vector<std::vector<double>> C(MATRIX_SIZE, std::vector<double>(MATRIX_SIZE, 0.0));
    naive_matmul(A, B, C);

    // Recursive Fibonacci (hotspot in recursion)
    std::cout << "Fib(" << FIB_DEPTH << ") = " << fib(FIB_DEPTH) << "\n";

    // Large array sum (loop hotspot)
    std::vector<int> large_vec(ARRAY_SIZE);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);
    for (int& val : large_vec) val = dis(gen);
    long long total = sum_loop(large_vec);

    std::cout << "Matrix mul done. Sum: " << total << "\n";
    return 0;
}
