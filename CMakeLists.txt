# run from _cmakebuild directory :
# cmake .. -DCMAKE_INSTALL_PREFIX=../_install

cmake_minimum_required (VERSION 3.5)

project (milk C)

# Version number
set ( VERSION_MAJOR 0 )
set ( VERSION_MINOR 1 )
set ( VERSION_PATCH 01 )



# Configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/src/Config.h.in"
  "${PROJECT_SOURCE_DIR}/src/Config.h"
  )



# PERFORMANCE ORIENTED COMPILING OPTIONS

# Adds options to the compiler command line for targets in the current directory and below that are added after this command is invoked
add_compile_options(-std=gnu11)
add_compile_options(-Ofast)
add_compile_options(-march=native)

# runs the standard link-time optimizer
add_compile_options(-flto)


# OpenMP
find_package(OpenMP)
if (OPENMP_FOUND)
message("Found OpenMP")
add_compile_options(-fopenmp)
endif()

message("COMPILE_OPTIONS:  ${COMPILE_OPTIONS}")


# A common flag is -pipe. This flag has no effect on the generated code, but it makes the compilation process faster. It tells the compiler to use pipes instead of temporary files during the different stages of compilation, which uses more memory. On systems with low memory, GCC might get killed. In those cases do not use this flag. 
add_compile_options(-pipe)





# options
option(USE_CUDA  "Use CUDA library"  OFF)
option(USE_MAGMA "Use MAGMA library" OFF)


# MAGMA (optional)
if(USE_MAGMA)
set(USE_CUDA ON)
endif(USE_MAGMA)



if(USE_CUDA)
find_package( CUDA REQUIRED )
endif(USE_CUDA)

if(USE_MAGMA)
find_package(PkgConfig REQUIRED)
pkg_check_modules(MAGMA REQUIRED magma)
message(STATUS ${MAGMA_LIBRARY_DIRS})
link_directories( ${MAGMA_LIBRARY_DIRS} )
endif(USE_MAGMA)


# ncurses
SET(CURSES_USE_NCURSES TRUE)






message("====================================================")
message("VERSION  ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")
message("====================================================")

message("PROJECT_SOURCE_DIR       = ${PROJECT_SOURCE_DIR}")
message("PROJECT_BINARY_DIR       = ${PROJECT_BINARY_DIR}")

message("USE_CUDA                 = ${USE_CUDA}")

message("USE_MAGMA                = ${USE_MAGMA}")
if(USE_MAGMA)
message("   MAGMA_LIBRARIES       = ${MAGMA_LIBRARIES}")
endif(USE_MAGMA)

message("EXTRAMODULES             = ${EXTRAMODULES}")

message("====================================================")




#                               
# recursively add libraries to be compiled
# each library compile as SHARED
#
add_subdirectory ( "src/ImageStreamIO" )
add_subdirectory ( "src/CommandLineInterface" )
add_subdirectory ( "src/00CORE" )
add_subdirectory ( "src/COREMOD_arith" )
add_subdirectory ( "src/COREMOD_iofits" )
add_subdirectory ( "src/COREMOD_memory" )
add_subdirectory ( "src/COREMOD_tools" )
add_subdirectory ( "src/info" )
add_subdirectory ( "src/fft" )
add_subdirectory ( "src/statistic" )
add_subdirectory ( "src/linopt_imtools" )
add_subdirectory ( "src/image_gen" )
add_subdirectory ( "src/image_filter" )
add_subdirectory ( "src/image_basic" )
add_subdirectory ( "src/ZernikePolyn" )
add_subdirectory ( "src/image_format" )
add_subdirectory ( "src/img_reduce" )
add_subdirectory ( "src/psf" )
add_subdirectory ( "src/cudacomp" )
add_subdirectory ( "src/kdtree" )
add_subdirectory ( "src/linARfilterPred" ) 


#
# Add extra optional modules (list provided by user)
# separator character ";"
#

FOREACH(extramodule ${EXTRAMODULES})
add_subdirectory ( "src/${extramodule}" )
ENDFOREACH()




# main
add_executable(milk 
src/CLImain.c)

target_include_directories(milk PUBLIC
${PROJECT_SOURCE_DIR}/src
${GSL_INCLUDE_DIRS}
${FFTW_INCLUDE_DIRS}
${FFTWF_INCLUDE_DIRS}
${CURSES_INCLUDE_DIR}
)

# adds the options to all targets within the directory and its sub-directories
target_compile_options(milk PUBLIC 
${FFTW_CFLAGS_OTHER}
${FFTWF_CFLAGS_OTHER}
-fopenmp
)


set(BUILD_FLAGS "-DPACKAGE_NAME=\\\"milk\\\" -DPACKAGE_VERSION=\\\"0.0.0\\\" -DCONFIGDIR=\\\"${PROJECT_SOURCE_DIR}/config\\\" -DSOURCEDIR=\\\"${PROJECT_SOURCE_DIR}\\\" -DABSSRCTOPDIR=\\\"${PROJECT_SOURCE_DIR}\\\" -DPACKAGE_BUGREPORT=\\\"https://github.com/milk-org/milk/issues\\\"" )




target_link_libraries (milk PUBLIC
CLIcore 
00CORE 
COREMOD_arith 
COREMOD_memory 
ImageStreamIO 
COREMOD_tools 
info 
fft
linopt_imtools 
image_basic
COREMOD_iofits 
ZernikePolyn
image_filter
image_gen
statistic
image_format 
img_reduce 
psf 
cudacomp 
kdtree 
linARfilterPred
${EXTRAMODULES}
m
readline
ncurses
cfitsio
dl
rt
${GSL_LIBRARIES} 
${FFTW_LIBRARIES}
${FFTWF_LIBRARIES}
${CMAKE_THREAD_LIBS_INIT}
-fopenmp
)


if(USE_MAGMA)
target_link_libraries (milk PUBLIC ${MAGMA_LIBRARIES})
set_target_properties(milk PROPERTIES COMPILE_FLAGS "-DHAVE_CUDA -DHAVE_MAGMA")
endif(USE_MAGMA)

set_target_properties(milk PROPERTIES COMPILE_FLAGS "${BUILD_FLAGS}" )


message("====================================================")
get_target_property(milkcompopts milk COMPILE_OPTIONS)

message("BUILD_FLAGS    :  ${BUILD_FLAGS}")
message("COMPILE_OPTIONS:  ${milkcompopts}")
message("CMAKE_EXE_LINKER_FLAGS  :  ${CMAKE_EXE_LINKER_FLAGS}")
message("====================================================")




install(TARGETS milk DESTINATION bin)
