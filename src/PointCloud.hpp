//
// Copyright (c) 2015, Deutsches Forschungszentrum für Künstliche Intelligenz GmbH.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#pragma once

#include <pcl/PCLPointCloud2.h>
#include <boost/serialization/nvp.hpp>
#include <boost/serialization/vector.hpp>


namespace boost { namespace serialization {

    template<class Archive>
    void serialize(Archive & ar, ::pcl::PCLPointCloud2 & pointcloud, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("header", pointcloud.header);
        ar & boost::serialization::make_nvp("height", pointcloud.height);
        ar & boost::serialization::make_nvp("width", pointcloud.width);
        ar & boost::serialization::make_nvp("fields", pointcloud.fields);
        ar & boost::serialization::make_nvp("is_bigendian", pointcloud.is_bigendian);
        ar & boost::serialization::make_nvp("point_step", pointcloud.point_step);
        ar & boost::serialization::make_nvp("row_step", pointcloud.row_step);
        ar & boost::serialization::make_nvp("data", pointcloud.data);
        ar & boost::serialization::make_nvp("is_dense", pointcloud.is_dense);
    }

    template<class Archive>
    void serialize(Archive & ar, ::pcl::PCLHeader & header, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("seq", header.seq);
        ar & boost::serialization::make_nvp("stamp", header.stamp);
        ar & boost::serialization::make_nvp("frame_id", header.frame_id);
    }

    template<class Archive>
    void serialize(Archive & ar, ::pcl::PCLPointField & field, const unsigned int version)
    {
        ar & boost::serialization::make_nvp("name", field.name);
        ar & boost::serialization::make_nvp("offset", field.offset);
        ar & boost::serialization::make_nvp("datatype", field.datatype);
        ar & boost::serialization::make_nvp("count", field.count);
    }

}}
