#include "Structures/CameraInfo/StereoRect.hpp"

namespace stereo
{
	


StereoRect::StereoRect()
{

}


void StereoRect::read(const cv::FileNode& node)
{
	node["IdealLeft"]>>P_l_;
	node["ROI_Left"]>>l_ROI_;
	node["IdealRight"]>>P_r_;
	node["ROI_Right"]>>r_ROI_;
	node["Q_"]>>Qmap_;
	node["baseR"]>>R_;
	node["baseT"]>>T_;
	node["essential"]>>E_;
	node["fundamental"]>>F_;
	node["leftExtrinsic"]>>lIso_;
	node["leftRectExtrinsic"]>>lrectIso_;
	node["rightExtrinsic"]>>rIso_;
	node["rightRectExtrinsic"]>>rrectIso_;
  node["Kl"]>>Kl;
  node["Kr"]>>Kr;
  node["Dl"]>>Dl;
  node["Dr"]>>Dr;
  node["lrms"]>>lrms;
  node["rrms"]>>rrms;
  node["stereorms"]>>stereorms;
	node["LmapX_int"]>>L_iMapx_;
	node["LmapY_int"]>>L_iMapy_;
	node["LmapX_f"]>>L_fMapx_;
	node["LmapY_f"]>>L_fMapy_;
	node["RmapX_int"]>>R_iMapx_;
	node["RmapY_int"]>>R_iMapy_;
	node["RmapX_f"]>>R_fMapx_;
	node["RmapY_f"]>>R_fMapy_;
}


void StereoRect::write(cv::FileStorage& fs) const
{
	fs<<"{";
	fs<<"IdealLeft"<<P_l_;
	fs<<"ROI_Left"<<l_ROI_;
	fs<<"IdealRight"<<P_r_;
	fs<<"ROI_Right"<<r_ROI_;
	fs<<"Q_"<<Qmap_;
	fs<<"baseR"<<R_;
	fs<<"baseT"<<T_;
	fs<<"essential"<<E_;
	fs<<"fundamental"<<F_;
	fs<<"leftExtrinsic"<<lIso_;
	fs<<"leftRectExtrinsic"<<lrectIso_;
	fs<<"rightExtrinsic"<<rIso_;
	fs<<"rightRectExtrinsic"<<rrectIso_;
  fs<<"Kl"<<Kl;
  fs<<"Kr"<<Kr;
  fs<<"Dl"<<Dl;
  fs<<"Dr"<<Dr;
  fs<<"lrms"<<lrms;
  fs<<"rrms"<<rrms;
  fs<<"stereorms"<<stereorms;
	fs<<"LmapX_int"<<L_iMapx_;
	fs<<"LmapY_int"<<L_iMapy_;
	fs<<"LmapX_f"<<L_fMapx_;
	fs<<"LmapY_f"<<L_fMapy_;
	fs<<"RmapX_int"<<R_iMapx_;
	fs<<"RmapY_int"<<R_iMapy_;
	fs<<"RmapX_f"<<R_fMapx_;
	fs<<"RmapY_f"<<R_fMapy_;
	fs<<"}";

}
	
}