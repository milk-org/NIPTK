#include <fitsio.h> 
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <malloc.h>
#include <math.h>
#include <stdlib.h>

#include "Cfits.h"
#include "COREMOD_memory/COREMOD_memory.h"
#include "COREMOD_arith/COREMOD_arith.h"
#include "fft/fft.h"
#include "image_gen/image_gen.h"
#include "WFpropagate/WFpropagate.h"
#include "statistic/statistic.h"
#include "linopt_imtools/linopt_imtools.h"
#include "OpticsMaterials/OpticsMaterials.h"
#include "PIAACMCsimul/PIAACMCsimul.h"

extern DATA data;

#define SBUFFERSIZE 2000


OPTSYST *optsyst;
int optsystinit = 0;
long IDx, IDy, IDr, IDPA;

SURFFIT *piaashapesfit; // analytical fit to piaa optics shapes


double LAMBDASTART = 0.6e-6;
double LAMBDAEND = 0.9e-6;





// CLI commands
//
// function CLI_checkarg used to check arguments
// 1: float
// 2: long
// 3: string
// 4: existing image
//

int PIAACMCsimul_run_cli()
{

  //  if(CLI_checkarg(1, 4)+CLI_checkarg(2, 3)+CLI_checkarg(3, 1)+CLI_checkarg(4, 1)+CLI_checkarg(5, 1)==0)
  //  {

  PIAACMCsimul_run();
  //data.cmdargtoken[1].val.string, data.cmdargtoken[2].val.string, data.cmdargtoken[3].val.numf, data.cmdargtoken[4].val.numf, data.cmdargtoken[5].val.numf);
  return 0;

  //  }
  //else
  // return 1;
}



int init_PIAACMCsimul()
{
  strcpy(data.module[data.NBmodule].name, __FILE__);
  strcpy(data.module[data.NBmodule].info, "PIAACMC system simulation");
  data.NBmodule++;
  


  strcpy(data.cmd[data.NBcmd].key,"piaacmcsimrun");
  strcpy(data.cmd[data.NBcmd].module,__FILE__);
  data.cmd[data.NBcmd].fp = PIAACMCsimul_run_cli;
  strcpy(data.cmd[data.NBcmd].info,"Simulate PIAACMC");
  strcpy(data.cmd[data.NBcmd].syntax,"no argument");
  strcpy(data.cmd[data.NBcmd].example,"piaacmcsimrun");
  strcpy(data.cmd[data.NBcmd].Ccall,"int PIAACMCsimul_run()");
  data.NBcmd++;
 
   
  // add atexit functions here
  atexit(PIAACMCsimul_free);

  return 0;

}






