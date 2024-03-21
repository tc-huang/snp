cmake_minimum_required(VERSION 3.5)
project(snp_automate_application)

# Default to C++17
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(ament_cmake REQUIRED)
find_package(snp_application REQUIRED)
find_package(motoros2_interfaces REQUIRED)
find_package(rviz_common REQUIRED)
find_package(pluginlib REQUIRED)

add_library(
  ${PROJECT_NAME}_widget SHARED
  src/snp_automate_widget.cpp
  src/bt/snp_automate_bt_ros_nodes.cpp
)
target_include_directories(
  ${PROJECT_NAME}_widget PUBLIC "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
                                "$<INSTALL_INTERFACE:include>")
target_link_libraries(${PROJECT_NAME}_widget Qt5::Widgets)
ament_target_dependencies(
  ${PROJECT_NAME}_widget
  motoros2_interfaces
  snp_application)

add_library(${PROJECT_NAME}_panel SHARED src/snp_automate_panel.cpp)
target_link_libraries(${PROJECT_NAME}_panel ${PROJECT_NAME}_widget)
ament_target_dependencies(${PROJECT_NAME}_panel rviz_common pluginlib)

# Install the headers
install(DIRECTORY include/${PROJECT_NAME} DESTINATION include/)

# Install the library(ies)
install(TARGETS ${PROJECT_NAME}_widget ${PROJECT_NAME}_panel EXPORT ${PROJECT_NAME}-targets DESTINATION lib)
ament_export_targets(${PROJECT_NAME}-targets HAS_LIBRARY_TARGET)

# Install MotoROS2 simulator
install(PROGRAMS scripts/motoros2_simulator.py DESTINATION lib/${PROJECT_NAME})

install(DIRECTORY config DESTINATION share/${PROJECT_NAME}/)

pluginlib_export_plugin_description_file(rviz_common plugin_description.xml)
ament_export_dependencies(
  snp_application
  motoros2_interfaces
  rviz_common
  pluginlib
)
ament_package()
