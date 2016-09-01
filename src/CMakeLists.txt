find_package(PCL 1.7 REQUIRED COMPONENTS common)

rock_library(envire_pcl
    SOURCES PointCloud.cpp
    HEADERS PointCloud.hpp
    DEPS_CMAKE Boost
    DEPS_PKGCONFIG pcl_common-${PCL_VERSION_MAJOR}.${PCL_VERSION_MINOR} class_loader envire_core)

install_plugin_info(envire_pcl)
