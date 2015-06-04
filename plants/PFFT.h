#ifndef PFFT_H
#define PFFT_H
#include <complex>
#include <tbb/task.h>

typedef std::complex<double> Complex;

class PFFT : public tbb::task {
  private:
    unsigned int N,
                 logN,
                 side,
                 * reverse;
    Complex** wN,
           ** _wN;
    Complex* vals[2];
  public:
    PFFT(int);
    ~PFFT();
    unsigned int reverseBits(unsigned int);
    Complex makeWn(double, double);


    void transform(Complex*,Complex*,int,int,bool);
    void lowpass2(Complex*, float, int);
    void fft2(Complex*, Complex*, int);
    void ifft2(Complex*, Complex*, int);

    tbb::task* execute(); 
};

#endif
