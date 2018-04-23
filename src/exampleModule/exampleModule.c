/**
 * @file    exampleModule.c
 * @brief   Example Module
 *  
 * Example module
 * Demonstrates custom compilation (separately from main package)
 * Creates shared object that can be loaded using milk's mload command
 * 
 * @author  O. Guyon
 * @date    2018-04-23
 *
 * Compilation 
 * Compile from milk/src/exampleModule directory
 * 
 * gcc -c -I.. -fPIC exampleModule.c
 * 
 * CHOOSE ONE:
 * gcc -c -fPIC compute_pi.c -Ofast
 * pgcc -c -fPIC -fast -acc compute_pi.c -ta=tesla:cc50 -Minfo=all
 * 
 * gcc -shared -I.. -fPIC exampleModule.o compute_pi.o -o libexamplemodule.so -lc
 * 
 * To automatically load the library, add sym link in lib directory:
 * cd ~/src/milk/lib
 * ln -s ../src/exampleModule/libexamplemodule.so libexamplemodule.so
 * 
 * To manually load within milk's CLI :
 * > soload "~/src/milk/src/exampleModule/libexamplemodule.so"
 * 
 * 
 */



#include <stdio.h>
#include <stdlib.h>


#include "CommandLineInterface/CLIcore.h"
// required for RegisterModule, data



#include "exampleModule/exampleModule.h"


static int INITSTATUS_exampleModule = 0;



void __attribute__ ((constructor)) libinit_exampleModule()
{
	if ( INITSTATUS_exampleModule == 0 )
	{
		init_exampleModule();
		RegisterModule(__FILE__, "exam", "Example Module");
		INITSTATUS_exampleModule = 1;
	}
}







int_fast8_t init_exampleModule()
{
	printf("Initializing user module exampleModule\n");
	printf("Testing: pi = %lf\n", compute_pi());
}



int free_exampleModule()
{
    return 0;
}

