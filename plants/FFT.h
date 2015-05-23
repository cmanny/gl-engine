#ifndef FFT_H
#define FFT_H
#include <complex>

typedef std::complex<double> Complex;

class FFT {
  private:
    int n;
  public:
    FFT(int n);
    Complex* transform(Complex* values, int n, bool inverse);
    Complex* inverseTransform(Complex* values, int n);
};

#endif
