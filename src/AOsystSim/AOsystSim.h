#ifndef _AOSYSTSIM_H
#define _AOSYSTSIM_H

long AOsystSim_mkTelPupDM(char *ID_name, long msize, double xc, double xy, double rin, double rout, double pupPA, double spiderPA, double spideroffset, double spiderthick);

long AOsystSim_fitTelPup(char *ID_name);

int init_AOsystSim();

int AOsystSim_run();

#endif
