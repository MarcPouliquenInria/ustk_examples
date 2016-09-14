#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePreScan2D.h>


int main(int argc, const char** argv) {
  /*if (argc != 2) {
  std::cerr << "Wrong number of arguments" << std::endl;
  std::cout << "Usage : ./usPostscan2D.exe /path/to/2dimage.png" << std::endl;
  std::cout << "Output image will be written near the .exe" << std::endl;
  exit(EXIT_FAILURE);
  }*/
  vpImage<unsigned char> img;
  std::string filename = std::string("prescanUChar2D.png");
  vpImageIo::read(img, filename.c_str());
  usImagePreScan2D<unsigned char> imagePreScan(img, usImageSettings());
  imagePreScan.setProbeRadius(40.10f);
  std::cout << "probe radius : " << imagePreScan.getProbeRadius() << std::endl;
  std::string outputFileName("prescanUChar2D_COPY.png");
  vpImageIo::write(img, outputFileName);
  exit(EXIT_SUCCESS);
}
