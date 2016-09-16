#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImageRF2D.h>

int main(int argc, const char** argv) {
#if 0 //vpImage<short> not managed by vpImageIO :/
  vpImage<short> img;
  std::string filename = std::string("rf2D.png");
  try {
    vpImageIo::read(img, filename.c_str());
  }
  catch (std::exception e) {
    std::cout << "Error reading image file !" << std::endl;
    std::cout << e.what() << std::endl;
}
  usImageRF2D imageRF2D(img, usImageSettings());
  mageRF2D.setProbeRadius(40.10f);
  std::cout << "probe radius : " << mageRF2D.getProbeRadius() << std::endl;
  std::string outputFileName("rf2D_COPY.png");
  vpImageIo::write(img, outputFileName);
#endif
  exit(EXIT_SUCCESS);
}
