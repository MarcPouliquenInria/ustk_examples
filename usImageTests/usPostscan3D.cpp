#include <visp3/ustk_core/usImagePostScan3D.h>

int main(int argc, const char** argv) {
	usImage3D<unsigned char> img;
  usImagePostScan3D imagePostScan3D(img,usImageSettings3D());
  imagePostScan3D.setProbeRadius(40.10f);
  imagePostScan3D.setScanLinePitch(8.04);
  imagePostScan3D.setImageConvex(true);
  imagePostScan3D.setMotorRadius(5.54f);
  imagePostScan3D.setFramePitch(0.05f);
	std::cout << "probe info : " << std::endl;
  imagePostScan3D.printProbeSettings();
	exit(EXIT_SUCCESS);
}
