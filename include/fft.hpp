#pragma once
#include <complex>
#include <vector>

class FFT {
private:
  // Time Complexity: O(n log n)
  // Space Complexity: O(n)
  // Note: Requires n to be a power of 2
  // @param a: input vector of complex numbers, size must be power of 2
  // @param invert: boolean flag to indicate whether to perform inverse FFT
  void fft(std::vector<std::complex<double>> &a, bool invert) noexcept;

public:
  FFT() = default;
  ~FFT() = default;

  // Time Complexity: O(n log n)
  // Space Complexity: O(n)
  // Note: Requires n to be a power of 2
  // @param a: input vector of complex numbers, size must be power of 2
  void fft(std::vector<std::complex<double>> &a) noexcept;

  // Time Complexity: O(n log n)
  // Space Complexity: O(n)
  // Note: Requires n to be a power of 2
  // @param a: input vector of complex numbers, size must be power of 2
  void ifft(std::vector<std::complex<double>> &a) noexcept;
};