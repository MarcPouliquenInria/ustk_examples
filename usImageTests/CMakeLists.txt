PROJECT(ustk_core_tests)

CMAKE_MINIMUM_REQUIRED(VERSION 2.6)

FIND_PACKAGE(VISP REQUIRED)
IF(VISP_FOUND)
	include_directories(${VISP_INCLUDE_DIRS})
	include_directories(${USTK_INCLUDE_DIR})
	 #include_directories("C:\Users\mpouliqu\Documents\sources codes\USTK\ustk\modules\ustk_data\include")
	 #include_directories("C:\Users\mpouliqu\Documents\sources codes\USTK\ustk\modules\ustk_grabber\include")
	 #include_directories("C:\Users\mpouliqu\Documents\sources codes\USTK\ustk\modules\ustk_io\include")
	
ENDIF(VISP_FOUND)

ADD_EXECUTABLE(usPrescan2D usPrescan2D.cpp)
ADD_EXECUTABLE(usPostscan2D usPostscan2D.cpp)
ADD_EXECUTABLE(usRF2D usRF2D.cpp)
target_link_libraries(usPrescan2D visp_core visp_io visp_ustk_core)
target_link_libraries(usPostscan2D visp_core visp_io visp_ustk_core)
target_link_libraries(usRF2D visp_core visp_io visp_ustk_core)