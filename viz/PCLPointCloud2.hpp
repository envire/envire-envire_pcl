#ifndef envire_pcl_PCLPointCloud2_H
#define envire_pcl_PCLPointCloud2_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <pcl/PCLPointCloud2.h>
#include <osg/Node>
#include <osg/Geometry>

namespace vizkit3d
{
    class PCLPointCloud2
        : public vizkit3d::Vizkit3DPlugin<pcl::PCLPointCloud2>
        , boost::noncopyable
    {
    Q_OBJECT
    Q_PROPERTY(QColor defaultFeatureColor READ getDefaultFeatureColor WRITE setDefaultFeatureColor)
    Q_PROPERTY(double pointSize READ getPointSize WRITE setPointSize)

    public:
        PCLPointCloud2();
        ~PCLPointCloud2();

    Q_INVOKABLE void updateData(pcl::PCLPointCloud2 const &sample)
    {vizkit3d::Vizkit3DPlugin<pcl::PCLPointCloud2>::updateData(sample);}

    public slots:
        QColor getDefaultFeatureColor();
        void setDefaultFeatureColor(QColor color);

        double getPointSize();
        void setPointSize(double size);

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(pcl::PCLPointCloud2 const& plan);
        
    private:
        struct Data;
        Data* p;

        osg::Vec4f default_feature_color;
        osg::ref_ptr<osg::Vec3Array> pointsOSG;
        osg::ref_ptr<osg::DrawArrays> drawArrays;
        osg::ref_ptr<osg::Geometry> pointGeom;
        osg::ref_ptr<osg::Vec4Array> color;
        bool newPoints;
    };
}
#endif
