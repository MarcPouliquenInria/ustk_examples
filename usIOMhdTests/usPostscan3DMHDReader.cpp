#include<iostream>
#include <visp3/ustk_io/usImageIo.h>

int main(int argc, const char** argv) {
  usImageIo img;
  usImagePostScan3D<unsigned char> postScanImage3D;
  usImageIo::read(postScanImage3D,std::string("postscan3d.mhd"));



    std::cout << "dim: " << postScanImage3D.getDimX() << ", " << postScanImage3D.getDimY() << ", " << postScanImage3D.getDimZ() << std::endl;
    std::cout << "elementSpacing: " << postScanImage3D.getElementSpacingX() << ", " << postScanImage3D.getElementSpacingY() << ", " << postScanImage3D.getElementSpacingZ() << std::endl;

    std::cout << "imageConvex: " << postScanImage3D.isImageConvex() << std::endl;
    std::cout << "motorConvex: " << postScanImage3D.isMotorConvex() << std::endl;
    std::cout << "probeRadius: " << postScanImage3D.getProbeRadius() << std::endl;
    std::cout << "scanLinePitch: " << postScanImage3D.getScanLinePitch() << std::endl;
    std::cout << "motorradius: " << postScanImage3D.getMotorRadius() << std::endl;
    std::cout << "framePitch: " << postScanImage3D.getFramePitch() << std::endl;


    usImageIo::write(postScanImage3D,"test");
  exit(EXIT_SUCCESS);
}
