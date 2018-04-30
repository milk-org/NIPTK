
// Choose one of the following:
// gcc -c -fPIC compute_pi.c -Ofast
// gcc -c compute_pi.c -fopenacc -foffload=nvptx-none -foffload="-O3" -Ofast
// pgcc -c -fPIC -fast compute_pi.c -ta=tesla:cc50 -Minfo=all
// pgcc -c -fPIC -fast compute_pi.c  



#include <stdio.h>
//#include <openacc.h>

#define N 2000000000

#define vl 1024


double compute_pi(void) {

  double pi = 0.0f;
  long long i;
	
//	acc_init(acc_device_nvidia);
//	printf("Number of devices: %d\n", acc_get_num_devices(acc_device_nvidia));

	// vector_length(vl) 

  #pragma acc parallel 
  #pragma acc loop reduction(+:pi)
  for (i=0; i<N; i++) {
    double t= (double)((i+0.5)/N);
    pi +=4.0/(1.0+t*t);
  }

	pi /= N;
  printf("pi=%11.10f\n",pi);

  return pi;
}
