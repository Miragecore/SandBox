#include "openMVG/features/feature.hpp"
#include "openMVG/features/sift/SIFT_Anatomy_Image_Describer.hpp"

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include <memory>
#include <string>

int main(int argc, char*arcv[])
{
  std::string desc_type = "SIFT";
    
  cv::Mat img_cv1, img_cv2;
  cv::Mat tmp;
  
  tmp = imread(argv[1], IMREAD_UNCHANGED);
  cv::cvtColor(tmp, img_cv1, CV_BGR2GRAY);
  tmp = imread(argv[2], IMREAD_UNCHANGED);
  cv::cvtColor(tmp, img_cv2, CV_BGR2GRAY);

  openMVG::Image<uint8_t> img_mvg1, img_mvg2;;
  cv::cv2eigen(img_cv1, *(openMVG::Image<uint8_t>::Base*)&img_mvg1);
  cv::cv2eigen(img_cv2, *(openMVG::Image<uint8_t>::Base*)&img_mvg2);

  using namespace openMVG::features;
  std::unique_ptr<Image_describer> image_describer;
  if (sImage_describer_type == "SIFT")
    image_describer.reset(new SIFT_Anatomy_Image_describer(SIFT_Anatomy_Image_describer::Params()));
  else if (sImage_describer_type == "AKAZE")
    image_describer = AKAZE_Image_describer::create
      (AKAZE_Image_describer::Params(AKAZE::Params(), AKAZE_MSURF));
  else if (sImage_describer_type == "AKAZE_MLDB")
    image_describer = AKAZE_Image_describer::create
      (AKAZE_Image_describer::Params(AKAZE::Params(), AKAZE_MLDB));

  if (!image_describer)
  {
    std::cerr << "Invalid Image_describer type" << std::endl;
    return EXIT_FAILURE;
  }

  //--
  // Detect regions thanks to the image_describer
  //--
  std::map<IndexT, std::unique_ptr<features::Regions>> regions_perImage;
  image_describer->Describe(imageL, regions_perImage[0]);
  image_describer->Describe(imageR, regions_perImage[1]);



