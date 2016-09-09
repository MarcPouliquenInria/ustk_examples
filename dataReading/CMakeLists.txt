PROJECT(dataReading)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
	include_directories(${VISP_INCLUDE_DIRS})
ENDIF(VISP_FOUND)

ADD_EXECUTABLE(prescan2D dataIoPrescan2D.cpp)
ADD_EXECUTABLE(postscan2D dataIoPostscan2D.cpp)
ADD_EXECUTABLE(postscan3D dataIoPostscan3D.cpp)
target_link_libraries(prescan2D visp_core visp_io visp_ustk_data visp_ustk_grabber visp_ustk_io)
target_link_libraries(postscan2D visp_core visp_io visp_ustk_data visp_ustk_grabber visp_ustk_io)
target_link_libraries(postscan3D visp_core visp_io visp_ustk_data visp_ustk_grabber visp_ustk_io)