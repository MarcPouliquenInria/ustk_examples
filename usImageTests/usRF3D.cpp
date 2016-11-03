#include <visp3/ustk_core/usImageRF3D.h>

int main(int argc, const char** argv) {
  //Testing usImageRF3D

  usImage3D<short> img(100,100,100);
  img.initData(255);
  usImageRF3D<short> imageRF3D;
  std::cout << "probe info at init : " << std::endl;
  std::cout << imageRF3D << std::endl;
  imageRF3D.setTransducerRadius(40.10f);
  imageRF3D.setScanLinePitch(8.04);
  imageRF3D.setTransducerConvexity(true);
  imageRF3D.setMotorRadius(5.54f);
  imageRF3D.setFramePitch(0.05f);
  std::cout << "probe info after setting them : " << std::endl;
  std::cout << imageRF3D << std::endl;

  exit(EXIT_SUCCESS);
}
