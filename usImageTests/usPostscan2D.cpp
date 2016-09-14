#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePostScan2D.h>


int main(int argc, const char** argv) {
	/*if (argc != 2) {
		std::cerr << "Wrong number of arguments" << std::endl;
		std::cout << "Usage : ./usPostscan2D.exe /path/to/2dimage.png" << std::endl;
		std::cout << "Output image will be written near the .exe" << std::endl;
		exit(EXIT_FAILURE);
	}*/
	vpImage<unsigned char> img;
	std::string filename = std::string("prescan2D.png");
	vpImageIo::read(img, filename.c_str());
	usImagePostScan2D imagePostScan(img,usImageSettings());
	imagePostScan.setProbeRadius(40.10f);
	std::cout << "probe radius : " << imagePostScan.getProbeRadius() << std::endl;
	std::string outputFileName("prescan2D_COPY.png");
	vpImageIo::write(img, outputFileName);
	exit(EXIT_SUCCESS);
}
