#include <visp3/ustk_core/usImageRF3D.h>

int main(int argc, const char** argv) {
  //Testing usImageRF3D

  usImage3D<short> img;
  usImageRF3D imageRF3D(img, usImageSettings3D());
  std::cout << "probe info at init : " << std::endl;
  imageRF3D.printProbeSettings();
  imageRF3D.setProbeRadius(40.10f);
  imageRF3D.setScanLinePitch(8.04);
  imageRF3D.setImageConvex(true);
  imageRF3D.setMotorRadius(5.54f);
  imageRF3D.setFramePitch(0.05f);
  std::cout << "probe info after setting them : " << std::endl;
  imageRF3D.printProbeSettings();

  exit(EXIT_SUCCESS);
}
