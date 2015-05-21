#ifndef FFT_H
#define FFT_H
#include <complex>


class FFT {
  private:
    int n;
  public:
    FFT(int n);
    complex<double>* transform(complex* values, int n, bool inverse);
    complex<double>* inverseTransform(complex* values, int n);
};

#endif FFT_H
