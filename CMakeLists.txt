# run from _cmakebuild directory :
# cmake .. -DCMAKE_INSTALL_PREFIX=../_install

cmake_minimum_required (VERSION 3.1)
project (milk C)

# options
option(USE_CUDA  "Use CUDA library"  OFF)
option(USE_MAGMA "Use MAGAM library" OFF)


message("====================================================")
message("PROJECT_SOURCE_DIR  = ${PROJECT_SOURCE_DIR}")
message("USE_CUDA            = ${USE_CUDA}")
message("USE_MAGMA           = ${USE_MAGMA}")
message("====================================================")



if(USE_CUDA)
find_package( CUDA REQUIRED )
endif(USE_CUDA)

if(USE_MAGMA)
find_package(PkgConfig REQUIRED)
pkg_check_modules(MAGMA REQUIRED magma)
message(STATUS ${MAGMA_LIBRARY_DIRS})
link_directories( ${MAGMA_LIBRARY_DIRS} )
endif(USE_MAGMA)


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

target_compile_options(milk PUBLIC 
${FFTW_CFLAGS_OTHER}
${FFTWF_CFLAGS_OTHER}
-fopenmp)



set_target_properties(milk PROPERTIES COMPILE_FLAGS "-DPACKAGE_NAME=\\\"milk\\\" -DPACKAGE_VERSION=\\\"0.0.0\\\" -DCONFIGDIR=\\\"${PROJECT_SOURCE_DIR}/config\\\" -DSOURCEDIR=\\\"${PROJECT_SOURCE_DIR}\\\" -DABSSRCTOPDIR=\\\"${PROJECT_SOURCE_DIR}\\\" -DPACKAGE_BUGREPORT=\\\"me@me.com\\\"" )


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
m
readline
cfitsio
dl
rt
gomp
${GSL_LIBRARIES} 
${FFTW_LIBRARIES}
${FFTWF_LIBRARIES}
${CMAKE_THREAD_LIBS_INIT}
${CURSES_LIBRARIES})


if(USE_MAGMA)
target_link_libraries (milk PUBLIC ${MAGMA_LIBRARIES})
set_target_properties(milk PROPERTIES COMPILE_FLAGS "-DHAVE_CUDA -DHAVE_MAGMA")
endif(USE_MAGMA)

install(TARGETS milk DESTINATION bin)
