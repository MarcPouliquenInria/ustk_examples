/****************************************************************************
 *
 * $Id: moveViper850.cpp,v 1.11 2008/06/13 13:37:36 asaunier Exp $
 *
 * Copyright (C) 1998-2006 Inria. All rights reserved.
 *
 * This software was developed at:
 * IRISA/INRIA Rennes
 * Projet Lagadic
 * Campus Universitaire de Beaulieu
 * 35042 Rennes Cedex
 * http://www.irisa.fr/lagadic
 *
 * This file is part of the ViSP toolkit
 *
 * This file may be distributed under the terms of the Q Public License
 * as defined by Trolltech AS of Norway and appearing in the file
 * LICENSE included in the packaging of this file.
 *
 * Licensees holding valid ViSP Professional Edition licenses may
 * use this file in accordance with the ViSP Commercial License
 * Agreement provided with the Software.
 *
 * This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
 * WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
 *
 * Contact visp@irisa.fr if any conditions of this licensing are
 * not clear to you.
 *
 * Description:
 * Example of a real robot control, the Viper850 robot (arm, with 6
 * degrees of freedom).
 *
 * Authors:
 * Fabien Spindler
 *
 ****************************************************************************/
/*!
  \example Viper850_test_FT_control_sensor_frame.cpp

  \brief Example of a real robot control, the Viper850 robot (arm
  with 6 degrees of freedom). The robot is controlled in force and torque.

  The forces and torques are controlled in the FT sensor frame.

  Let us denote \f$\cal{F}_{ft}\f$ the force/torque frame.

  The cartesian velocity \f$\bf{v}_{ft}\f$ compute from the force torque
  measures is given by \f$ \bf{v}_{ft} = \lambda \; (\bf{H}-\bf{H}^*)\f$.

  Since \f$ \bf{v}_{ft} = ^{ft}{\bf V}_e \; ^e{\bf J}_e \; \dot{q}\f$, the
  corresponding joint velocities are then computed using \f$ \dot{q} = \lambda
  ( ^{ft}{\bf V}_e \; ^e{\bf J}_e)^{-1} (\bf{H}-\bf{H}^*)\f$

*/


#include <stdlib.h>

#include <visp/vpConfig.h>
#include <visp/vpDebug.h>
#include <visp/vpParseArgv.h>
#include <visp/vpRobotViper850.h>
#include <visp/vpTime.h>
#include <visp/vpPlot.h>

#ifdef VISP_HAVE_VIPER850


