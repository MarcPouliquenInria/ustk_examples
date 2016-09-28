#include<iostream>
#include <visp3/ustk_io/usImageIo.h>

int main(int argc, const char** argv) {
  usImageIo img;
  usImagePostScan3D<unsigned char> postScanImage3D;
  img.read(postScanImage3D,std::string("/home/mpouliqu/Documents/usData/ustk-tests-dataset/postscan3d.mhd"));

  std::cout << "scanline pitch: " << postScanImage3D.getScanLinePitch() << std::endl;
  exit(EXIT_SUCCESS);
}