//
// make basis used to describe and fit PIAA shapes
//
// size        : mode map pixel size 
// radorder    : maximum radial order for radial modes
// korder      : maximum order for 2D kx,ky modes
// rad         : beam radius [pix]
// radfactlim  : overfilling factor; modes will be computed up to rad * radfactlim
// CPAstep     : cycles per aperture step
//  
/*long PIAACMCsimul_mksurfModes(char *ID_name, long size, double CPAmax1D, double CPAmax2D, double rad, double radfactlim, double CPAstep)
{
  long ID;
  long ii, jj, kk;
  long NBmodes;
  long ii1;
  long size2;
  double x, y, r;  
  int kx, ky;
  long k;

  float *CPAxarray;
  float *CPAyarray;
  float *CPArarray;
  long NBmax;


  NBmax = 0;
  for(CPAx=0;CPAx<CPAmax;CPAx+=deltaCPA)
    for(CPAy=-CPAmax;CPAy<CPAmax;CPAy+=deltaCPA)
      NBmax += 2;
  
  printf("NBmax = %ld\n", NBmax);
  fflush(stdout);
  
  CPAxarray = (float*) malloc(sizeof(float)*NBmax);
  CPAyarray = (float*) malloc(sizeof(float)*NBmax);
  CPArarray = (float*) malloc(sizeof(float)*NBmax);
  
  NBmax = 0;
  for(CPAx=0;CPAx<CPAmax;CPAx+=deltaCPA)
    for(CPAy=-CPAmax;CPAy<CPAmax;CPAy+=deltaCPA)
      {
	CPAxarray[NBmax] = CPAx;
	CPAyarray[NBmax] = CPAy;
	CPArarray[NBmax] = sqrt(CPAx*CPAx+CPAy*CPAy);
	NBmax ++;
      }

  printf("sorting\n");
  fflush(stdout);

  quick_sort3_float(CPArarray, CPAxarray, CPAyarray, NBmax);
  


  size2 = size*size;
  NBmodes = 1+2*(radorder-1) + 2*korder*2*korder-2;
  printf("size = %ld, %ld %ld -> %ld modes\n", size, radorder, korder, NBmodes);
  
  

  ID = create_3Dimage_ID(ID_name, size, size, NBmodes);


  
  for(ii=0;ii<size;ii++)
    for(jj=0;jj<size;jj++)
      {
	ii1 = jj*size+ii;
	x = (1.0*ii-0.5*size)/rad;
	y = (1.0*jj-0.5*size)/rad;
	r = sqrt(x*x+y*y);

	if(r<radfactlim)
	  {
	    kk = 0;
	    data.image[ID].array.F[kk*size2+ii1] = 1.0;
	    kk++;
	    
	    for(k=1;k<radorder;k++)
	      {
		data.image[ID].array.F[kk*size2+ii1] = cos(r*k*M_PI);
		kk++;
		data.image[ID].array.F[kk*size2+ii1] = sin(r*k*M_PI);
		kk++;
	      }
	    for(kx=0;kx<korder;kx++)
	      for(ky=-korder;ky<korder;ky++)
		{
		  if((kx!=0)||(ky!=0))
		    {
		      data.image[ID].array.F[kk*size2+ii1] =  cos(x*kx*M_PI+y*ky*M_PI);
		      kk++;
		      data.image[ID].array.F[kk*size2+ii1] =  sin(x*kx*M_PI+y*ky*M_PI);	    
		      kk++;
		    }
		}
	  }
      }

  return(ID);
}
*/
 /*
long PIAACMCsimul_surffit2map(SURFFIT *sfit, int surf, double rmax, char *ID_name)
{
  long ID;
  long size;
  long ii, jj;
  double x, y, r;
  double value;
  long k, kx, ky;
  

  size = optsyst[0].size;
  ID = create_2Dimage_ID(ID_name, size, size);
  
  
  for(k=0;k<SURFFIT_RADORDER;k++)
    printf("%d cos term %ld = %f\n", surf, k, sfit[surf].cosarray1D[k]);


  for(ii=0;ii<size;ii++)
    for(jj=0;jj<size;jj++)
      {
	value = 0.0;
	x = data.image[IDx].array.F[jj*size+ii];
	y = data.image[IDy].array.F[jj*size+ii];

	r = data.image[IDr].array.F[jj*size+ii];
	if(r<rmax)
	  {
	    for(k=0;k<SURFFIT_RADORDER;k++)
	      {
		value += sfit[surf].cosarray1D[k] * cos(r*k*M_PI);
		value += sfit[surf].sinarray1D[k] * sin(r*k*M_PI);
	      }
	    for(k=0;k<SURFFIT_2DCORRORDER*2*SURFFIT_2DCORRORDER;k++)
	      {
		kx = sfit[surf].array2D_kx[k];
		ky = sfit[surf].array2D_ky[k];
		value +=  sfit[surf].cosarray2D[k]*cos(kx*x*M_PI+ky*y*M_PI);
		value +=  sfit[surf].sinarray2D[k]*sin(kx*x*M_PI+ky*y*M_PI);	    
	      }
	    data.image[ID].array.F[jj*size+ii] = value;
	  }
      }
  
  return(ID);
}
 */



// makes 1-fpm CA
long PIAACMCsimul_mkFocalPlaneMask(char *IDname)
{
  long ID;
  long size;
  long nblambda;
  long k;
  long ii, jj;
  double x, y, r;

  size = optsyst[0].size;
  nblambda = optsyst[0].nblambda;

  ID = create_3DCimage_ID(IDname, size, size, nblambda);

  for(k=0;k<nblambda;k++)
    {
      for(ii=0;ii<size;ii++)
	for(jj=0;jj<size;jj++)
	  {
	    x = 1.0*ii-size/2;
	    y = 1.0*jj-size/2;	    
	    r = sqrt(x*x+y*y);
	    if (r<10.0)
	      {
		data.image[ID].array.CF[jj*size+ii].re = 2.0;
		data.image[ID].array.CF[jj*size+ii].im = 0.0;
	      }
	    else
	      {
		data.image[ID].array.CF[jj*size+ii].re = 0.0;
		data.image[ID].array.CF[jj*size+ii].im = 0.0;
	      }
	  }
    }

  return(ID);
}


