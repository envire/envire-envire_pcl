#include <iostream>
#include "PCLPointCloud2.hpp"

using namespace vizkit3d;

struct PCLPointCloud2::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    pcl::PCLPointCloud2 data;
};


PCLPointCloud2::PCLPointCloud2()
    : p(new Data)
{
}

PCLPointCloud2::~PCLPointCloud2()
{
    delete p;
}

osg::ref_ptr<osg::Node> PCLPointCloud2::createMainNode()
{
    // Geode is a common node used for vizkit3d plugins. It allows to display
    // "arbitrary" geometries
    return new osg::Geode();
}

void PCLPointCloud2::updateMainNode ( osg::Node* node )
{
    osg::Geode* geode = static_cast<osg::Geode*>(node);
    // Update the main node using the data in p->data
}

void PCLPointCloud2::updateDataIntern(pcl::PCLPointCloud2 const& value)
{
    p->data = value;
    std::cout << "got new sample data" << std::endl;
}

//Macro that makes this plugin loadable in ruby, this is optional.
VizkitQtPlugin(PCLPointCloud2)

