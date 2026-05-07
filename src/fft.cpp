#include "fft.hpp"
#include <cmath>

// Cooley-Tukey Algorithm
// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Note: Requires n to be a power of 2
// @param a: input vector of complex numbers, size must be power of 2
// @param invert: boolean flag to indicate whether to perform inverse FFT
void FFT::fft(std::vector<std::complex<double>> &a, bool invert) noexcept {
  int n = a.size();
  if (n == 1) {
    return;
  }

  std::vector<std::complex<double>> a0(n / 2);
  std::vector<std::complex<double>> a1(n / 2);

  for (int i = 0; i < n / 2; i++) {
    a0[i] = a[2 * i];
    a1[i] = a[2 * i + 1];
  }

  fft(a0, invert);
  fft(a1, invert);

  double ang = 2 * M_PI / n * (invert ? -1 : 1);
  std::complex<double> w(1), wn(cos(ang), sin(ang));

  for (int i = 0; i < n / 2; i++) {
    a[i] = a0[i] + w * a1[i];
    a[i + n / 2] = a0[i] - w * a1[i];
    w *= wn;
  }

  if (invert) {
    for (int i = 0; i < n; i++) {
      a[i] /= 2;
    }
  }
}

void FFT::fft(std::vector<std::complex<double>> &a) noexcept { fft(a, false); }

void FFT::ifft(std::vector<std::complex<double>> &a) noexcept { fft(a, true); }