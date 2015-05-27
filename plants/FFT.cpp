#include "FFT.h"


FFT::FFT(int N) : N(N), wN(0), _wN(0), reverse(0), side(0) {
  vals[0] = vals[1] = 0;
  logN = log(N)/log(2); // log2(N) 
  reverse = new unsigned int[N];
  wN = new Complex*[logN];
  _wN = new Complex*[logN];
  int pow2 = 1;
  for(int i = 0; i < N; i++) reverse[i] = reverseBits(i);
  for(int i = 0; i < logN; i++){
    wN[i] = new Complex[pow2]; //Holding the (2^(i+1))th roots of unity
    _wN[i] = new Complex[pow2];
    for(int j = 0; j < pow2; j++) {
      wN[i][j] = makeWn(j, pow2<<1); // jth power of the (2^(i+1))th root of unity
      _wN[i][j] = pow(wN[i][j], -1); // inverse 
    }
    pow2 <<= 1; //double pow2
  } 
  vals[0] = new Complex[N];
  vals[1] = new Complex[N];
}

Complex FFT::makeWn(double n, double N){
  return Complex(cos(2*M_PI*n/N), sin(2*M_PI*n/N));
}

FFT::~FFT(){
  if(vals[0]) delete [] vals[0];
  if(vals[1]) delete [] vals[1];
  if(wN){
    for(int i = 0; i < logN; i++) if(wN[i]) delete [] wN[i];
    delete [] wN;
  }
  if(_wN){
    for(int i = 0; i < logN; i++) if(_wN[i]) delete [] _wN[i];
    delete [] _wN;
  }
  if (reverse) delete [] reverse;
}

//Reverse the bits of an integer which has logN bits
unsigned int FFT::reverseBits(unsigned int n){
  unsigned int res = 0;
  for(int i = 0; i < logN; i++) {
    res <<= 1;
    res += (n&1);
    n >>= 1;
  }
  return res;
}

void FFT::transform(Complex* input, Complex* output, int stride, int offset, bool inverse){
  //fill our first side of values with the bit reversed input
  for(int i = 0; i < N; i++) vals[side][i] = input[reverse[i] * stride + offset];
 
  Complex** wNs = (inverse) ? wN : _wN; //If inverse, choose the inverse roots of unity
  int spN = N>>1; //Number of subproblems, at each step i we have N/(2^(i+1)) subproblems
  int size = 2; // How many k values much we iterate through, how large is the reconstruction
  int size_2 = size>>1; //size over 2
  for(int i = 0; i < logN; i++){
    side ^= 1;
    for(int spi = 0; spi < spN; spi ++){ // From subproblem index = 0 to subproblem count
      for(int k = 0; k < size_2; k++){
        //Inside a subproblem, we reconstruct based on the DL-Lemma, together with the k + N/2 rule
        vals[side][spi * size + k] = vals[side^1][spi * size + k] + wNs[i][k] * vals[side^1][spi * size + (k + size_2)];
        vals[side][spi * size + (k + size_2)] = vals[side^1][spi * size + k] - wNs[i][k] * vals[side^1][spi * size + (k + size_2)];
      }
    }
    spN >>= 1; // Number of subproblems halves
    size <<= 1; // Size of reconstruction increases
    size_2 <<= 1;
  }
  for(int i = 0; i < N; i++) output[i * stride + offset] = vals[side][i] * Complex(((inverse) ? 1.0f/N : 1.0f), 0.0);
}


//Assumes a square input
void FFT::lowpass2(Complex* input, float beta, int N){
  for(int y = 0; y < N; y++){
    for(int x = 0; x < N; x++){
      int i = y * N + x;
      double f = sqrt((x-N/2)/float(N) * (x-N/2)/float(N) + (y-N/2)/float(N) * (y-N/2)/float(N));
      f = f < 1.0f/N ? 1.0f / N : f;
      input[i] *= 1.0f/pow(f, 1.8);
    }
  }
}

void FFT::fft2(Complex* input, Complex* output, int N){
  for(int i = 0; i < N; i++) transform(input, output, 1, i*N, false); //rows
  for(int i = 0; i < N; i++) transform(input, output, N, i, false); //columns 
}

void FFT::ifft2(Complex* input, Complex* output, int N){
  for(int i = 0; i < N; i++) transform(input, output, 1, i*N, true); //rows
  for(int i = 0; i < N; i++) transform(input, output, N, i, true); //columns 
}
