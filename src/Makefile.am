#SUFFIXES = .c .h .y .l

bin_PROGRAMS = nipTK
nipTK_SOURCES = CLImain.c CommandLineInterface/CLIcore.c CommandLineInterface/CLIcore.h CommandLineInterface/calc_bison.y CommandLineInterface/calc_flex.l CommandLineInterface/calc.h
nipTK_CPPFLAGS = -I@abs_top_srcdir@/src -DCONFIGDIR=\"@abs_top_srcdir@/config\" -DSOURCEDIR=\"@abs_top_srcdir@/src\" -DABSSRCTOPDIR=\"@abs_top_srcdir@\" -fopenmp -ldl

ACLOCAL_AMFLAGS = -I m4

## For Bison and FLEX
AM_YFLAGS = -d
AM_LFLAGS = -i 

## The contents of this variable are passed to every compilation that invokes the C preprocessor IF target_CPPFLAGS does not exit; it is a list of arguments to the preprocessor. For instance, -I and -D options should be listed here.
## AM_CPPFLAGS = -DCONFIGDIR=\"@abs_top_srcdir@/config\"

noinst_HEADERS = CommandLineInterface/calc.h

BUILT_SOURCES = CommandLineInterface/calc_bison.h


SUBDIRS = 
nipTK_LDADD = 


## Modules are built as libraries of convenience
## Linking order matters
## Core modules last, higher level modules at the top


SUBDIRS += cudacomp
nipTK_LDADD += cudacomp/libcudacomp.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/cudacomp

SUBDIRS += psf
nipTK_LDADD += psf/libpsf.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/psf

SUBDIRS += img_reduce
nipTK_LDADD += img_reduce/libimgreduce.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/img_reduce

SUBDIRS += image_format
nipTK_LDADD += image_format/libimageformat.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_format

SUBDIRS += ZernikePolyn
nipTK_LDADD += ZernikePolyn/libzernikepolyn.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/ZernikePolyn

SUBDIRS += image_basic
nipTK_LDADD += image_basic/libimagebasic.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_basic

SUBDIRS += image_filter
nipTK_LDADD += image_filter/libimagefilter.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_filter

SUBDIRS += image_gen
nipTK_LDADD += image_gen/libimagegen.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_gen

SUBDIRS += linopt_imtools
nipTK_LDADD += linopt_imtools/liblinoptimtools.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/linopt_imtools

SUBDIRS += statistic
nipTK_LDADD += statistic/libstatistic.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/statistic

SUBDIRS += info
nipTK_LDADD += info/libinfo.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/info

SUBDIRS += fft
nipTK_LDADD += fft/libfft.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/fft








## 
## CORE modules, should always be included
##



SUBDIRS += COREMOD_arith
nipTK_LDADD += COREMOD_arith/libcoremodarith.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_arith

SUBDIRS += COREMOD_memory
nipTK_LDADD += COREMOD_memory/libcoremodmemory.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_memory

SUBDIRS += COREMOD_iofits
nipTK_LDADD += COREMOD_iofits/libcoremodiofits.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_iofits

SUBDIRS += COREMOD_tools
nipTK_LDADD += COREMOD_tools/libcoremodtools.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_tools

SUBDIRS += 00CORE
nipTK_LDADD += 00CORE/lib00core.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/00CORE

SUBDIRS += ImageStreamIO
nipTK_LDADD += ImageStreamIO/libimagestreamio.la
nipTK_CPPFLAGS += -I@abs_top_srcdir@/src/ImageStreamIO
