[![License: GPL v3](https://img.shields.io/badge/License-GPL%20v3-blue.svg)](http://www.gnu.org/licenses/gpl-3.0)
[![Build Status](https://travis-ci.org/niptk-org/NIPTK.svg?branch=master)](https://travis-ci.org/niptk-org/NIPTK)
[![Codacy Badge](https://api.codacy.com/project/badge/Grade/596968680753486e8146b764644a604c)](https://www.codacy.com/app/oguyon/Cfits?utm_source=github.com&amp;utm_medium=referral&amp;utm_content=oguyon/Cfits&amp;utm_campaign=Badge_Grade)


# Multi-purpose Imaging Libraries toolKit (MILK)

*Milk is the primary source of nutrition for infant mammals (Wikipedia)*

*Milk is used to prepare delicious drinks with cacao (CACAO-org dev team)*

## Overview

Set of image processing tools and functions accessible through a command line interface (CLI). Holds images in RAM, with image stream support (shared memory with low-latency IPC support).

Written in C, optimized for performance.

Executable launches a command line interface (CLI). Type "help" in the CLI to get started.


MILK is used by the following packages:

- Compute and Control for Adaptive Optics ([CACAO](https://github.com/CACAO-org/CACAO))
- Coronagraph Design ([FALCON](https://github.com/FALCON-orga/FALCON))
- Optics Propagation ([WOMAT](https://github.com/AtmoTurbu/WOMAT))
- Transit Light Curve ([TRANSIT](https://github.com/transitLC/TRANSIT))
- SCExAO instrument control ([SCExAO](https://github.com/SCExAO-RTS-org/SCExAO))
- future modules YOU can code



## Downloading and installing 


The MILK package follows the standard git clone steps and GNU build process :

	git clone https://github.com/milk-org/MILK
	cd MILK
	git submodule init
	git submodule update
	autoreconf -i
	./configure
	make
	make install

Note: On OS X you need to use gcc-mp-5 for openMP:

	./configure "CC=/opt/local/bin/gcc-mp-5" CPPFLAGS="-I/usr/include/malloc/ -I/opt/local/include/readline" LDFLAGS="-L/opt/local/lib/"
(Replace "/opt/local/" is the location of your installed libraries. )



## Reporting bugs, issues

Report bugs and issues on [this page]( https://github.com/milk-org/NIPTK/issues )


## Contributing to project


See [coding standards]( http://milk-org.github.io/NIPTK/html/page_coding_standards.html ) 





## Documentation

[Online documentation]( http://milk-org.github.io/MILK/ ) 


## Libraries

The following libraries are used:

- libtool
- automake
- readline, for reading the command line input
- ncurses-dev
- flex, for parsing the command line input
- bison, to interpret the command line input
- fftw, for performing Fourier Transforms
- gsl, for math functions and tools
- fitsio, for reading and writing FITS image files
- CUDA, CuBLAS, MAGMA for GPU acceleration (optional)

If you use NVIDIA GPUs, install cuda and magma libraries, and add "--enable-cuda and --enable-magma" options to the configure command.



## Getting Started

All functions are accessible from the command line interface (CLI). Enter the CLI and type "help" for instructions.

		./bin/milk


## LICENCE


[GNU General Public License v3.0]( https://github.com/milk-org/MILK/blob/master/LICENCE.txt )
