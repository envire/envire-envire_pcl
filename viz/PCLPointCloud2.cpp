#include <iostream>
#include "PCLPointCloud2.hpp"

#include <osg/Geode>
#include <osg/Point>

#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/conversions.h>


using namespace vizkit3d;

const double DEFAULT_POINT_SIZE = 2.0;

struct PCLPointCloud2::Data {
    // Copy of the value given to updateDataIntern.
    //
    // Making a copy is required because of how OSG works
    pcl::PCLPointCloud2 data;
};


PCLPointCloud2::PCLPointCloud2()
    : p(new Data)
{
    newPoints = false;
    default_feature_color = osg::Vec4f(1.0f, 1.0f, 1.0f, 1.0f);
}

PCLPointCloud2::~PCLPointCloud2()
{
    delete p;
}

osg::ref_ptr<osg::Node> PCLPointCloud2::createMainNode()
{
    osg::ref_ptr<osg::Group> mainNode = new osg::Group();

    // set up point cloud
    pointGeom = new osg::Geometry;
    pointsOSG = new osg::Vec3Array;
    pointGeom->setVertexArray(pointsOSG);
    color = new osg::Vec4Array;
    pointGeom->setColorArray(color);
    pointGeom->setColorBinding(osg::Geometry::BIND_PER_VERTEX);
    pointGeom->getOrCreateStateSet()->setMode(GL_LIGHTING, osg::StateAttribute::OFF); 
    drawArrays = new osg::DrawArrays( osg::PrimitiveSet::POINTS, 0, pointsOSG->size() );
    pointGeom->addPrimitiveSet(drawArrays.get());

    osg::ref_ptr<osg::Geode> geode = new osg::Geode;
    geode->addDrawable(pointGeom.get());
    mainNode->addChild(geode);
    setPointSize(DEFAULT_POINT_SIZE);
    return mainNode;
}

void PCLPointCloud2::updateMainNode ( osg::Node* node )
{
    if(newPoints)
    {
        //convert pc2 to pc

        pcl::PointCloud<pcl::PointXYZ> pointCloud;
        pcl::fromPCLPointCloud2(p->data,pointCloud );
        

        newPoints = false;
        pointsOSG->clear();
        color->clear();
        //bool use_colors = pointCloud.colors.size() == pointCloud.points.size();
        for(size_t i=0; i<pointCloud.points.size(); i++)
        {
            osg::Vec3d vec(pointCloud.points[i].x, pointCloud.points[i].y, pointCloud.points[i].z);
            pointsOSG->push_back(vec);
            // if(use_colors)
            // {
            //     color->push_back(osg::Vec4f(pointCloud.colors[i][0], pointCloud.colors[i][1], pointCloud.colors[i][2], pointCloud.colors[i][3]));
            // }else{
                color->push_back(default_feature_color);
            // }
        }
        drawArrays->setCount(pointsOSG->size());
        pointGeom->setVertexArray(pointsOSG);
        pointGeom->setColorArray(color);
    }
}

void PCLPointCloud2::updateDataIntern(pcl::PCLPointCloud2 const& value)
{
    p->data = value;
    newPoints = true;
    std::cout << std::endl << "got new sample data" << std::endl << std::endl;
}

QColor PCLPointCloud2::getDefaultFeatureColor()
{
    QColor color;
    color.setRgbF(default_feature_color.x(), default_feature_color.y(), default_feature_color.z(), default_feature_color.w());
    return color;
}

void PCLPointCloud2::setDefaultFeatureColor(QColor color)
{
    default_feature_color.x() = color.redF();
    default_feature_color.y() = color.greenF();
    default_feature_color.z() = color.blueF();
    default_feature_color.w() = color.alphaF();
    emit propertyChanged("defaultFeatureColor");
}

void PCLPointCloud2::setPointSize(double size)
{
    if(pointGeom.valid())
    {
        if(size <= 0.0)
            size = 0.01;
        osg::ref_ptr<osg::Point> pt = new osg::Point(size);
        pointGeom->getOrCreateStateSet()->setAttribute(pt, osg::StateAttribute::ON);
    }
    emit propertyChanged("pointSize");
}

double PCLPointCloud2::getPointSize()
{
    if(pointGeom.valid())
    {
        osg::Point *pt = dynamic_cast<osg::Point*>(pointGeom->getOrCreateStateSet()->getAttribute(osg::StateAttribute::POINT));
        if(pt)
            return pt->getSize();
    }
    return DEFAULT_POINT_SIZE;
}




//Macro that makes this plugin loadable in ruby, this is optional.
VizkitQtPlugin(PCLPointCloud2)

