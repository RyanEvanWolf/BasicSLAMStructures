#include "Structures/CameraInfo/SingleDistortion.hpp"

namespace stereo
{
	
SingleDistortion::SingleDistortion()
{
	distParam_=cv::Mat::zeros(0,4,CV_64FC1);
}

void SingleDistortion::read(const cv::FileNode& node)
{
	node["distortionParameters"]>>distParam_;
	node["RectifiedR"]>>RectR_;
	node["RegionOfInterest"]>>ROI_;
	node["undistortX"]>>undistort_mapx_;
	node["undistortY"]>>undistort_mapy_;
	node["undistortX_int"]>>undistort_mapx_int_;
	node["undistortY_int"]>>undistort_mapy_int_;
}

void SingleDistortion::write(cv::FileStorage& fs) const
{
	
	fs<<"{";
	fs<<"distortionParameters"<<distParam_;
	fs<<"RectifiedR"<<RectR_;
	fs<<"RegionOfInterest"<<ROI_;
	fs<<"undistortX"<<undistort_mapx_;
	fs<<"undistortY"<<undistort_mapy_;
	fs<<"undistortX_int"<<undistort_mapx_int_;
	fs<<"undistortY_int"<<undistort_mapy_int_;
	fs<<"}";
}


}