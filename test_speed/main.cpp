// For testing speed of various data types using FIR template class
#include <math.h>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "noise.h"
#include "fir.h"
#include <sys/time.h>

#include <spuc/spuc_fixed.h>

using namespace std;

double get_time()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    double d = t.tv_sec + (double) t.tv_usec/1000000;
    return d;
}


int main(int argc, char* argv[]) {
  const long LOOPS = ((long)1 << 21);
  const int FIR_SIZE = 64;
  const int MODSIZE = 64;
  const int INT_BITS =  8;
  const int FRAC_BITS = 6;
  const double NOISE_GAIN = 0.010;
  int i;

  typedef SPUC::spuc_fixed<INT_BITS+FRAC_BITS, INT_BITS> spuc_new;

  fir<double>   REF_FIR(FIR_SIZE);
  fir<spuc_new>   MSPUC_FIR(FIR_SIZE);

  double phase = 3.14*1.0/9.0;
  noise AWGN;

  double ref;
  spuc_new msc;

  // Set coefficients
  double c;
  for (i=0;i<FIR_SIZE;i++) {
	c  = 1.0/FIR_SIZE;
	msc = c;
	REF_FIR.settap(i,c);
	MSPUC_FIR.settap(i,msc);
  }


  double expj,tmp;
  double arg = 0;

  spuc_new mspuc_i[MODSIZE];
  double ref_i[MODSIZE];

  for (i=0;i<MODSIZE;i++) {
	tmp    = AWGN.gauss();
	expj   = cos(arg);
	arg += phase;
	ref_i[i]    = expj+NOISE_GAIN*tmp;
	mspuc_i[i]    = ref_i[i];
  }

  double ref_time=1;

  std::cout << "Starting Loops with Loops = " << LOOPS << "\n";

  for (int sel=0;sel<2;sel++) {
	double time_start = get_time();
	int index=0;
	for (long loops=0;loops<LOOPS;loops++) {
	  index = (index+1)%MODSIZE;
	  switch (sel) {
	  case 0: ref = REF_FIR.update(ref_i[index]); break;
	  case 1: msc = MSPUC_FIR.update(mspuc_i[index]); break;
	  }

	}
	double time_end = get_time();

	switch (sel) {
	case 0: std::cout << "double   "; break;
	case 1: std::cout << "spuc_fp  "; break; 
	}

	std::cout << " Time elapsed = " << time_end - time_start << " ";

	if (sel==0) ref_time = (time_end-time_start);
	std::cout << " Factor = " << (time_end - time_start)/ref_time << "\n";
	
  }
  return 0;
}

