#include "FFT.h"

FFT::FFT(int n) {
  this->n = n;
}

Complex* FFT::transform(Complex* values, int n, bool inverse){
  if(n == 1)
    return values;
  Complex wN = exp(Complex(0.0, -2*M_PI/(double)n));
  if(inverse) wN = pow(wN, -1);
  Complex w(1.0, 0.0);
  Complex *a0 = new Complex[n/2];
  Complex *a1 = new Complex[n/2];
  for(int i = 0; i < n/2; i++){
    a0[i] = values[i*2];
    a1[i] = values[i*2 + 1];
  }
  Complex *y0 = transform(a0, n/2, inverse);
  Complex *y1 = transform(a1, n/2, inverse);
  Complex *y = new Complex[n];
  for(int k = 0; k < (n/2); k++){
    y[k] = y0[k] + w*y1[k];
    y[k + n/2] = y0[k] - w*y1[k];
    w = w*wN;
  }
  return y;
}

Complex* FFT::inverseTransform(Complex* values, int n){
  Complex* inv = transform(values, n, true);
  for(int i = 0; i < n; i++){
    inv[i] /= n;
  }
  return inv;
}
