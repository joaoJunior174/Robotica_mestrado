/*
 * File:          controle_robo.c
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
#include <webots/distance_sensor.h>
#include <webots/motor.h>
#include <stdio.h>

/*
 * You may want to add macros here.
 */
#define TIME_STEP 64

/*
 * This is the main program.
 * The arguments of the main function can be specified by the
 * "controllerArgs" field of the Robot node
 */
int main(int argc, char **argv) {
  /* necessary to initialize webots stuff */
  wb_robot_init();


  WbDeviceTag left_motor_1 = wb_robot_get_device("front left wheel");
  WbDeviceTag right_motor_1 = wb_robot_get_device("front right wheel");
  WbDeviceTag left_motor_2 = wb_robot_get_device("back left wheel");
  WbDeviceTag right_motor_2 = wb_robot_get_device("back right wheel");
  
  WbDeviceTag sensf = wb_robot_get_device("so4");
  WbDeviceTag sensb = wb_robot_get_device("so12");
  
  wb_distance_sensor_enable(sensf,TIME_STEP);
  wb_distance_sensor_enable(sensb,TIME_STEP);
  
  wb_motor_set_position(left_motor_1,INFINITY);
  wb_motor_set_position(right_motor_1,INFINITY);
  wb_motor_set_position(left_motor_2,INFINITY);
  wb_motor_set_position(right_motor_2,INFINITY);
  
  double left_speed_1 = 5.0;
  double left_speed_2 = 5.0;
  double right_speed_1=5.0;
  double right_speed_2=5.0;
  double sensf_value;
  double sensb_value; 
  
  /*
   * You should declare here WbDeviceTag variables for storing
   * robot devices like this:
   *  WbDeviceTag my_sensor = wb_robot_get_device("my_sensor");
   *  WbDeviceTag my_actuator = wb_robot_get_device("my_actuator");
   */

  /* main loop
   * Perform simulation steps of TIME_STEP milliseconds
   * and leave the loop when the simulation is over
   */
  while (wb_robot_step(TIME_STEP) != -1) {
  
     sensf_value = wb_distance_sensor_get_value(sensf);
     sensb_value = wb_distance_sensor_get_value(sensb);
     
     
     printf("sensor f %f sensor b %f\n",sensf_value,sensb_value);
     fflush(stdout);
     
     if(sensf_value >= 900){
     
        left_speed_1 = -5.0;
        left_speed_2 = -5.0;
        right_speed_1= -5.0;
        right_speed_2= -5.0;     
     
     }
     if(sensb_value >= 900){
     
        left_speed_1 = 5.0;
        left_speed_2 = 5.0;
        right_speed_1= 5.0;
        right_speed_2= 5.0;     
     
     }
     
         
     
     wb_motor_set_velocity(left_motor_1,left_speed_1);
     wb_motor_set_velocity(left_motor_2,left_speed_2);
     wb_motor_set_velocity(right_motor_1,right_speed_1);
     wb_motor_set_velocity(right_motor_2,right_speed_2);
  
    /*
     * Read the sensors :
     * Enter here functions to read sensor data, like:
     *  double val = wb_distance_sensor_get_value(my_sensor);
     */

    /* Process sensor data here */

    /*
     * Enter here functions to send actuator commands, like:
     * wb_motor_set_position(my_actuator, 10.0);
     */
  };

  /* Enter your cleanup code here */

  /* This is necessary to cleanup webots resources */
  wb_robot_cleanup();

  return 0;
}
