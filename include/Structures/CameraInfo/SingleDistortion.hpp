#ifndef CAMERA_INFO_SINGLE_DISTORTION_HPP
#define CAMERA_INFO_SINGLE_DISTORTION_HPP

#include <opencv2/core.hpp>

namespace stereo {
	


//#include "Structures/Transforms/Isometry.hpp"
	
class SingleDistortion
{
	private:

	public:
		cv::Mat distParam_;
		cv::Mat undistort_mapx_;//distortionMapping
		cv::Mat undistort_mapy_;
		cv::Mat undistort_mapx_int_;
		cv::Mat undistort_mapy_int_;
		cv::Mat RectR_;
		cv::Rect ROI_;
		SingleDistortion();
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);
	protected:

};

//These write and read functions must be defined for the serialization in FileStorage to work

static void read(const cv::FileNode& node, stereo::SingleDistortion& x, const stereo::SingleDistortion& default_value = stereo::SingleDistortion()){
    if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::SingleDistortion& x)
{
    x.write(fs);
}








	
}

#endif