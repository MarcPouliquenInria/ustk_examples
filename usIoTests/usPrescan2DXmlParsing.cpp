#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePreScan2D.h>
#include <visp3/ustk_io/usImageIo.h>
#include <visp3/ustk_io/usImageSettingsXmlParser.h>

int main(int argc, const char** argv) {
  vpImage<unsigned char> imagePng;
  std::string imagePath("~/Documents/usData/png/test.png");
  vpImageIo::read(imagePng,imagePath);
  usImagePreScan2D<unsigned char> preScanImg(imagePng,usImageSettings(2.555f,58.66666f,true));

  usImageIo imageIo2D;
  std::string testFileName("test");
  imageIo2D.writeXmlPng(preScanImg, testFileName);
  usImageIo imageIo2DReading;
  usImagePreScan2D<unsigned char> preScanRead = imageIo2DReading.readPreScan2DUCharFromXml(std::string("test.xml"));
  std::cout << "scanline_pitch : " << preScanRead.getScanLinePitch() << std::endl;
  std::cout << "probe_radius : " << preScanRead.getProbeRadius() << std::endl;
  std::cout << "is_convex : " << preScanRead.isImageConvex() << std::endl;
  std::cout << "image read width : " << preScanRead.getWidth() << std::endl;
  exit(EXIT_SUCCESS);
}
