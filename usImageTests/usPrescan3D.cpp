//#include <visp3/ustk_core/usImage3D.h>
#include <visp3/ustk_core/usImagePreScan3D.h>


int main(int argc, const char** argv) {
  //prescan image of uchar type
  std::cout << "Testing usImagePreScan3D<unsigned char> : " << std::endl;
  usImage3D<unsigned char> imgUChar;
  usImagePreScan3D<unsigned char> imagePreScan3DUChar(imgUChar, usImageSettings3D());
  imagePreScan3DUChar.setProbeRadius(40.10f);
  imagePreScan3DUChar.setBSampleFreq(10.5f);
  imagePreScan3DUChar.setFrameAngle(15.3f);
  imagePreScan3DUChar.setLineAngle(55.84f);
  imagePreScan3DUChar.setMotorRadius(5.54f);
  imagePreScan3DUChar.setProbeElementPitch(0.05f);
  std::cout << "probe info : " << std::endl;
  imagePreScan3DUChar.printProbeSettings();

  //prescan image of double type
  std::cout << "Testing usImagePreScan3D<double> : " << std::endl;
  const usImage3D<double> img;
  usImagePreScan3D<double> imagePreScan3DDouble(img, usImageSettings3D());
  imagePreScan3DDouble.setProbeRadius(40.10f);
  imagePreScan3DDouble.setBSampleFreq(10.5f);
  imagePreScan3DDouble.setFrameAngle(15.3f);
  imagePreScan3DDouble.setLineAngle(55.84f);
  imagePreScan3DDouble.setMotorRadius(5.54f);
  imagePreScan3DDouble.setProbeElementPitch(0.05f);
  std::cout << "probe info : " << std::endl;
  imagePreScan3DDouble.printProbeSettings();

  exit(EXIT_SUCCESS);
}
