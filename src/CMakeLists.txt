find_package(PCL 1.8 REQUIRED COMPONENTS common)
IF("${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR}" VERSION_LESS 1.14)
    SET(PCL_VERSION_SUFFIX "-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR}")
ENDIF()

# Default to C++14 (PCL requirement)
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

rock_library(envire_pcl
    SOURCES PointCloud2.cpp PointCloudXYZ.cpp
    HEADERS PointCloud2.hpp PointCloudXYZ.hpp
    DEPS_PKGCONFIG pcl_common${PCL_VERSION_SUFFIX} envire_core)

install_plugin_info(envire_pcl)
