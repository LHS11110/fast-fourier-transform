#include "fft.hpp"
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
#include <cassert>

// 헬퍼 함수: 두 실수의 차이가 오차 범위(허용치) 이내인지 확인
bool is_close(double a, double b, double tol = 1e-6) {
    return std::abs(a - b) < tol;
}

int main() {
    FFT fft_solver;
    
    // 간단한 4개짜리 신호 생성 (크기는 2의 거듭제곱)
    std::vector<std::complex<double>> original = {
        {1.0, 0.0}, {2.0, 0.0}, {3.0, 0.0}, {4.0, 0.0}
    };
    
    // FFT를 수행할 복사본
    std::vector<std::complex<double>> data = original;

    // 1. FFT 수행
    fft_solver.fft(data);
    
    std::cout << "--- FFT Results ---\n";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "data[" << i << "] = " << data[i] << "\n";
    }

    // 2. IFFT 수행 (역변환)
    fft_solver.ifft(data);
    
    std::cout << "\n--- IFFT Results ---\n";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << "data[" << i << "] = " << data[i] << "\n";
    }

    // 3. 역변환 결과가 원본과 일치하는지 검증
    for (size_t i = 0; i < original.size(); ++i) {
        if (!is_close(original[i].real(), data[i].real()) ||
            !is_close(original[i].imag(), data[i].imag())) {
            std::cerr << "\n[FAIL] Test failed at index " << i << "\n";
            std::cerr << "Expected: " << original[i] << ", Got: " << data[i] << "\n";
            return 1;
        }
    }
    
    std::cout << "\n[SUCCESS] All tests passed successfully!" << std::endl;
    return 0;
}