//
// initializes the optsyst structure to simulate reflective PIAACMC system
//
void PIAACMCsimul_init( MIRRORPIAACMCDESIGN *design, long index )
{
  long k;
  long size;
  double x, y, PA;
  long ii, jj;
  long nblambda;
  long size2;
  double beamradpix;
  long kx, ky, kxy;
  long IDpiaaz0, IDpiaaz1;
  long surf;
  long IDa;
  char fname_pupa0[200];
  long ID;
  


  optsyst = (OPTSYST*) malloc(sizeof(OPTSYST));
  optsyst[0].nblambda = 3;
  nblambda = optsyst[0].nblambda;
  for(k=0;k<optsyst[0].nblambda;k++)
    optsyst[0].lambdaarray[k] = LAMBDASTART + (0.5+k)*(LAMBDAEND-LAMBDASTART)/optsyst[0].nblambda;


  optsyst[0].beamrad = design[index].beamrad; // 8mm
  optsyst[0].size = design[index].size;
  size = optsyst[0].size;
  size2 = size*size;
  optsyst[0].pixscale = design[index].pixscale;
  
  beamradpix = optsyst[0].beamrad/optsyst[0].pixscale;




  // define optical elements and locations
  optsyst[0].NB_DM = 0;
  optsyst[0].NB_asphsurfm = 2;
  optsyst[0].NB_asphsurfr = 0;
  
  optsyst[0].NBelem = 6; 


  // ------------------- elem 0: input pupil -----------------------
  optsyst[0].elemtype[0] = 1; // pupil mask
    // input pupil
  sprintf(fname_pupa0, "pupa0_%ld.fits", size);
  if(file_exists(fname_pupa0)==1)
    load_fits(fname_pupa0, "pupa0");
  IDa = image_ID("pupa0");
  if(IDa==-1)
    {
      printf("CREATING INPUT PUPIL\n");
      if(IDa!=-1)
	delete_image_ID("pupa0");
      IDa = create_3Dimage_ID("pupa0", size, size, nblambda);
            
      for(k=0;k<nblambda;k++)
	for(ii=0;ii<size2;ii++)
	  {
	    if((data.image[IDr].array.F[ii]>0.05)&&(data.image[IDr].array.F[ii]<1.0))
	      data.image[IDa].array.F[k*size2+ii] = 1.0;
	    else
	      data.image[IDa].array.F[k*size2+ii] = 0.0;
	  }     
      sprintf(fname_pupa0, "!pupa0_%ld.fits", size);
      save_fl_fits("pupa0", fname_pupa0);      
    }
  optsyst[0].elemarrayindex[0] = IDa;  
  optsyst[0].elemZpos[0] = 0.0;


 
  IDpiaaz0 = image_ID("piaa0z");
  IDpiaaz1 = image_ID("piaa1z");



  // ------------------- elem 1: reflective PIAA M1  -----------------------  
  optsyst[0].elemtype[1] = 3; // reflective PIAA M1   
  optsyst[0].elemarrayindex[1] = 0; // index
  optsyst[0]. ASPHSURFMarray[0].surfID = IDpiaaz0; 
  optsyst[0].elemZpos[1] = 0.0;



  // ------------------- elem 2: reflective PIAA M2  -----------------------  
  optsyst[0].elemtype[2] = 3; // reflective PIAA M2
  optsyst[0].elemarrayindex[2] = 1;
  optsyst[0]. ASPHSURFMarray[1].surfID = IDpiaaz1; 
  optsyst[0].elemZpos[2] = 0.5;



  // ------------------- elem 3: opaque mask at reflective PIAA M2  -----------------------  
  optsyst[0].elemtype[3] = 1; // reflective PIAA M2
  ID = make_disk("piaam2m", size, size, 0.5*size, 0.5*size, 1.5*beamradpix);
  optsyst[0].elemarrayindex[3] = ID;
  optsyst[0].elemZpos[3] = 0.5;


  
  // --------------------  elem 4: focal plane mask ------------------------
  optsyst[0].elemtype[4] = 5; // focal plane mask 
  optsyst[0].elemarrayindex[4] = 0;
  optsyst[0]. FOCMASKarray[0].fpmID = PIAACMCsimul_mkFocalPlaneMask("piaacmcfpm"); // this is 1-fpm
  optsyst[0]. FOCMASKarray[0].zfactor = 8.0;
  optsyst[0].elemZpos[4] = 0.0; // plane from which FT is done


  
  // --------------------  elem 5: Lyot mask ------------------------
  optsyst[0].elemtype[5] = 1; // Lyot mask 
  printf("CREATING LYOT MASK\n");
  IDa = create_3Dimage_ID("lmask", size, size, nblambda);
  
  for(k=0;k<nblambda;k++)
    for(ii=0;ii<size2;ii++)
      {
	if((data.image[IDr].array.F[ii]>0.00)&&(data.image[IDr].array.F[ii]<2.0))
	  data.image[IDa].array.F[k*size2+ii] = 1.0;
	else
	  data.image[IDa].array.F[k*size2+ii] = 0.0;
	  }     
  sprintf(fname_pupa0, "!LyotMask_%ld.fits", size);
  save_fl_fits("lmask", fname_pupa0);      

  optsyst[0].elemarrayindex[5] = IDa;  
  optsyst[0].elemZpos[5] = 0.0;

 

  optsystinit = 1;
}


