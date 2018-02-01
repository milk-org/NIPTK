#include <stdio.h>
#include <stdlib.h>
#include <CommandLineInterface/CLIcore.h>



#include <image_basic/image_basic.h>
#include <image_format/image_format.h>
#include <img_reduce/img_reduce.h>
#include <psf/psf.h>
#include <ZernikePolyn/ZernikePolyn.h>



#define STYLE_BOLD    "\033[1m"
#define STYLE_NO_BOLD "\033[22m"


int main(int argc, char *argv[])
{
	char *AppName = "milk";

	printf(STYLE_BOLD);
	printf("\n        Multi-purpose Imaging Libraries toolKit (milk)\n");
	printf(STYLE_NO_BOLD);
	
	
	
	// initialize milk modules for which no function calls is included by default
	libinit_image_basic();
	libinit_image_format();
	libinit_psf();
	libinit_img_reduce();
	libinit_ZernikePolyn();

	runCLI(argc, argv, AppName);

	return 0;
}
