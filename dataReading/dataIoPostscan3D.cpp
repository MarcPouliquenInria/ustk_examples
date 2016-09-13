/****************************************************************************
 *
 * This file is part of the UsTk software.
 * Copyright (C) 2014 by Inria. All rights reserved.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License ("GPL") as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 * See the file COPYING at the root directory of this source
 * distribution for additional information about the GNU GPL.
 * 
 * This software was developed at:
 * INRIA Rennes - Bretagne Atlantique
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * France
 * http://www.irisa.fr/lagadic
 *
 * If you have questions regarding the use of this file, please contact the
 * authors at Alexandre.Krupa@inria.fr
 * 
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 *
 * Authors:
 * Pierre Chatelain
 *
 *****************************************************************************/

/**
 * @file testDataIoPostscan3D.cpp
 * @brief Read a 3D postscan image and write a copy.
 * @author Pierre Chatelain
 */

#include <visp3/ustk_io/usDataIo.h>

/**
 * @example testDataIoPostscan3D.cpp
 *
 * Read a 3D postscan image and write a copy.
 *
 * @author Pierre Chatelain
 */
int main(int argc, const char** argv) {
  usDataPostscan3D data;
  if (argc != 2) {
    std::cerr << "Wrong number of arguments" << std::endl;
	std::cout << "Usage : ./postscan3D.exe /path/to/3dimage.mhd" << std::endl;
	std::cout << "Output image will be written near the .exe" << std::endl;
    exit(EXIT_FAILURE);
  }
  std::string filename = std::string(argv[1]) + "/postscan3d.mhd";
  usDataIo::read(data, filename.c_str());
  filename = std::string(argv[1]) + "/postscan3D_out.mhd";
  usDataIo::write(data, filename.c_str());
  exit(EXIT_SUCCESS);
}
