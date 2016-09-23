#include<iostream>
#include <visp3/ustk_io/usImageIo.h>

int main(int argc, const char** argv) {
  std::cout << "test 1" << std::endl;
  usImageIo img;
  img.readPostScan3D(std::string("C:/Users/mpouliqu/Documents/DataUS/postscan/3D/postscan3d.mhd")); ///home/mpouliqu/Documents/usData/postscan/3D/postscan3d.mhd
  exit(EXIT_SUCCESS);
}
