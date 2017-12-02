 
cmake_minimum_required (VERSION 2.8)
project(Structures)
#Version Numbers



set(OpenCV_PROJ CACHE FILEPATH ${CMAKE_CURRENT_LIST_FILE}/cmake)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin CACHE FILEPATH  "Build binary directory")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE FILEPATH "build static libs directory")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib CACHE FILEPATH "Build Dynamic Libs directory")


find_package(OpenCV REQUIRED PATHS OpenCV_PROJ)
find_package(Boost REQUIRED)

MESSAGE(STATUS "OpenCV Found = ${OpenCV_FOUND}")

if(${OpenCV_FOUND})
	MESSAGE(STATUS "OpenCV config file search path :${OpenCV_DIR}")
	MESSAGE(STATUS "OpenCV include DIR :${OpenCV_INCLUDE_DIRS}")
	MESSAGE(STATUS "OpenCV libraries :${OpenCV_LIBS}")
endif(${OpenCV_FOUND})


include_directories(
  include
  /usr/local/include
  ${Boost_INCLUDE_DIRS}
)

add_subdirectory(src)
