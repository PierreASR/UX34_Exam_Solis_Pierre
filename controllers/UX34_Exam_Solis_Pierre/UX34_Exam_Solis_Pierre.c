/*
 * File:          UX34_Exam_Solis_Pierre.c
 * Date:
 * Description:
 * Author:
 * Modifications:
 */

/*
 * You may need to add include files like <webots/distance_sensor.h> or
 * <webots/motor.h>, etc.
 */
#include <webots/robot.h>
#include <webots/motor.h>
#include <webots/distance_sensor.h>
#include <webots/keyboard.h>

#include <stdio.h>
/*
 * You may want to add macros here.
 */
#define TIME_STEP 64
#define VELOCITY 3
#define VEL_INCREMENT 0.2

int pressed_key;
double velocity;
double VelInc;


double Velocity (double V) {
  
double velocity; 

    velocity = V/0.075;
    return(velocity);
    }
    
double IncVel (double i) {

double VelInc;

    VelInc = i/0.075;
    return(VelInc);
    }

int main(int argc, char **argv) {
  
  wb_robot_init();

 
   WbDeviceTag left = wb_robot_get_device ("motor_left");
   WbDeviceTag right = wb_robot_get_device ("motor_right");
   
   WbDeviceTag position1 = wb_robot_get_device ("encoder1");
   WbDeviceTag position2 = wb_robot_get_device ("encoder2");
   
   WbDeviceTag dis_left = wb_robot_get_device ("dis_senosr1");
   WbDeviceTag dis_right = wb_robot_get_device ("dis_sensor2");
  
   wb_motor_set_position(left, INFINITY);
   wb_motor_set_position(right, INFINITY);
      
   wb_distance_sensor_enable(dis_left, TIME_STEP);
   wb_distance_sensor_enable(dis_right, TIME_STEP);
   
   wb_keyboard_enable(TIME_STEP);
   
    
  while (wb_robot_step(TIME_STEP) != -1) {
  
    velocity = Velocity(VELOCITY);
    VelInc = IncVel(VEL_INCREMENT);
    
    pressed_key = wb_keyboard_get_key();
    
    if (pressed_key == 'S') {
       velocity = velocity + VelInc;
    }
     else if (pressed_key == 'A') {
      velocity = velocity - VelInc;
     }
    
  
       
    wb_motor_set_velocity(left, -velocity);
    wb_motor_set_velocity(right, -velocity);
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
