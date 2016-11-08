project(sonosite)

cmake_minimum_required(VERSION 2.6)

find_package(VISP REQUIRED)
include_directories(${VISP_INCLUDE_DIRS})

set(example_cpp
#  tutorial-sonosite-grabber.cpp
#  tutorial-sonosite-confidence-map.cpp
  Viper850_test_FT_control_sensor_frame.cpp
  Viper850_test_FT_control_tool_frame.cpp
)

foreach(cpp ${example_cpp})
  visp_add_target(${cpp})
endforeach()


add_executable(tutorial-sonosite-grabber tutorial-sonosite-grabber.cpp)
target_link_libraries(tutorial-sonosite-grabber visp_gui visp_sensor visp_ustk_core)
#target_link_libraries(tutorial-sonosite-grabber ${VISP_LIBRARIES})

add_executable(tutorial-sonosite-confidence-map tutorial-sonosite-confidence-map.cpp)
target_link_libraries(tutorial-sonosite-confidence-map visp_gui visp_sensor visp_ustk_confidence_map)

add_executable(tutorial-sonosite-confidence-control tutorial-sonosite-confidence-control.cpp)
target_link_libraries(tutorial-sonosite-confidence-control visp_gui visp_sensor visp_robot visp_ustk_confidence_map)


