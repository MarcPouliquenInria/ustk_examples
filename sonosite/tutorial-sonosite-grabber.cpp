//! \example tutorial-sonosite-grabber.cpp
//! [capture-multi-threaded declaration]
#include <iostream>

#include <visp3/core/vpImageConvert.h>
#include <visp3/core/vpMutex.h>
#include <visp3/core/vpThread.h>
#include <visp3/core/vpTime.h>
#include <visp3/gui/vpDisplayX.h>
#include <visp3/sensor/vpV4l2Grabber.h>

#include <visp3/ustk_core/usImagePostScan2D.h>

#if defined(VISP_HAVE_V4L2) && defined(VISP_HAVE_PTHREAD)

// Shared vars
typedef enum {
  capture_waiting,
  capture_started,
  capture_stopped
} t_CaptureState;
t_CaptureState s_capture_state = capture_waiting;
vpImage<unsigned char> s_frame;
vpMutex s_mutex_capture;
//! [capture-multi-threaded declaration]

//! [capture-multi-threaded captureFunction]
vpThread::Return captureFunction(vpThread::Args args)
{
  vpV4l2Grabber cap = *((vpV4l2Grabber *) args);
  vpImage<unsigned char> frame_;
  bool stop_capture_ = false;

  cap.open(frame_);

  vpRect roi(vpImagePoint(48, 90), vpImagePoint(416, 550)); // roi to remove sonosite banners

  double start_time = vpTime::measureTimeSecond();
  while (! stop_capture_) {
    // Capture in progress
    cap.acquire(frame_, roi); // get a new frame from camera

    // Update shared data
    {
      vpMutex::vpScopedLock lock(s_mutex_capture);
      if (s_capture_state == capture_stopped)
        stop_capture_ = true;
      else
        s_capture_state = capture_started;
      s_frame = frame_;
    }
  }

  {
    vpMutex::vpScopedLock lock(s_mutex_capture);
    s_capture_state = capture_stopped;
  }
  std::cout << "End of capture thread" << std::endl;
  return 0;
}
//! [capture-multi-threaded captureFunction]

//! [capture-multi-threaded displayFunction]
vpThread::Return displayFunction(vpThread::Args args)
{
  (void)args; // Avoid warning: unused parameter args
  vpImage<unsigned char> I_;
  usImagePostScan2D<unsigned char> postScan_;

  t_CaptureState capture_state_;
  bool display_initialized_ = false;
#if defined(VISP_HAVE_X11)
  vpDisplayX *d_ = NULL;
#endif

  do {
    s_mutex_capture.lock();
    capture_state_ = s_capture_state;
    s_mutex_capture.unlock();

    // Check if a frame is available
    if (capture_state_ == capture_started) {
      // Create a copy of the captured frame
      {
        vpMutex::vpScopedLock lock(s_mutex_capture);
        I_ = s_frame;
      }

      // Convert image into post-scan image
      postScan_.setData(I_);
      postScan_.setProbeName("Sonosite C60");
      postScan_.setTransducerRadius(0.060);
      postScan_.setTransducerConvexity(true);
      postScan_.setScanLineNumber(128);
      postScan_.setScanLinePitch(vpMath::rad(57/127)); // field of view is 57 deg

      // Check if we need to initialize the display with the first frame
      if (! display_initialized_) {
        // Initialize the display
#if defined(VISP_HAVE_X11)
        d_ = new vpDisplayX(postScan_);
        display_initialized_ = true;
#endif
      }

      // Display the image
      vpDisplay::display(postScan_);

      // Trigger end of acquisition with a mouse click
      vpDisplay::displayText(postScan_, 10, 10, "Click to exit...", vpColor::red);
      if (vpDisplay::getClick(postScan_, false)) {
        vpMutex::vpScopedLock lock(s_mutex_capture);
        s_capture_state = capture_stopped;
      }

      // Update the display
      vpDisplay::flush(postScan_);
    }
    else {
      vpTime::wait(2); // Sleep 2ms
    }
  } while(capture_state_ != capture_stopped);

#if defined(VISP_HAVE_X11)
  delete d_;
#endif

  std::cout << "End of display thread" << std::endl;
  return 0;
}
//! [capture-multi-threaded displayFunction]

//! [capture-multi-threaded mainFunction]
int main(int argc, const char* argv[])
{
  unsigned int opt_input = 1;  // Default value is 1 to mach the material in the lab

  // Command line options
  for (int i=0; i<argc; i++) {
    if (std::string(argv[i]) == "--input")
      opt_input = (unsigned int)atoi(argv[i+1]);
    else if (std::string(argv[i]) == "--help") {
      std::cout << "Usage: " << argv[0] << " [--input <number>] [--help]" << std::endl;
      return 0;
    }
  }

  // Instantiate the grabber
  vpV4l2Grabber g;

  g.setInput(opt_input);
  g.setScale(1);

  // Start the threads
  vpThread thread_capture((vpThread::Fn)captureFunction, (vpThread::Args)&g);
  vpThread thread_display((vpThread::Fn)displayFunction);

  // Wait until thread ends up
  thread_capture.join();
  thread_display.join();

  return 0;
}
//! [capture-multi-threaded mainFunction]

#else
int main()
{
#  ifndef VISP_HAVE_V4L2
  std::cout << "You should enable V4L2 to make this example working..." << std::endl;
#  elif !defined(_WIN32) && (defined(__unix__) || defined(__unix) || (defined(__APPLE__) && defined(__MACH__))) // UNIX
  std::cout << "You should enable pthread usage and rebuild ViSP..." << std::endl;
#  else
  std::cout << "Multi-threading seems not supported on this platform" << std::endl;
#  endif
}

#endif
