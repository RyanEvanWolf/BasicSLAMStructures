 
cmake_minimum_required (VERSION 2.8)
project(Structures)
#Version Numbers
##figure out which platform is being targeted

execute_process(COMMAND uname -m COMMAND tr -d '\n' OUTPUT_VARIABLE ARCHITECTURE)
set(OpenCV_PROJ CACHE FILEPATH ${CMAKE_CURRENT_LIST_FILE}/cmake)



if(${ARCHITECTURE} STREQUAL "x86_64")
  ##build against OpenCV 3
  find_package(OpenCV 3.0 REQUIRED)
else()
  find_package(OpenCV REQUIRED)
  ##link to tegra
  set(OpenCV_LIBS opencv_tegra)
  set(CUDA_USE_STATIC_CUDA_RUNTIME OFF)
endif()

message(STATUS "OpenCV version Found ${OpenCV_VERSION}")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE FILEPATH  "Build binary directory")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE FILEPATH "build static libs directory")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE FILEPATH "Build Dynamic Libs directory")


find_package(Boost REQUIRED)

include_directories(
  include
  /usr/local/include
  ${Boost_INCLUDE_DIRS}
)

add_subdirectory(src)


##create Config FILEPATH
#export(TARGETS BasicSLAMStructures
#  FILE "${PROJECT_BINARY_DIR}/BasicSLAMStructures.cmake")
  
#export(PACKAGE BasicSLAMStructures)

