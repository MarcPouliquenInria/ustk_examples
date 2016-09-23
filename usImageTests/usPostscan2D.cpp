#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePostScan2D.h>


int main(int argc, const char** argv) {
	vpImage<unsigned char> img;
	std::string filename = std::string("postcan2D.png");
  try {
    vpImageIo::read(img, filename.c_str());
  }
  catch (std::exception e) {
    std::cout << "Error reading image file !" << std::endl;
    std::cout << e.what() << std::endl;
  }
	usImagePostScan2D imagePostScan(img,usImageSettings());
  imagePostScan.setProbeRadius(40.10f);
  imagePostScan.setScanLinePitch(8.04);
  imagePostScan.setImageConvex(true);
  std::cout << "probe info : " << std::endl;
  imagePostScan.printProbeSettings();
	std::string outputFileName("prescan2D_COPY.png");
	vpImageIo::write(img, outputFileName);
	exit(EXIT_SUCCESS);
}