void PIAACMCsimul_free( void )
{
  if(optsystinit ==1)
    {
      free(piaashapesfit);
      free(optsyst);
    }
}






int PIAACMCsimu_propoagateCube(char *IDin_amp_name, char *IDin_pha_name, char *IDout_amp_name, char *IDout_pha_name, double zprop)
{
  int kl;
  long ii;
  long size = optsyst[0].size;
  long size2;
  long IDin_amp, IDin_pha;
  long IDc_in, IDc_out;
  long IDout_amp, IDout_pha;
  
  double amp, pha, re, im;

  size2 = size*size;

  printf("propagating by %lf m\n", zprop);

  IDin_amp = image_ID(IDin_amp_name);
  IDin_pha = image_ID(IDin_pha_name);
  IDc_in = create_2DCimage_ID("tmppropCin", size, size);

  IDout_amp = create_3Dimage_ID(IDout_amp_name, size, size, optsyst[0].nblambda);
  IDout_pha = create_3Dimage_ID(IDout_pha_name, size, size, optsyst[0].nblambda);

  for(kl=0; kl<optsyst[0].nblambda; kl++)
    {
      printf("kl = %d / %d  %f\n", kl, optsyst[0].nblambda, optsyst[0].lambdaarray[kl]);
      for(ii=0;ii<size2;ii++)
	{
	  amp = data.image[IDin_amp].array.F[kl*size2+ii];
	  pha = data.image[IDin_pha].array.F[kl*size2+ii];
	  data.image[IDc_in].array.CF[ii].re = amp*cos(pha);
	  data.image[IDc_in].array.CF[ii].im = amp*sin(pha);
	}
      Fresnel_propagate_wavefront("tmppropCin", "tmppropCout", optsyst[0].pixscale, zprop, optsyst[0].lambdaarray[kl]);

      IDc_out = image_ID("tmppropCout");
      for(ii=0;ii<size2;ii++)
	{
	  re = data.image[IDc_out].array.CF[ii].re;
	  im = data.image[IDc_out].array.CF[ii].im;
	  amp = sqrt(re*re+im*im);
	  pha = atan2(im,re);
	  data.image[IDout_amp].array.F[kl*size2+ii] = amp;
	  data.image[IDout_pha].array.F[kl*size2+ii] = pha;
	}
      delete_image_ID("tmppropCout");
    }

  return 0;
}



