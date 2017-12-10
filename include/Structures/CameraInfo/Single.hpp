#ifndef CAMERA_INFO_SINGLE_HEADER_HPP
#define CAMERA_INFO_SINGLE_HEADER_HPP

#include "Structures/Transforms/Isometry.hpp"
#include "Structures/CameraInfo/SingleDistortion.hpp"
namespace stereo {

class Single
{
	private:
	public:
		Isometry  rectIso_;//isometry into the rectified coordinate frame
		Isometry  iso_;//Coordinate Transform from world to camera
		/*
		 * 		(WORLD SYSTEM)--->iso_----->(Camera Coordinate System)
		 * 
		 * 		therefore Xcam=(iso_^-1)Xworld
		 * */
		cv::Size imgResolution_;
		cv::Mat K_;
		cv::Mat idealP_;
		SingleDistortion D_;
		Single();
		~Single();
		Single(cv::Mat k,cv::Mat dist,Isometry is);
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);
		void printInternals();
	protected:
};

//These write and read functions must be defined for the serialization in FileStorage to work

static void read(const cv::FileNode& node, stereo::Single& x, const stereo::Single& default_value = stereo::Single()){
    if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::Single& x)
{
    x.write(fs);
}





}

#endif