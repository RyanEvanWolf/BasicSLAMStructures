#include "Structures/DataSet/ImageMetaData.hpp"

namespace stereo {

ImageMetaData::ImageMetaData()
{

}

int ImageMetaData::getTimeStamp() const
{
	//TODO
//	std::string numberString;
//	numberString=fileName_.substr(0,fileName_.length()-4);
	//std::cout<<fileName_<<" "<<numberString<<std::endl;
//	return std::stoi(numberString);
	return 0;
}

void ImageMetaData::read(const cv::FileNode& node)
{
	node["fullImageDirectory"]>>fullDir_;
	node["fileName"]>>fileName_;
}


void ImageMetaData::write(cv::FileStorage& fs) const
{
	fs<<"{";
	fs<<"fullImageDirectory"<<fullDir_;
	fs<<"fileName"<<fileName_;
	fs<<"}";
}



	
}