//
// make PIAA shapes from radial sag profile
//
int PIAACMCsimul_mkPIAAMshapes_from_RadSag(char *fname, double radius_edge, char *ID_PIAAM1_name, char *ID_PIAAM2_name)
{
  FILE *fp;
  long size = optsyst[0].size;
  long ii, jj;
  long ID_PIAAM1, ID_PIAAM2;
 
  long nbpt = 20000;
  long k;

  double x, y, r, r1;

  double *r0array;
  double *z0array;
  double *r1array;
  double *z1array;

  double alpha;
  double r00, r01;
  double val;

  double beamradpix;
  int ret;

  beamradpix = optsyst[0].beamrad/ optsyst[0].pixscale;


  r0array = (double*) malloc(sizeof(double)*nbpt);
  z0array = (double*) malloc(sizeof(double)*nbpt);
  r1array = (double*) malloc(sizeof(double)*nbpt);
  z1array = (double*) malloc(sizeof(double)*nbpt);

  fp = fopen(fname, "r");
  for(k=0;k<nbpt;k++)
    ret = fscanf(fp,"%lf %lf %lf %lf\n", &r0array[k], &z0array[k], &r1array[k], &z1array[k]);
  fclose(fp);

  //  for(k=0;k<nbpt;k++)
  //  printf("%ld %.8lf %.8lf %.8lf %.8lf\n", k, r0array[k], z0array[k], r1array[k], z1array[k]);
  

   for(k=0;k<nbpt;k++)
     z1array[k] -= 1.0;
      
  

  ID_PIAAM1 = create_2Dimage_ID(ID_PIAAM1_name, size, size);
  ID_PIAAM2 = create_2Dimage_ID(ID_PIAAM2_name, size, size);
  
  printf("\n\n");
  for(ii=0;ii<size;ii++)
    {
      printf("\r %ld / %ld     ", ii, size);
      fflush(stdout);
      for(jj=0;jj<size;jj++)
	{
	  x = (1.0*ii-0.5*size)/beamradpix;
	  y = (1.0*jj-0.5*size)/beamradpix;
	  r = sqrt(x*x+y*y);
	  r1 = r * radius_edge;
	  if(r<2.0)
	    {
	      k = 1;
	      while((r0array[k]<r1)&&(k<nbpt-2))
		k++;
	      r00 = r0array[k-1];
	      r01 = r0array[k];
	      alpha = (r1-r00)/(r01-r00);
	      if(alpha>1.0)
		alpha = 1.0;
	      val = (1.0-alpha)*z0array[k-1] + alpha*z0array[k];
	      data.image[ID_PIAAM1].array.F[jj*size+ii] = val;
	      
	      k = 1;
	      while((r1array[k]<r1)&&(k<nbpt-2))
		k++;
	      r00 = r1array[k-1];
	      r01 = r1array[k];
	      alpha = (r1-r00)/(r01-r00);
	      if(alpha>1.0)
		alpha = 1.0;
	      val = (1.0-alpha)*z1array[k-1] + alpha*z1array[k];
	      data.image[ID_PIAAM2].array.F[jj*size+ii] = val;	
	    }
	}
    }
  printf("\n\n");

  free(r0array);
  free(z0array);
  free(r1array);
  free(z1array);

  return 0;
}





