PROJECT(usPostscan3DMHDReader)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
	include_directories(${VISP_INCLUDE_DIRS})
	include_directories(${USTK_INCLUDE_DIR})	
ENDIF(VISP_FOUND)

ADD_EXECUTABLE(usPostscan3DMHDReader usPostscan3DMHDReader.cpp)
target_link_libraries(usPostscan3DMHDReader visp_core visp_io visp_ustk_core visp_ustk_io)