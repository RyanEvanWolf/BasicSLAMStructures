#ifndef IMAGE_META_DATA_HEADER_HPP
#define IMAGE_META_DATA_HEADER_HPP

#include <iostream>
#include <opencv2/core.hpp>

namespace stereo
{
	
class ImageMetaData
{
	public:
		std::string fullDir_;
		std::string fileName_;
		int getTimeStamp() const;
		ImageMetaData();
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);
};
	

//These write and read functions must be defined for the serialization in FileStorage to work

static void read(const cv::FileNode& node, stereo::ImageMetaData& x, const stereo::ImageMetaData& default_value = stereo::ImageMetaData()){
    if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::ImageMetaData& x)
{
    x.write(fs);
}


}
	


#endif