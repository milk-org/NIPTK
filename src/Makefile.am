#SUFFIXES = .c .h .y .l

bin_PROGRAMS = milk
milk_SOURCES = CLImain.c CommandLineInterface/CLIcore.c CommandLineInterface/CLIcore.h CommandLineInterface/calc_bison.y CommandLineInterface/calc_flex.l CommandLineInterface/calc.h
milk_CPPFLAGS = -I@abs_top_srcdir@/src -DCONFIGDIR=\"@abs_top_srcdir@/config\" -DSOURCEDIR=\"@abs_top_srcdir@/src\" -DABSSRCTOPDIR=\"@abs_top_srcdir@\" -fopenmp -ldl

ACLOCAL_AMFLAGS = -I m4

## For Bison and FLEX
AM_YFLAGS = -d
AM_LFLAGS = -i 

## The contents of this variable are passed to every compilation that invokes the C preprocessor IF target_CPPFLAGS does not exit; it is a list of arguments to the preprocessor. For instance, -I and -D options should be listed here.
## AM_CPPFLAGS = -DCONFIGDIR=\"@abs_top_srcdir@/config\"

noinst_HEADERS = CommandLineInterface/calc.h

BUILT_SOURCES = CommandLineInterface/calc_bison.h


SUBDIRS = 
milk_LDADD = 


## Modules are built as libraries of convenience
## Linking order matters
## Core modules last, higher level modules at the top


SUBDIRS += cudacomp
milk_LDADD += cudacomp/libcudacomp.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/cudacomp

SUBDIRS += psf
milk_LDADD += psf/libpsf.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/psf

SUBDIRS += img_reduce
milk_LDADD += img_reduce/libimgreduce.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/img_reduce

SUBDIRS += image_format
milk_LDADD += image_format/libimageformat.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/image_format

SUBDIRS += ZernikePolyn
milk_LDADD += ZernikePolyn/libzernikepolyn.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/ZernikePolyn

SUBDIRS += image_basic
milk_LDADD += image_basic/libimagebasic.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/image_basic

SUBDIRS += image_filter
milk_LDADD += image_filter/libimagefilter.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/image_filter

SUBDIRS += image_gen
milk_LDADD += image_gen/libimagegen.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/image_gen

SUBDIRS += linopt_imtools
milk_LDADD += linopt_imtools/liblinoptimtools.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/linopt_imtools

SUBDIRS += statistic
milk_LDADD += statistic/libstatistic.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/statistic

SUBDIRS += info
milk_LDADD += info/libinfo.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/info

SUBDIRS += fft
milk_LDADD += fft/libfft.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/fft








## 
## CORE modules, should always be included
##



SUBDIRS += COREMOD_arith
milk_LDADD += COREMOD_arith/libcoremodarith.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_arith

SUBDIRS += COREMOD_memory
milk_LDADD += COREMOD_memory/libcoremodmemory.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_memory

SUBDIRS += COREMOD_iofits
milk_LDADD += COREMOD_iofits/libcoremodiofits.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_iofits

SUBDIRS += COREMOD_tools
milk_LDADD += COREMOD_tools/libcoremodtools.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/COREMOD_tools

SUBDIRS += 00CORE
milk_LDADD += 00CORE/lib00core.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/00CORE

SUBDIRS += ImageStreamIO
milk_LDADD += ImageStreamIO/libimagestreamio.la
milk_CPPFLAGS += -I@abs_top_srcdir@/src/ImageStreamIO
