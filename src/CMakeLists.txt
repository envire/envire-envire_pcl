find_package(PCL 1.8 REQUIRED COMPONENTS common)

# Default to C++14 (PCL requirement)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

rock_library(envire_pcl
    SOURCES PointCloud.cpp
    HEADERS PointCloud.hpp
    DEPS_PKGCONFIG pcl_common-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR} class_loader_melodic envire_core)

install_plugin_info(envire_pcl)
