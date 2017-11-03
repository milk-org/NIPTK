#SUFFIXES = .c .h .y .l

bin_PROGRAMS = cfitsTK
cfitsTK_SOURCES = CLIcore.c CLIcore.h CommandLineInterface/calc_bison.y CommandLineInterface/calc_flex.l CommandLineInterface/calc.h
cfitsTK_CPPFLAGS = -I@abs_top_srcdir@/src -DCONFIGDIR=\"@abs_top_srcdir@/config\" -DSOURCEDIR=\"@abs_top_srcdir@/src\" -DABSSRCTOPDIR=\"@abs_top_srcdir@\" -fopenmp -ldl

ACLOCAL_AMFLAGS = -I m4

## For Bison and FLEX
AM_YFLAGS = -d
AM_LFLAGS = -i 

## The contents of this variable are passed to every compilation that invokes the C preprocessor IF target_CPPFLAGS does not exit; it is a list of arguments to the preprocessor. For instance, -I and -D options should be listed here.
## AM_CPPFLAGS = -DCONFIGDIR=\"@abs_top_srcdir@/config\"

noinst_HEADERS = CommandLineInterface/calc.h

BUILT_SOURCES = CommandLineInterface/calc_bison.h


SUBDIRS = 
cfitsTK_LDADD = 


## Modules are built as libraries of convenience
## Linking order matters
## Core modules last, higher level modules at the top


SUBDIRS += cudacomp
cfitsTK_LDADD += cudacomp/libcudacomp.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/cudacomp

SUBDIRS += psf
cfitsTK_LDADD += psf/libpsf.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/psf

SUBDIRS += img_reduce
cfitsTK_LDADD += img_reduce/libimgreduce.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/img_reduce

SUBDIRS += image_format
cfitsTK_LDADD += image_format/libimageformat.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_format

SUBDIRS += ZernikePolyn
cfitsTK_LDADD += ZernikePolyn/libzernikepolyn.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/ZernikePolyn

SUBDIRS += image_basic
cfitsTK_LDADD += image_basic/libimagebasic.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_basic

SUBDIRS += image_filter
cfitsTK_LDADD += image_filter/libimagefilter.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_filter

SUBDIRS += image_gen
cfitsTK_LDADD += image_gen/libimagegen.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/image_gen

SUBDIRS += linopt_imtools
cfitsTK_LDADD += linopt_imtools/liblinoptimtools.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/linopt_imtools

SUBDIRS += statistic
cfitsTK_LDADD += statistic/libstatistic.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/statistic

SUBDIRS += info
cfitsTK_LDADD += info/libinfo.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/info

SUBDIRS += fft
cfitsTK_LDADD += fft/libfft.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/fft








## 
## CORE modules, should always be included
##



SUBDIRS += COREMOD_arith
cfitsTK_LDADD += COREMOD_arith/libcoremodarith.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_arith

SUBDIRS += COREMOD_memory
cfitsTK_LDADD += COREMOD_memory/libcoremodmemory.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_memory

SUBDIRS += COREMOD_iofits
cfitsTK_LDADD += COREMOD_iofits/libcoremodiofits.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_iofits

SUBDIRS += COREMOD_tools
cfitsTK_LDADD += COREMOD_tools/libcoremodtools.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_tools

SUBDIRS += 00CORE
cfitsTK_LDADD += 00CORE/lib00core.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/00CORE

SUBDIRS += ImageStreamIO
cfitsTK_LDADD += ImageStreamIO/libimagestreamio.la
cfitsTK_CPPFLAGS += -I@abs_top_srcdir@/src/ImageStreamIO