//
// Detailed simulation of PIAACMC
// 
// INPUT 
// 
//
// 
int PIAACMCsimul_run()
{
  long IDx, IDy, IDr, IDPA;
  double x, y;
  long IDa, IDp;
  long size;
  long nblambda;
  long size2;
  long ii, jj, k;
  long IDpiaa1z, IDpiaa2z;
  long elem;
  long kl;

  char fname_piaa1z[200];
  char fname_piaa2z[200];
  char fname_pupa0[200];
  char fname_pupp0[200];
  char fname[200];

  long ID;
  long index;

  double proplim = 1.0e-4;
  double total;

  MIRRORPIAACMCDESIGN *piaacmc;
  long NBpiaacmcdesign = 1;

  float beamradpix;
  long ID0, ID1;
  long size0, size1;


  printf("PIAACMC system simulation\n");

  size = 256;

  // x, y, r and PA coordinates in beam (for convenience & speed)
  IDx = create_2Dimage_ID("xcoord", size, size);
  IDy = create_2Dimage_ID("ycoord", size, size);
  IDr = create_2Dimage_ID("rcoord", size, size);
  IDPA = create_2Dimage_ID("PAcoord", size, size);
  for(ii=0; ii<size; ii++)
    for(jj=0; jj<size; jj++)
      {
	x = (1.0*ii-0.5*size)/beamradpix;
	y = (1.0*jj-0.5*size)/beamradpix;
	data.image[IDx].array.F[jj*size+ii] = x;
	data.image[IDy].array.F[jj*size+ii] = y;
	data.image[IDr].array.F[jj*size+ii] = sqrt(x*x+y*y);
	data.image[IDPA].array.F[jj*size+ii] = atan2(y,x);	
      }
  save_fl_fits("xcoord", "!xcoord.fits");
  save_fl_fits("ycoord", "!ycoord.fits");
  save_fl_fits("rcoord", "!rcoord.fits");
  save_fl_fits("PAcoord", "!PAcoord.fits");




  // allocate design struct array
  piaacmc = (MIRRORPIAACMCDESIGN*) malloc(sizeof(MIRRORPIAACMCDESIGN)*NBpiaacmcdesign);

  piaacmc[0].beamrad = 0.004; // 8mm
  piaacmc[0].size = size;
  piaacmc[0].pixscale = 0.0001;
  

  // create modes for aspheric optical surfaces description
  beamradpix = piaacmc[0].beamrad/piaacmc[0].pixscale;
  
  linopt_imtools_makeCosRadModes("Cmodes", (long) (beamradpix*4), 10, beamradpix, 2.0);
  piaacmc[0].CmodesID = image_ID("Cmodes");
  save_fits("Cmodes", "!Cmodes.fits");
  piaacmc[0].NBCmodes = data.image[ piaacmc[0].CmodesID].md[0].size[2];
  
  linopt_imtools_makeCPAmodes("Fmodes",  (long) (beamradpix*4), 5.0, 0.8, beamradpix, 2.0, 1);
  piaacmc[0].FmodesID = image_ID("Fmodes");
  save_fits("Fmodes", "!Fmodes.fits");
  piaacmc[0].NBFmodes = data.image[piaacmc[0].FmodesID].md[0].size[2];

  piaacmc[0].piaa0CmodesID = create_1Dimage_ID("piaa0Cmodes",piaacmc[0].NBCmodes );
  piaacmc[0].piaa0FmodesID = create_1Dimage_ID("piaa0Fmodes",piaacmc[0].NBFmodes );
  piaacmc[0].piaa1CmodesID = create_1Dimage_ID("piaa1Cmodes",piaacmc[0].NBCmodes );
  piaacmc[0].piaa1FmodesID = create_1Dimage_ID("piaa1Fmodes",piaacmc[0].NBFmodes );
  
  for(k=0;k<piaacmc[0].NBCmodes;k++)
    {
      data.image[piaacmc[0].piaa0CmodesID].array.F[k] = 1.0e-8*(0.5-ran1());
      data.image[piaacmc[0].piaa1CmodesID].array.F[k] = 1.0e-8*(0.5-ran1());
    }
 
  for(k=0;k<piaacmc[0].NBFmodes;k++)
    {
      data.image[piaacmc[0].piaa0FmodesID].array.F[k] = 1.0e-8*(0.5-ran1());
      data.image[piaacmc[0].piaa1FmodesID].array.F[k] = 0.0;
    }
 

  
  // assemble piaa0z and piaa1z images

  ID0 = linopt_imtools_image_construct("Cmodes", "piaa0Cmodes", "piaa0Cz");
  ID1 = linopt_imtools_image_construct("Fmodes", "piaa0Fmodes", "piaa0Fz");
  ID = create_2Dimage_ID("piaa0z", size, size);
  size0 = data.image[ID0].md[0].size[0];
  size1 = data.image[ID1].md[0].size[0];
  for(ii=0;ii<size0;ii++)
    for(jj=0;jj<size0;jj++)
      data.image[ID].array.F[(jj+(size-size0)/2)*size+(ii+(size-size0)/2)] += data.image[ID0].array.F[jj*size0+ii];
  for(ii=0;ii<size1;ii++)
    for(jj=0;jj<size1;jj++)
    data.image[ID].array.F[(jj+(size-size1)/2)*size+(ii+(size-size1)/2)] += data.image[ID1].array.F[jj*size1+ii];
  save_fits("piaa0Cz", "!piaa0Cz.fits");
  save_fits("piaa0Fz", "!piaa0Fz.fits");
  save_fits("piaa0z", "!piaa0z.fits");

  ID0 = linopt_imtools_image_construct("Cmodes", "piaa1Cmodes", "piaa1Cz");
  ID1 = linopt_imtools_image_construct("Fmodes", "piaa1Fmodes", "piaa1Fz");
  ID = create_2Dimage_ID("piaa1z", size, size);
  size0 = data.image[ID0].md[0].size[0];
  size1 = data.image[ID1].md[0].size[0];
  for(ii=0;ii<size0;ii++)
    for(jj=0;jj<size0;jj++)
      data.image[ID].array.F[(jj+(size-size0)/2)*size+(ii+(size-size0)/2)] += data.image[ID0].array.F[jj*size0+ii];
  for(ii=0;ii<size1;ii++)
    for(jj=0;jj<size1;jj++)
    data.image[ID].array.F[(jj+(size-size1)/2)*size+(ii+(size-size1)/2)] += data.image[ID1].array.F[jj*size1+ii];
  save_fits("piaa1Cz", "!piaa1Cz.fits");
  save_fits("piaa1Fz", "!piaa1Fz.fits");
  save_fits("piaa1z", "!piaa1z.fits");



  // initializes optical system to piaacmc design
  PIAACMCsimul_init(piaacmc, 0);
 






  
  // perform propagations


  
  size = optsyst[0].size;
  size2 = size*size;
  nblambda = optsyst[0].nblambda;


  
  // create base complex amplitude
  IDa = create_3Dimage_ID("WFamp", size, size, nblambda);
  IDp = create_3Dimage_ID("WFpha", size, size, nblambda);
  for(ii=0;ii<size2;ii++)
    for(kl=0;kl<nblambda;kl++)
      data.image[IDa].array.F[size2*kl+ii] = 1.0;
  

  for(elem=0; elem<optsyst[0].NBelem; elem++)
    {
      if( (elem>0) && (fabs(optsyst[0].elemZpos[elem]-optsyst[0].elemZpos[elem-1])>proplim) )
	{
	  printf("Propagating to element %ld  (%lf %lf)\n", elem,  optsyst[0].elemZpos[elem-1], optsyst[0].elemZpos[elem]);
	  PIAACMCsimu_propoagateCube("WFamp", "WFpha", "WFamp_prop", "WFpha_prop", optsyst[0].elemZpos[elem]-optsyst[0].elemZpos[elem-1]); 
	  delete_image_ID("WFamp");
	  delete_image_ID("WFpha");
	  chname_image_ID("WFamp_prop", "WFamp");
	  chname_image_ID("WFpha_prop", "WFpha");      
 	  IDa = image_ID("WFamp");
	  IDp = image_ID("WFpha");
	}
      else
	{
	  IDa = image_ID("WFamp");
	  IDp = image_ID("WFpha");
	}

      printf("Applying element %ld\n", elem);
      fflush(stdout);

      if(optsyst[0].elemtype[elem]==1)   // OPAQUE MASK
	{
	  printf("============= Opaque mask =================\n");
	  fflush(stdout);
	  ID = optsyst[0].elemarrayindex[elem];
	  for(ii=0;ii<size2;ii++)
	    for(kl=0;kl<nblambda;kl++)
	      data.image[IDa].array.F[size2*kl+ii] *= data.image[ID].array.F[ii];
	}

      if(optsyst[0].elemtype[elem]==3)  // MIRROR
	{
	  printf("============= Mirror =======================\n");
	  fflush(stdout);
	  ID = optsyst[0].ASPHSURFMarray[optsyst[0].elemarrayindex[elem]].surfID;
	  for(ii=0;ii<size2;ii++)
	    for(kl=0;kl<nblambda;kl++)
	      data.image[IDp].array.F[size2*kl+ii] += 2.0*M_PI*data.image[ID].array.F[ii]/optsyst[0].lambdaarray[kl];
	}


      if(optsyst[0].elemtype[elem]==5)  // FOCAL PLANE MASK
	{
	  printf("============= Focal Plane Mask ==============\n");
	  fflush(stdout);

	  mk_complex_from_amph("WFamp", "WFpha", "_WFctmp");
	  list_image_ID();
	  index = optsyst[0].elemarrayindex[elem];
	  ID = optsyst[0].FOCMASKarray[index].fpmID;

	  printf("focm : %s\n", data.image[ID].md[0].name);

	  fft_DFTinsertFPM("_WFctmp", data.image[ID].md[0].name, optsyst[0].FOCMASKarray[index].zfactor, "_WFcout");
	  arith_image_sub_inplace("_WFctmp", "_WFcout");
	  mk_amph_from_complex("_WFctmp", "WFamp", "WFpha");	  
	  delete_image_ID("_WFctmp");
	  delete_image_ID("_WFcout");	  
	}

      IDa = image_ID("WFamp");
      optsyst[0].flux[elem] = 0.0;
      for(kl=0;kl<nblambda;kl++)
	for(ii=0;ii<size2;ii++)
	  optsyst[0].flux[elem] += data.image[IDa].array.F[kl*size2+ii]*data.image[IDa].array.F[kl*size2+ii];

      printf("Element %ld   Flux = %lf\n", elem, optsyst[0].flux[elem]/nblambda);
      

      printf("Saving intermediate plane ... ");
      fflush(stdout);

      sprintf(fname, "!WFamp_%ld.fits", elem);
      save_fits("WFamp", fname);
      sprintf(fname, "!WFpha_%ld.fits", elem);
      save_fits("WFpha", fname);
 
      printf("done\n");
      fflush(stdout);
    }
  
  // Compute final focal plane image
  mk_complex_from_amph("WFamp", "WFpha", "_WFctmp");
  permut("_WFctmp");
  do2dfft("_WFctmp","_focc");
  delete_image_ID("_WFctmp");
  permut("_focc");
  mk_amph_from_complex("_focc", "psfa", "psfp");
  save_fits("psfa","!psfa.fits");
  save_fits("psfp","!psfp.fits");

  ID = image_ID("psfa");
  for(ii=0;ii<size2*nblambda;ii++)
    data.image[ID].array.F[ii] /= sqrt(size2*optsyst[0].flux[0]/nblambda);

  arith_image_mult("psfa", "psfa", "psfi");
  total = arith_image_total("psfi")/nblambda;
  printf("TOTAL = %lf\n", total);

  save_fits("psfi", "!psfi.fits");


  free(piaacmc);

  // PIAA shapes
  /*  sprintf(fname_piaa1z,"piaa1z_%ld.fits", size);
  if(file_exists(fname_piaa1z)==1)
    load_fits(fname_piaa1z, "piaa1z");
  sprintf(fname_piaa2z,"piaa2z_%ld.fits", size);
  if(file_exists(fname_piaa2z)==1)
    load_fits(fname_piaa2z, "piaa2z");
  IDpiaa1z = image_ID("piaa1z");
  IDpiaa2z = image_ID("piaa2z");
  
  if((IDpiaa1z==-1)||(IDpiaa2z==-1))
    {
      printf("CREATING PIAA SAGS\n");

      if(IDpiaa1z!=-1)
	delete_image_ID("piaa1z");

      if(IDpiaa2z!=-1)
	delete_image_ID("piaa2z");

      PIAACMCsimul_mkPIAAMshapes_from_RadSag("PIAA_Mshapes.txt", beamrad, "piaa1z", "piaa2z");

      sprintf(fname_piaa1z,"!piaa1z_%ld.fits", size);
      save_fl_fits("piaa1z", fname_piaa1z);
      sprintf(fname_piaa2z,"!piaa2z_%ld.fits", size);
      save_fl_fits("piaa2z", fname_piaa2z);      
      
      IDpiaa1z = image_ID("piaa1z");
      IDpiaa2z = image_ID("piaa2z");
    }
  

  
  PIAACMCsimu_propoagateCube("pupa0","pupp0", "pupa1", "pupp1", PIAAM1_Zpos); 
  delete_image_ID("pupa0");
  delete_image_ID("pupp0");


  save_fl_fits("pupa1", "!pupa1.fits");
  save_fl_fits("pupp1", "!pupp1.fits");
   
  */
  // ADD PIAA SHAPES
  /* printf("Adding PIAA shapes ... ");
  fflush(stdout);
  IDp = image_ID("pupp1");
  for(k=0; k<optsyst[0].nblambda; k++)
    {
      for(ii=0;ii<size2;ii++)
	data.image[IDp].array.F[k*size2+ii] -= 2.0 * 2.0*M_PI*data.image[IDpiaa1z].array.F[ii]/optsyst[0].lambdaarray[k];
    }
  printf("done\n");
  fflush(stdout);

  save_fl_fits("pupp1", "!pupp1b.fits");


  PIAACMCsimu_propoagateCube("pupa1", "pupp1", "pupa2", "pupp2", PIAAM2_Zpos-PIAAM1_Zpos); 
  delete_image_ID("pupa1");
  delete_image_ID("pupp1");
  save_fl_fits("pupa2", "!pupa2.fits");
  save_fl_fits("pupp2", "!pupp2.fits");

  IDp = image_ID("pupp2");
  for(k=0; k<optsyst[0].nblambda; k++)
    {
      for(ii=0;ii<size2;ii++)
	data.image[IDp].array.F[k*size2+ii] += 2.0 * 2.0*M_PI*data.image[IDpiaa2z].array.F[ii]/optsyst[0].lambdaarray[k];
    }

  save_fl_fits("pupp2", "!pupp2b.fits");



  list_image_ID();  
  */
  return(0);
}

