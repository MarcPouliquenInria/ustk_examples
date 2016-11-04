/****************************************************************************
 *
 * This file is part of the UsConfidenceMaps software.
 * Copyright (C) 2013 - 2016 by Inria. All rights reserved.
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
 * Authors:
 * Pierre Chatelain
 * Alexandre Krupa
 * Marc Pouliquen
 *
 *****************************************************************************/

#include <visp3/io/vpImageIo.h>

#include <visp3/ustk_core/usBackScanConverter2D.h>
#include <visp3/ustk_core/usScanConverter2D.h>

#include <visp3/ustk_io/usImageIo.h>
#include <visp3/ustk_io/usImageSettingsXmlParser.h>
#include <visp3/ustk_io/usSequenceReader.h>
#include <visp3/ustk_io/usSequenceWriter.h>

#include <visp3/ustk_core/usBackScanConverter2D.h>
#include <visp3/ustk_core/usScanConverter2D.h>

int main(int argc, const char** argv) {
  std::cout << "usage : ./usconfidenceMapExample /path/to/mysequence.xml" <<std::endl;

  if(argc != 2) {
    std::cout << "error, you must provide a sequence to process with confidence map" << std::endl;
  }

  usImagePostScan2D<unsigned char> postScan;
  usImageIo::read(postScan,argv[1]);

  usImagePreScan2D<unsigned char> preScan;

  usBackScanConverter2D backConv;
  backConv.init(postScan,0.15,480,0.0005);
  backConv.run(preScan);

  usImageIo::write(preScan,"test.xml");



  exit(EXIT_SUCCESS);
}
