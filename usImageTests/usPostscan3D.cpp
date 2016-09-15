#include <visp3/ustk_core/usImage3D.h>
#include <visp3/ustk_core/usImagePostScan3D.h>


int main(int argc, const char** argv) {
	usImage3D<unsigned char> img;
  usImagePostScan3D imagePostScan3D(img,usImageSettings3D());
  imagePostScan3D.setProbeRadius(40.10f);
  imagePostScan3D.setBSampleFreq(10.5f);
  imagePostScan3D.setFrameAngle(15.3f);
  imagePostScan3D.setLineAngle(55.84f);
  imagePostScan3D.setMotorRadius(5.54f);
  imagePostScan3D.setProbeElementPitch(0.05f);
	std::cout << "probe info : " << std::endl;
  imagePostScan3D.printProbeSettings();
	exit(EXIT_SUCCESS);
}
