rock_library(envire_pcl
    SOURCES PointCloud.cpp
    HEADERS PointCloud.hpp
    DEPS_CMAKE Boost
    DEPS_PKGCONFIG pcl_common-1.7 class_loader envire_core)
