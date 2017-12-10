#include "Structures/vSLAM/InterStereoFrame.hpp"

namespace stereo {

InterStereoFrame::InterStereoFrame()
{
	startingFrame="-1";
	endFrame="-2";
	totalMatches=-1;
	totalInliers=-1;
	
}

void InterStereoFrame::read(const cv::FileNode& node)
{
	node["startFrame"]>>startingFrame;
	node["endFrame"]>>endFrame;
	node["delta"]>>interMotion;
	node["inliers"]>>totalInliers;
	node["matches"]>>totalMatches;
}


void InterStereoFrame::write(cv::FileStorage& fs) const
{
	fs<<"{";
	fs<<"startFrame"<<startingFrame;
	fs<<"endFrame"<<endFrame;
	fs<<"delta"<<interMotion;
	fs<<"inliers"<<totalInliers;
	fs<<"matches"<<totalMatches;
	fs<<"}";
}






}