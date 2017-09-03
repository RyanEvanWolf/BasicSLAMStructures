#ifndef STEREO_RECTIFIED_CAMERA_INFO_HEADER_
#define STEREO_RECTIFIED_CAMERA_INFO_HEADER_


#include "Structures/CameraInfo/Single.hpp"
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
/*only containing the essential information needed for a stereo rectified camera
 * configuration*/

namespace stereo
{

class StereoRect
{
	public:
		StereoRect();
		cv::Mat L_iMapx_,L_iMapy_;//fixed point rectification map
		cv::Mat R_iMapx_,R_iMapy_;//fixed point rectification map
		cv::Mat L_fMapx_,L_fMapy_;//float rectification map
		cv::Mat R_fMapx_,R_fMapy_;
		cv::Mat Qmap_;
		cv::Mat P_l_,P_r_;//ideal projection matrices
		cv::Rect l_ROI_,r_ROI_;
		Isometry lIso_,lrectIso_;
		Isometry rIso_,rrectIso_;
		//baselineInfo
		cv::Mat R_,T_;
		cv::Mat E_,F_;//essential and fundamental matrix
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);
};

//These write and read functions must be defined for the serialization in FileStorage to work

static void read(const cv::FileNode& node, stereo::StereoRect& x, const stereo::StereoRect& default_value = stereo::StereoRect()){
    if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::StereoRect& x)
{
    x.write(fs);
}


}

#endif