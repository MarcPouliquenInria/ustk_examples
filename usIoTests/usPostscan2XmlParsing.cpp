#include <visp3/core/vpImage.h>
#include <visp3/io/vpImageIo.h>
#include <visp3/ustk_core/usImagePostScan2D.h>
#include <visp3/ustk_io/usImageIo.h>
#include <visp3/ustk_io/usImageSettingsXmlParser.h>

int main(int argc, const char** argv) {
  vpImage<unsigned char> imagePng;
  std::string imagePath("~/Documents/usData/png/test.png");
  vpImageIo::read(imagePng,imagePath);
  usImagePostScan2D postScanImg(imagePng,usImageSettings(2.555f,58.66666f,true));

  usImageIo imageIo2D;
  std::string testFileName("test");
  imageIo2D.writeXmlPng(postScanImg, testFileName);
  usImageIo imageIo2DReading;
  usImagePostScan2D postScanRead = imageIo2DReading.readPostScan2DFromXml(std::string("test.xml"));
  std::cout << "scanline_pitch : " << postScanRead.getScanLinePitch() << std::endl;
  std::cout << "probe_radius : " << postScanRead.getProbeRadius() << std::endl;
  std::cout << "is_convex : " << postScanRead.isImageConvex() << std::endl;
  std::cout << "image read width : " << postScanRead.getWidth() << std::endl;
  exit(EXIT_SUCCESS);
}
