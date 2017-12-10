#ifndef INTER_STEREO_FRAME_HEADER_HPP
#define INTER_STEREO_FRAME_HEADER_HPP

#include <Structures/Transforms/Isometry.hpp>

namespace stereo 
{
	
class InterStereoFrame 
{
	public:
		std::string startingFrame,endFrame;
		int totalMatches,totalInliers;
		Isometry interMotion;
		InterStereoFrame();
		void write(cv::FileStorage& fs) const;
		void read(const cv::FileNode& node);

	
};

static void read(const cv::FileNode& node, stereo::InterStereoFrame& x, const stereo::InterStereoFrame& default_value = stereo::InterStereoFrame()){
   if(node.empty())
	{
        x = default_value;
	}
    else
	{
        x.read(node);
	}
}

static void write(cv::FileStorage& fs, const std::string&, const stereo::InterStereoFrame& x)
{
    x.write(fs);
}


	
}

#endif
