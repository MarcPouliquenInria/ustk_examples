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

#include <visp3/ustk_confidence_map/usScanlineConfidence2D.h>

int main(int argc, const char** argv) {
  std::cout << "usage : ./usconfidenceMapExample /path/to/mysequence.xml" <<std::endl;

  if(argc != 2) {
    std::cout << "error, you must provide a sequence to process with confidence map" << std::endl;
  }

  //confidence processor and scan converter
  usScanlineConfidence2D confidenceMapProcessor;
  usScanConverter2D scanConverter;
  double postScanResolution = 5.0e-4;

  //to read the sequence
  usSequenceReader<usImagePreScan2D<unsigned char> > reader;
  std::string sequenceFileName = argv[1];
  reader.setSequenceFileName(sequenceFileName);

  //to write the confidence sequence
  std::string  outputSequence = "/tmp/" + vpIoTools::getUserName() + "/confidenceMapSequence/" ;
  vpIoTools::makeDirectory(outputSequence);
  outputSequence += "confidenceSequence.xml";
  std::string outputImage = "confidence%04d.png";

  usSequenceWriter<usImagePostScan2D<unsigned char> > writer;
  writer.setSequenceFileName(outputSequence);
  writer.setImageFileName(outputImage);

  while(!reader.end()) {
    usImagePreScan2D<unsigned char> currentImage;
    reader.acquire(currentImage);

    //initialisations
    //settings for sonosite probe
    scanConverter.init(currentImage.getHeight(), currentImage.getWidth(),1540.0,
                       postScanResolution,currentImage.getTransducerRadius(),(int) (10*currentImage.getHeight()),
                       4.25e-4, 128);
    confidenceMapProcessor.init(usScanlineConfidence2D::US_CONF_INTEGRATION);

    //computing pre-scan confidence map
    usImagePreScan2D<unsigned char> confidencePreScan;
    confidencePreScan.setImagePreScanSettings(currentImage);
    confidenceMapProcessor.run(confidencePreScan, currentImage);

    //converting computed confidence map in post-scan
    usImagePostScan2D<unsigned char> confidencePostScan;
    scanConverter.run(confidencePostScan,confidencePreScan);

    //writing
    writer.saveImage(confidencePostScan);
  }
  exit(EXIT_SUCCESS);
}
