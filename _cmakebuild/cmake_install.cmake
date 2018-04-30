# Install script for directory: /data1/src/milk

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/data1/src/milk/_install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

if(NOT CMAKE_INSTALL_COMPONENT OR "${CMAKE_INSTALL_COMPONENT}" STREQUAL "Unspecified")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/bin" TYPE EXECUTABLE FILES "/data1/src/milk/_build/milk")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk"
         OLD_RPATH "/data1/src/milk/_build/src/ImageStreamIO:/data1/src/milk/_build/src/00CORE:/data1/src/milk/_build/src/COREMOD_arith:/data1/src/milk/_build/src/COREMOD_iofits:/data1/src/milk/_build/src/COREMOD_memory:/data1/src/milk/_build/src/COREMOD_tools:/data1/src/milk/_build/src/info:/data1/src/milk/_build/src/fft:/data1/src/milk/_build/src/statistic:/data1/src/milk/_build/src/linopt_imtools:/data1/src/milk/_build/src/image_gen:/data1/src/milk/_build/src/image_filter:/data1/src/milk/_build/src/image_basic:/data1/src/milk/_build/src/ZernikePolyn:/data1/src/milk/_build/src/image_format:/data1/src/milk/_build/src/img_reduce:/data1/src/milk/_build/src/psf:/data1/src/milk/_build/src/cudacomp:/data1/src/milk/_build/src/kdtree:/data1/src/milk/_build/src/linARfilterPred:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/bin/milk")
    endif()
  endif()
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/data1/src/milk/_build/src/ImageStreamIO/cmake_install.cmake")
  include("/data1/src/milk/_build/src/00CORE/cmake_install.cmake")
  include("/data1/src/milk/_build/src/COREMOD_arith/cmake_install.cmake")
  include("/data1/src/milk/_build/src/COREMOD_iofits/cmake_install.cmake")
  include("/data1/src/milk/_build/src/COREMOD_memory/cmake_install.cmake")
  include("/data1/src/milk/_build/src/COREMOD_tools/cmake_install.cmake")
  include("/data1/src/milk/_build/src/info/cmake_install.cmake")
  include("/data1/src/milk/_build/src/fft/cmake_install.cmake")
  include("/data1/src/milk/_build/src/statistic/cmake_install.cmake")
  include("/data1/src/milk/_build/src/linopt_imtools/cmake_install.cmake")
  include("/data1/src/milk/_build/src/image_gen/cmake_install.cmake")
  include("/data1/src/milk/_build/src/image_filter/cmake_install.cmake")
  include("/data1/src/milk/_build/src/image_basic/cmake_install.cmake")
  include("/data1/src/milk/_build/src/ZernikePolyn/cmake_install.cmake")
  include("/data1/src/milk/_build/src/image_format/cmake_install.cmake")
  include("/data1/src/milk/_build/src/img_reduce/cmake_install.cmake")
  include("/data1/src/milk/_build/src/psf/cmake_install.cmake")
  include("/data1/src/milk/_build/src/cudacomp/cmake_install.cmake")
  include("/data1/src/milk/_build/src/kdtree/cmake_install.cmake")
  include("/data1/src/milk/_build/src/linARfilterPred/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/data1/src/milk/_build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
