#include <visp3/ustk_core/usImagePostScan3D.h>

int main(int argc, const char** argv) {
  //usImage3D<unsigned char> img;
  usImagePostScan3D<unsigned char> imagePostScan3D;
  imagePostScan3D.setTransducerRadius(40.10f);
  imagePostScan3D.setScanLinePitch(10.5f);
  imagePostScan3D.setTransducerConvexity(true);
  imagePostScan3D.setMotorRadius(55.014);
  imagePostScan3D.setFramePitch(5.54f);
  imagePostScan3D.setMotorType(usMotorSettings::LinearMotor);
	std::cout << "probe info : " << std::endl;
  std::cout << imagePostScan3D << std::endl;
	exit(EXIT_SUCCESS);
}
