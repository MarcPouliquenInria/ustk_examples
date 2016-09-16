#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePreScan2D.h>

int main(int argc, const char** argv) {
  //prescan image of uchar type
  std::cout << "Testing usImagePreScan2D<unsigned char> : " << std::endl;
  vpImage<unsigned char> imgUChar;
  std::string filenameUChar = std::string("prescanUChar2D.png");
  try {
    vpImageIo::read(imgUChar, filenameUChar.c_str());
  }
  catch (std::exception e) {
    std::cout << "Error reading image file !" << std::endl;
    std::cout << e.what() << std::endl;
  }
  usImagePreScan2D<unsigned char> imagePreScanUChar(imgUChar, usImageSettings());
  imagePreScanUChar.setProbeRadius(40.10f);
  imagePreScanUChar.setBSampleFreq(10.5f);
  imagePreScanUChar.setLineAngle(55.84f);
  imagePreScanUChar.setProbeElementPitch(0.05f);
  std::cout << "probe info : " << std::endl;
  imagePreScanUChar.printProbeSettings();
  std::string outputFileNameUChar("prescanUChar2D_COPY.png");
  vpImageIo::write(imgUChar, outputFileNameUChar);

  //prescan image of double type
  std::cout << "Testing usImagePreScan2D<double> : " << std::endl;
  vpImage<double> imgDouble;
  //std::string filenameDouble = std::string("prescanDouble2D.png");
  //vpImageIo::read(imgDouble, filenameDouble.c_str());
  usImagePreScan2D<double> imagePreScanDouble(imgDouble, usImageSettings());
  imagePreScanDouble.setProbeRadius(40.10f);
  imagePreScanDouble.setBSampleFreq(10.5f);
  imagePreScanDouble.setLineAngle(55.84f);
  imagePreScanDouble.setProbeElementPitch(0.05f);
  std::cout << "probe info : " << std::endl;
  imagePreScanDouble.printProbeSettings();
  //std::string outputFileNameDouble("prescanUChar2D_COPY.png");
  //vpImageIo::write(imgDouble, outputFileNameDouble);

  exit(EXIT_SUCCESS);
}
