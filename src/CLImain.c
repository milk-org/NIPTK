#include <stdio.h>
#include <stdlib.h>
#include <CommandLineInterface/CLIcore.h>

#define STYLE_BOLD    "\033[1m"
#define STYLE_NO_BOLD "\033[22m"


int main(int argc, char *argv[])
{
	char *AppName = "milk";

	printf(STYLE_BOLD);
	printf("\n        Multi-purpose Imaging Libraries toolKit (milk)\n");
	printf(STYLE_NO_BOLD);

	runCLI(argc, argv, AppName);

	return 0;
}
