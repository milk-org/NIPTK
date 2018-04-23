#ifndef _EXAMPLEMODULE_H
#define _EXAMPLEMODULE_H

void __attribute__ ((constructor)) libinit_exampleModule();

int_fast8_t init_exampleModule();

double compute_pi(void);

#endif

