#include "fft.h"

FFT::FFT() {
}

complex* transform(complex* values, int n){
  if(n == 1)
    return values;
  complex<double> wN = exp(0.0, 2*M_PI/(double)n);
  complex<double> w(1.0, 0.0);
  complex<double> a0[] = new complex<double>[n/2];
  complex<double> a1[] = new complex<double>[n/2];
  for(int i = 0; i < n/2; i++){
    a0[i] = values[i*2];
    a1[i] = values[i*2 + 1];
  }
  complex<double> y0[] = transform(a0, n/2);
  complex<double> y1[] = transform(a1, n/2);
  complex<double> y[] = new complex<double>[n];
  for(int k = 0; k < (n/2); k++){
    y[k] = y0[k] + w*y1[k];
    y[k + n/2] = y0[k] - w*y1[k];
    w = w*wN;
  }
  return y;
}

complex* inverseTransform(){ }
