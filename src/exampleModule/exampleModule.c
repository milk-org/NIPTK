/**
 * @file    exampleModule.c
 * @brief   Example Module
 *  
 * Example module
 * Demonstrates custom compilation (separately from main package)
 * Creates shared object that can be loaded using milk's mload command
 * This example illustrates use of openACC with pgi compiler
 * 
 * @author  O. Guyon
 * @date    2018-04-23
 *
 * Compilation 
 * Compile from milk/src/exampleModule directory
 * 
 * gcc -c -I.. -fPIC exampleModule.c
 * 
 * For non-accelerated code:
 * gcc -c -fPIC compute_pi.c -Ofast
 * 
 * Accelerated code:
 * pgcc -c -fPIC -fast -acc compute_pi.c -ta=tesla:nordc -Minfo=all
 * 
 * Add "-ta=tesla:nordc" to pgcc compilation. 
 * By default PGI uses runtime dynamic compilation (RDC) for the GPU code. 
 * However RDC requires an extra link step (with nvlink) that gcc does not support. 
 * The "nordc" sub-option disables RDC so you'll be able to use OpenACC code in a library. 
 * However by disabling RDC you can no longer call external device routines from a compute region.
 * 
 * Create shared object :
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

