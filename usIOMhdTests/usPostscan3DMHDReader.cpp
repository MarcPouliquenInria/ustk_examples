#include<iostream>
#include <visp3/ustk_io/usImageIo.h>

int main(int argc, const char** argv) {
  std::cout << "test 1" << std::endl;
  usImageIo img;
  img.readPostScan3D(std::string(argv[2])); //C:\Users\mpouliqu\Documents\DataUS\postscan\3D\postscan3d.mhd
  exit(EXIT_SUCCESS);
}
