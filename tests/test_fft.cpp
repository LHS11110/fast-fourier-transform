#include "fft.hpp"
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <random>

// 헬퍼 함수: 두 실수의 차이가 오차 범위(허용치) 이내인지 확인
bool is_close(double a, double b, double tol = 1e-6) {
    return std::abs(a - b) < tol;
}

bool verify_ifft(const std::vector<std::complex<double>>& original, const std::vector<std::complex<double>>& result) {
    if (original.size() != result.size()) return false;
    for (size_t i = 0; i < original.size(); ++i) {
        if (!is_close(original[i].real(), result[i].real()) ||
            !is_close(original[i].imag(), result[i].imag())) {
            std::cerr << "\n[FAIL] Test failed at index " << i << "\n";
            std::cerr << "Expected: " << original[i] << ", Got: " << result[i] << "\n";
            return false;
        }
    }
    return true;
}

bool test_simple_size4() {
    FFT fft_solver;
    std::vector<std::complex<double>> original = {
        {1.0, 0.0}, {2.0, 0.0}, {3.0, 0.0}, {4.0, 0.0}
    };
    std::vector<std::complex<double>> data = original;

    fft_solver.fft(data);
    fft_solver.ifft(data);
    
    if (!verify_ifft(original, data)) return false;
    std::cout << "[PASS] test_simple_size4\n";
    return true;
}

bool test_complex_size8() {
    FFT fft_solver;
    std::vector<std::complex<double>> original = {
        {1.0, 1.0}, {2.0, -1.0}, {3.0, 0.5}, {4.0, -0.5},
        {-1.0, 2.0}, {-2.0, -2.0}, {0.0, 1.0}, {1.5, -1.5}
    };
    std::vector<std::complex<double>> data = original;

    fft_solver.fft(data);
    fft_solver.ifft(data);
    
    if (!verify_ifft(original, data)) return false;
    std::cout << "[PASS] test_complex_size8\n";
    return true;
}

bool test_large_random_size1024() {
    FFT fft_solver;
    std::mt19937 gen(42);
    std::uniform_real_distribution<double> dist(-100.0, 100.0);
    
    int n = 1024;
    std::vector<std::complex<double>> original(n);
    for (int i = 0; i < n; ++i) {
        original[i] = {dist(gen), dist(gen)};
    }
    std::vector<std::complex<double>> data = original;

    fft_solver.fft(data);
    fft_solver.ifft(data);
    
    if (!verify_ifft(original, data)) return false;
    std::cout << "[PASS] test_large_random_size1024\n";
    return true;
}

bool test_all_zeros() {
    FFT fft_solver;
    std::vector<std::complex<double>> original(16, {0.0, 0.0});
    std::vector<std::complex<double>> data = original;

    fft_solver.fft(data);
    fft_solver.ifft(data);
    
    if (!verify_ifft(original, data)) return false;
    std::cout << "[PASS] test_all_zeros\n";
    return true;
}

int main() {
    std::cout << "Running FFT tests...\n";
    bool all_passed = true;
    
    // Evaluate all tests instead of short-circuiting
    bool r1 = test_simple_size4();
    bool r2 = test_complex_size8();
    bool r3 = test_all_zeros();
    bool r4 = test_large_random_size1024();
    
    all_passed = r1 && r2 && r3 && r4;
    
    if (all_passed) {
        std::cout << "\n[SUCCESS] All tests passed successfully!\n";
        return 0;
    } else {
        std::cerr << "\n[FAIL] Some tests failed!\n";
        return 1;
    }
}
