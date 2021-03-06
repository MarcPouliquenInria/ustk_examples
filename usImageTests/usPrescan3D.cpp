#include <visp3/ustk_core/usImagePreScan3D.h>

int main(int argc, const char** argv) {
  //prescan image of uchar type
  std::cout << "Testing usImagePreScan3D<unsigned char> : " << std::endl;
  usImage3D<unsigned char> imgUChar;
  /*usImageSettings3D settingsUChar;
  usImagePreScan3D<unsigned char> imagePreScan3DUChar(imgUChar, settingsUChar);
  //print default values
  std::cout << "probe default info : " << std::endl;
  imagePreScan3DUChar.printProbeSettings();
  imagePreScan3DUChar.setProbeRadius(40.10f);
  imagePreScan3DUChar.setScanLinePitch(8.04);
  imagePreScan3DUChar.setImageConvex(true);
  imagePreScan3DUChar.setMotorRadius(5.54f);
  imagePreScan3DUChar.setFramePitch(0.05f);
  //print updated values
  std::cout << "probe new info : " << std::endl;
  imagePreScan3DUChar.printProbeSettings();

  //prescan image of double type
  std::cout << "Testing usImagePreScan3D<double> : " << std::endl;
  const usImage3D<double> img;
  usImageSettings3D settingsDouble;
  usImagePreScan3D<double> imagePreScan3DDouble(img, settingsDouble);
  //print default values
  std::cout << "probe info : " << std::endl;
  imagePreScan3DDouble.printProbeSettings();
  imagePreScan3DDouble.setProbeRadius(40.10f);
  imagePreScan3DDouble.setScanLinePitch(8.04);
  imagePreScan3DDouble.setImageConvex(true);
  imagePreScan3DDouble.setMotorRadius(5.54f);
  imagePreScan3DDouble.setFramePitch(0.05f);
  //print updated values
  std::cout << "probe new info : " << std::endl;
  imagePreScan3DDouble.printProbeSettings();*/

  exit(EXIT_SUCCESS);
}
