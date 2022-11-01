# CMakeLists.txt has to be located in the project folder and cmake has to be
# executed from 'project/build' with 'cmake ../'.
cmake_minimum_required(VERSION 3.3)

find_package(Rock)
find_package(PluginManager)
rock_init(envire_pcl 0.1)
rock_standard_layout()