int
main()
{
  try
  {
    vpRobotViper850 robot ;

    vpMatrix eJe; // robot jacobian

    // Transformation from end-effector frame to the force/torque sensor
    // Note that the end-effector frame is located on the lower part of
    // male component of the tool changer.
    vpHomogeneousMatrix eMs;
    eMs[2][3] = -0.0666; // tz = -6.66cm

    // Transformation from force/torque sensor to the end-effector frame
    vpHomogeneousMatrix sMe;
    eMs.inverse(sMe);

    // Build the transformation that allows to convert a velocity in the
    // end-effector frame to the FT sensor frame
    vpVelocityTwistMatrix sVe;
    sVe.buildFrom(sMe);

    vpColVector sHs(6); // force/torque sensor measures
    vpColVector sHs_star(6); // force/torque sensor desired values
    vpMatrix lambda(6,6);

    // Cartesian velocities corresponding to the force/torque control in the
    // sensor frame
    vpColVector v_s(6);
    // Joint velocities corresponding to the force/torque control
    vpColVector q_dot(6);

    // Initialized the force gain
    lambda = 0;
    switch (robot.getControlMode()) {
    case vpRobotViper850::AUTO:
      for (int i=0; i< 3; i++)
        lambda[i][i] = 0.02/10;
      // Initialized the torque gain
      for (int i=3; i< 6; i++)
        lambda[i][i] =1./4.;
      break;
    case vpRobotViper850::MANUAL:
      for (int i=0; i< 3; i++)
        lambda[i][i] = 0.02/2.0; // 0.02 with old sensor
      // Initialized the torque gain
      for (int i=3; i< 6; i++)
        lambda[i][i] = 1.0/3.0; // 1  with old sensor
      break;
    default:
      break;
    }

    // Initialize the desired force/torque values
    sHs_star = 0;
    sHs_star[2] = 1; // Fz = 1N

    // Create a window with two graphics
    // - first graphic for the measured forces
    // - second graphic for the measured torques
    // - third graphic for the translational velocities expressed in the
    //   sensor frame
    // - fourth graphic for the rotational velocities expressed in the
    //   sensor frame
    vpPlot plot(4);
    // The first graphic contains 3 data to plot:  Fx, Fy, Fz
    plot.initGraph(0, 3);
    // The second graphic contains 3 data to plot: Tx, Ty, Tz
    plot.initGraph(1, 3);
    // For the first graphic :
    // - along the x axis the expected values are between 0 and 200 and
    //   the step is 1
    // - along the y axis the expected values are between -1.2 and 1.2 and the
    //   step is 0.1
    plot.setTitle(0, "Forces measures");
    plot.setUnitY(0, "N");
    // Set the curves legend
    plot.setLegend(0, 0, "Fx");
    plot.setLegend(0, 1, "Fy");
    plot.setLegend(0, 2, "Fz");
    // Set the curves color
    plot.setColor(0, 0, vpColor::red);
    plot.setColor(0, 1, vpColor::green);
    plot.setColor(0, 2, vpColor::blue);

    // For the second graphic :
    // - along the x axis the expected values are between 0 and 200 and
    //   the step is 1
    // - along the y axis the expected values are between 30 and -30 and the
    //   step is 10
    plot.setTitle(1, "Torques measures");
    plot.setUnitY(1, "Nm");
    // Set the curves legend
    plot.setLegend(1, 0, "Tx");
    plot.setLegend(1, 1, "Ty");
    plot.setLegend(1, 2, "Tz");
    // Set the curves color
    plot.setColor(1, 0, vpColor::red);
    plot.setColor(1, 1, vpColor::green);
    plot.setColor(1, 2, vpColor::blue);

    // The third graphic contains 3 data to plot: vx, vy, vz
    plot.initGraph(2, 3);
    // For the first graphic :
    // - along the x axis the expected values are between 0 and 200 and
    //   the step is 1
    // - along the y axis the expected values are between -1.2 and 1.2 and the
    //   step is 0.1
    plot.setTitle(2, "Translational velocities expressed in Fs");
    plot.setUnitY(2, "m/s");
    // Set the curves legend
    plot.setLegend(2, 0, "vx");
    plot.setLegend(2, 1, "vy");
    plot.setLegend(2, 2, "vz");
    // Set the curves color
    plot.setColor(2, 0, vpColor::red);
    plot.setColor(2, 1, vpColor::green);
    plot.setColor(2, 2, vpColor::blue);

    // The fourth graphic contains 3 data to plot: wx, wy, wz
    plot.initGraph(3, 3);
    // For the fourth graphic :
    // - along the x axis the expected values are between 0 and 200 and
    //   the step is 1
    // - along the y axis the expected values are between -1.2 and 1.2 and the
    //   step is 0.1
    plot.setTitle(3, "Rotational velocities expressed in Fs");
    plot.setUnitY(3, "rad/s");
    // Set the curves legend
    plot.setLegend(3, 0, "wx");
    plot.setLegend(3, 1, "wy");
    plot.setLegend(3, 2, "wz");
    // Set the curves color
    plot.setColor(3, 0, vpColor::red);
    plot.setColor(3, 1, vpColor::green);
    plot.setColor(3, 2, vpColor::blue);

    // Bias the force/torque sensor
    std::cout << "\nBias the force/torque sensor...\n " << std::endl;
    robot.biasForceTorqueSensor() ;

    // Set the robot to velocity control
    robot.setRobotState(vpRobot::STATE_VELOCITY_CONTROL) ;

    int iter = 0;
    while(1) {
      // Get the force/torque measures from the sensor
      sHs = robot.getForceTorque() ;

      // Multiply the measures by -1 to get the force/torque exerced by the
      // robot to the environment.
      sHs *= -1;

      // std::cout << "Measured force/torque: " << sHs.t() << std::endl;

      // Compute the force/torque control law in the sensor frame
      v_s = lambda*(sHs_star - sHs );
      // std::cout << "v_s: " << v_s.t() << std::endl;

      // Plot the force/torque measures
      for (int i=0; i<3; i++)
        plot.plot(0, i, iter, sHs[i]); // plot Fx,Fy,Fz
      for (int i=0; i<3; i++)
        plot.plot(1, i, iter, sHs[i+3]); // plot Tx,Ty,Tz
      // Plot the velocities expressed in the probe frame
      for (int i=0; i<3; i++)
        plot.plot(2, i, iter, v_s[i]); // plot vx,vy,vz
      for (int i=0; i<3; i++)
        plot.plot(3, i, iter, v_s[i+3]); // plot wx,wy,wz

      // Get the robot jacobian eJe
      robot.get_eJe(eJe);

      // Compute the joint velocities to achieve the force/torque control
      q_dot = (sVe * eJe).pseudoInverse() * v_s;

      // Send the joint velocities to the robot
      // std::cout << "\nApply joint velocity (rad/s): " << q_dot.t();
      robot.setVelocity(vpRobot::ARTICULAR_FRAME, q_dot) ;

      if (vpDisplay::getClick(plot.I, false))
        break;

      iter ++;
      vpTime::wait(1);
    }
    std::cout << "The end.\n";

    //       plot.saveData(0, "/tmp/torque.txt");
    //       plot.saveData(1, "/tmp/force.txt");
  }
  catch (...)
  {
    vpERROR_TRACE(" Test failed") ;
    return 0;
  }
}
#else
int
main()
{
  vpERROR_TRACE("You do not have an viper850 robot connected to your computer...");
  return 0;
}

#endif
