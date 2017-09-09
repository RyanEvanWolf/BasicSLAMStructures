

#include "Structures/DataSet/BumbleDataSet.hpp"
 
 int main(int argc, char *argv [])
 {
	using namespace stereo;
	std::string inputDataSetDir;
    
	if(argc==2)
	{
		//use the command line arguments
		inputDataSetDir=std::string(argv[1]);
	}
	else
	{
		std::cerr << std::endl << "Incorrect Number of Parameters -example usage -->" << std::endl;
	    std::cerr <<"./displayDataSet [datasetDirectory]" << std::endl;
	    std::cerr <<"./displayDataSet" << std::endl;
        return 1;
	}
	
	//create all the possible variations of the fastDetector
	
	//initialize the BumbleBee dataset and camera
	BumbleDataSet bumbleData(inputDataSetDir);
	
	bool end=false;
	
	
	int im=0;
	cv::namedWindow("l",cv::WINDOW_NORMAL);
	cv::namedWindow("r",cv::WINDOW_NORMAL);
	while(!end)
	{
		
		cv::imshow("l",bumbleData.getCurrentLeft());
		cv::imshow("r",bumbleData.getCurrentRight());

		end= !bumbleData.incrementFrame();
		std::cout<<im<<std::endl;
		im++;
		cv::waitKey(1);
	}
	cv::destroyAllWindows();
	return 0;
 }