#include <visp3/ustk_core/usImagePostScan3D.h>

int main(int argc, const char** argv) {
	usImage3D<unsigned char> img;
  usImagePostScan3D<unsigned char> imagePostScan3D(img,usImageSettings3D());
  imagePostScan3D.setProbeRadius(40.10f);
  imagePostScan3D.setScanLinePitch(10.5f);
  imagePostScan3D.setImageConvex(true);
  imagePostScan3D.setMotorRadius(55.014);
  imagePostScan3D.setFramePitch(5.54f);
  imagePostScan3D.setMotorConvex(true);
	std::cout << "probe info : " << std::endl;
  imagePostScan3D.printProbeSettings();
	exit(EXIT_SUCCESS);
}
