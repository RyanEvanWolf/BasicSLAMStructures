#include "Structures/CameraInfo/Single.hpp"

namespace stereo
{
	
Single::Single()
{
	iso_.setIdentity();
}

Single::Single(cv::Mat k,cv::Mat dist,Isometry is)
{
	k.copyTo(K_);
	dist.copyTo(D_.distParam_);
	iso_=is;
}


Single::~Single()
{
	//K_.release();
	//K_dist_.release();
}


void Single::printInternals()
{
	std::cout<<"K: "<<K_<<std::endl;
	std::cout<<"Distortion: "<<D_.distParam_<<std::endl;
	std::cout<<"IdealProjection: "<<idealP_<<std::endl;
	std::cout<<"ImageSize: "<<imgResolution_<<std::endl;
	std::cout<<"ROI : "<<D_.ROI_<<std::endl;
	std::cout<<"World Coordinate System to Camera Coordinate System\n";
	iso_.printH();
	std::cout<<"World Coordinate System to Rectified Coordinate System\n";
	rectIso_.printH();

}


	

//input output xml functions

void Single::read(const cv::FileNode& node)
{

	node["intrinsics"]>>K_;
	node["idealProjection"]>>idealP_;
	node["ImageSize"]>>imgResolution_;
	node["Extrinsic"]>>iso_;
	node["Distortion"]>>D_;

}

void Single::write(cv::FileStorage& fs) const
{
	fs<<"{";
	fs<<"intrinsics"<<K_;
	fs<<"idealProjection"<<idealP_;
	fs<<"ImageSize"<<imgResolution_;
	fs<<"Extrinsic"<<iso_;
	fs<<"Distortion"<<D_;
	fs<<"}";
}





}