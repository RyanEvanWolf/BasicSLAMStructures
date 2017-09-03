#include "Structures/vSLAM/StereoFeatures.hpp"

namespace stereo 
{
StereoFeatures::StereoFeatures()
{

}
	
void StereoFeatures::read(const cv::FileNode& node)
{
	node["ImageMetaData"]>>frameData_;
	node["detectionSettings_"]>>detectionSettings_;
	
	cv::FileNodeIterator meas_it,meas_end;
	cv::KeyPoint tempIn;
	
	
	meas_it=node["leftFeatures"].begin();
	meas_end=node["leftFeatures"].end();
	for(;meas_it!=meas_end;++meas_it)
	{
		(*meas_it)["point"]>>tempIn.pt;
		(*meas_it)["size"]>>tempIn.size;
		(*meas_it)["angle"]>>tempIn.angle;
		(*meas_it)["response"]>>tempIn.response;
		(*meas_it)["octave"]>>tempIn.octave;
		(*meas_it)["id"]>>tempIn.class_id;
		leftFeatures.push_back(tempIn);
	}
	
	meas_it=node["rightFeatures"].begin();
	meas_end=node["rightFeatures"].end();
	for(;meas_it!=meas_end;++meas_it)
	{
		(*meas_it)["point"]>>tempIn.pt;
		(*meas_it)["size"]>>tempIn.size;
		(*meas_it)["angle"]>>tempIn.angle;
		(*meas_it)["response"]>>tempIn.response;
		(*meas_it)["octave"]>>tempIn.octave;
		(*meas_it)["id"]>>tempIn.class_id;
		rightFeatures.push_back(tempIn);
	}

	
}


void StereoFeatures::write(cv::FileStorage& fs) const
{
	fs<<"{";
	fs<<"ImageMetaData"<<frameData_;
	fs<<"detectionSettings_"<<detectionSettings_;
	fs<<"leftFeatures"<<"[";
	for(int index=0;index<leftFeatures.size();index++)
	{
		fs<<"{";
			fs<<"point"<<leftFeatures.at(index).pt;
			fs<<"size"<<leftFeatures.at(index).size;
			fs<<"angle"<<leftFeatures.at(index).angle;
			fs<<"response"<<leftFeatures.at(index).response;
			fs<<"octave"<<leftFeatures.at(index).octave;
			fs<<"id"<<leftFeatures.at(index).class_id;
		fs<<"}";
	}
	fs<<"]";
	fs<<"rightFeatures"<<"[";
	for(int index=0;index<rightFeatures.size();index++)
	{
		fs<<"{";
			fs<<"point"<<rightFeatures.at(index).pt;
			fs<<"size"<<rightFeatures.at(index).size;
			fs<<"angle"<<rightFeatures.at(index).angle;
			fs<<"response"<<rightFeatures.at(index).response;
			fs<<"octave"<<rightFeatures.at(index).octave;
			fs<<"id"<<rightFeatures.at(index).class_id;
		fs<<"}";
	}
	fs<<"]";
	
	fs<<"}";
}

	
}