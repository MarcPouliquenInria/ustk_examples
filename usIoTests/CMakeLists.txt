PROJECT(ustk_core_tests)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
	include_directories(${VISP_INCLUDE_DIRS})
	include_directories(${USTK_INCLUDE_DIR})	
ENDIF(VISP_FOUND)

ADD_EXECUTABLE(usPostscan2XmlParsing usPostscan2XmlParsing.cpp)
ADD_EXECUTABLE(usPrescan2DXmlParsing usPrescan2DXmlParsing.cpp)
target_link_libraries(usPostscan2XmlParsing visp_core visp_io visp_ustk_core visp_ustk_io)
target_link_libraries(usPrescan2DXmlParsing visp_core visp_io visp_ustk_core visp_ustk_io)
