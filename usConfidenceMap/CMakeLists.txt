PROJECT(usConfidenceMapExample)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
	include_directories(${VISP_INCLUDE_DIRS})
ENDIF(VISP_FOUND)

ADD_EXECUTABLE(usConfidenceMapExample usConfidenceMapExample.cpp)
target_link_libraries(usConfidenceMapExample visp_ustk_core visp_ustk_io visp_ustk_confidence_map)
