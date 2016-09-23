#include<iostream>
#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_io/usImageIo.h>

int main(int argc, const char** argv) {
  vpImage<unsigned char> img;
  vpImageIo::read(img,std::string("C:/Users/mpouliqu/Documents/DataUS/prescan/prescan2D.png"));
  usImageSettings settings(0.5,0.6,true);
  usImagePostScan2D postScanImg(img, settings);
  postScanImg.setHeightResolution(12.5);
  postScanImg.setHeightResolution(10.2);
  usImageIo imgIo;
  imgIo.write(postScanImg, std::string("test"));
  usImagePostScan2D readPostScan2D(const std::string filename);


  exit(EXIT_SUCCESS);
}
