#ifndef FFT_H
#define FFT_H
#include <complex>


class FFT {
  private:
    int n;
  public:
    FFT(int n);
    complex* transform(complex* values);
    complex* inverseTransform(complex* values);
};

#endif FFT_H
