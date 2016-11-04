project(sonosite)

cmake_minimum_required(VERSION 2.6)

find_package(VISP REQUIRED)
include_directories(${VISP_INCLUDE_DIRS})

add_executable(tutorial-sonosite-grabber tutorial-sonosite-grabber.cpp)
target_link_libraries(tutorial-sonosite-grabber visp_gui visp_sensor visp_ustk_core)

add_executable(tutorial-sonosite-confidence-map tutorial-sonosite-confidence-map.cpp)
target_link_libraries(tutorial-sonosite-confidence-map visp_gui visp_sensor visp_ustk_confidence_map)

#target_link_libraries(tutorial-sonosite-grabber visp_ustk_core visp_ustk_io visp_ustk_confidence_map)
