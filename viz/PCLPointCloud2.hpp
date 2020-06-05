#ifndef envire_pcl_PCLPointCloud2_H
#define envire_pcl_PCLPointCloud2_H

#include <boost/noncopyable.hpp>
#include <vizkit3d/Vizkit3DPlugin.hpp>
#include <osg/Geode>
#include <pcl/PCLPointCloud2.h>

namespace vizkit3d
{
    class PCLPointCloud2
        : public vizkit3d::Vizkit3DPlugin<pcl::PCLPointCloud2>
        , boost::noncopyable
    {
    Q_OBJECT
    public:
        PCLPointCloud2();
        ~PCLPointCloud2();

    Q_INVOKABLE void updateData(pcl::PCLPointCloud2 const &sample)
    {vizkit3d::Vizkit3DPlugin<pcl::PCLPointCloud2>::updateData(sample);}

    protected:
        virtual osg::ref_ptr<osg::Node> createMainNode();
        virtual void updateMainNode(osg::Node* node);
        virtual void updateDataIntern(pcl::PCLPointCloud2 const& plan);
        
    private:
        struct Data;
        Data* p;
    };
}
#endif
