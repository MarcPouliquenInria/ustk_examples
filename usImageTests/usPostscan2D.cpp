#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePostScan2D.h>


int main(int argc, const char** argv) {
	vpImage<unsigned char> img;
	std::string filename = std::string("prescan2D.png");
	vpImageIo::read(img, filename.c_str());
	usImagePostScan2D imagePostScan(img,usImageSettings());
  imagePostScan.setProbeRadius(40.10f);
  imagePostScan.setBSampleFreq(10.5f);
  imagePostScan.setLineAngle(55.84f);
  imagePostScan.setProbeElementPitch(0.05f);
  std::cout << "probe info : " << std::endl;
  imagePostScan.printProbeSettings();
	std::string outputFileName("prescan2D_COPY.png");
	vpImageIo::write(img, outputFileName);
	exit(EXIT_SUCCESS);
}
