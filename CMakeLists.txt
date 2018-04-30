# run from _cmakebuild directory :
# cmake .. -DCMAKE_INSTALL_PREFIX=../_install

cmake_minimum_required (VERSION 3.1)
project (milk)

# option example
option(USE_IMAGE_BASIC
	"Use module image_basic" ON)

include_directories ("${PROJECT_SOURCE_DIR}/src")


# libraries
add_subdirectory ( "src/ImageStreamIO" )
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
add_executable(milk src/CLImain.c)
target_link_libraries (milk ImageStreamIO 00CORE COREMOD_arith COREMOD_iofits COREMOD_memory COREMOD_tools info fft statistic linopt_imtools image_gen image_filter image_basic ZernikePolyn image_format img_reduce psf cudacomp kdtree linARfilterPred)

install(TARGETS milk DESTINATION bin)
