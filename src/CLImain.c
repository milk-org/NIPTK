#include <stdio.h>
#include <stdlib.h>
#include <CommandLineInterface/CLIcore.h>


int main(int argc, char *argv[])
{
	char *AppName = "milk";

	runCLI(argc, argv, AppName);

	return 0;
}
