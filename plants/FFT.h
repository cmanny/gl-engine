#ifndef FFT_H
#define FFT_H
#include <complex>

typedef std::complex<double> Complex;

class FFT {
  private:
    unsigned int N,
                 logN,
                 side,
                 * reverse;
    Complex** wN,
           ** _wN;
    Complex* vals[2];
  public:
    FFT(int);
    ~FFT();
    unsigned int reverseBits(unsigned int);
    Complex makeWn(double, double);
    void transform(Complex*,Complex*,int,int,bool);
};

#endif
