
set(TRANSFORMS_SRC "Isometry.cpp")
set(TRANSFORMS_HEADERS "Isometry.hpp")
set(REL_TRANSFORMS_SRC "Transforms/Isometry.cpp")

set(CAMERA_INFO_SRC "Single.cpp;SingleDistortion.cpp;StereoRect.cpp")
set(CAMERA_INFO_HEADERS "Single.hpp;SingleDistortion.hpp")
set(REL_CAMERA_INFO_SRC "CameraInfo/Single.cpp;CameraInfo/SingleDistortion.cpp;CameraInfo/StereoRect.cpp")

set(OUTPUT_DATA_SRC "ImageDetections.cpp;StereoFrame.cpp;StereoFrameStats.cpp;StereoKP.cpp")
set(OUTPUT_DATA_HEADERS "ImageDetections.hpp;OutputData.hpp;StereoFrame.hpp;StereoFrameStats.hpp;StereoKP.hpp")
set(REL_OUTPUT_DATA_SRC "OutputData/ImageDetections.cpp;OutputData/StereoFrame.cpp;OutputData/StereoFrameStats.cpp;OutputData/StereoKP.cpp;OutputData/SalientFeature.cpp")

set(DATASET_SRC "BumbleDataSet.cpp;BumbleFrame.cpp;ImageMetaData.cpp")
set(DATASET_HEADERS "BumbleDataSet.hpp;BumbleFrame.hpp;ImageMetaData.hpp")
set(REL_DATASET_SRC "DataSet/BumbleDataSet.cpp;DataSet/BumbleFrame.cpp;DataSet/ImageMetaData.cpp")

set(vSLAM_SRC vSLAM/StereoFrame.cpp vSLAM/StereoFeatures.cpp vSLAM/InterStereoFrame.cpp)


set(RELDATA_SRCS "${REL_TRANSFORMS_SRC};${REL_CAMERA_INFO_SRC};${REL_DATASET_SRC};${vSLAM_SRC}")

add_library(BasicSLAMStructures SHARED
	${RELDATA_SRCS}
)

target_link_libraries(BasicSLAMStructures
    ${OpenCV_LIBS}
	boost_filesystem
	boost_system
	)
	
add_executable(displayData ${CMAKE_CURRENT_LIST_DIR}/DataSet/bin/DisplayDataSet.cpp)
target_link_libraries(displayData BasicSLAMStructures)

