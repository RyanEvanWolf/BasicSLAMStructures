#ifndef STEREO_FEATURES_VSLAM_HEADER_HPP
#define STEREO_FEATURES_VSLAM_HEADER_HPP

#include <opencv2/features2d.hpp>
#include "Structures/DataSet/ImageMetaData.hpp"

namespace stereo 
{
class StereoFeatures 
{
	public:
		StereoFeatures();
		std::string detectionSettings_;
		ImageMetaData frameData_;
		std::vector<cv::KeyPoint> leftFeatures,rightFeatures;
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);
};

//These write and read functions must be defined for the serialization in FileStorage to work

static void read(const cv::FileNode& node, stereo::StereoFeatures& x, const stereo::StereoFeatures& default_value = stereo::StereoFeatures()){
    if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::StereoFeatures& x)
{
    x.write(fs);
}
	
	
}

#endif