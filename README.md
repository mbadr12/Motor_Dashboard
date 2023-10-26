# Motor Dashboard Project

This is a README file for the Motor Dashboard project that controls three motors: a DC motor, a stepper motor, and a servo motor. The system utilizes an LCD display and a keypad for user interaction. The project is implemented using an AVR microcontroller, a 4x4 keypad, a 16x2 character LCD, a DC motor, a stepper motor, a servo motor, a potentiometer, and a temperature sensor.

## System Overview

The Motor Dashboard project allows users to control three types of motors using the provided interface. The system incorporates the following components:

1. AVR Microcontroller: The AVR microcontroller acts as the main processing unit, responsible for coordinating the inputs from the keypad and controlling the motors.

2. 4x4 Keypad: The 4x4 keypad provides the user interface for inputting commands and selecting motor control options.

3. 16x2 Character LCD: The LCD display module shows relevant information and prompts to guide the user through the motor control process.

4. DC Motor: The system enables the user to control the direction and speed of a DC motor. The user can choose the motor direction (CW or CCW) and select a speed control method (potentiometer, full speed, or using temperature sensor value).

5. Stepper Motor: The project allows the user to control the direction (CW or CCW) and specify the degree of rotation for a stepper motor.

6. Servo Motor: The system provides a menu for the user to select the absolute degree to which a servo motor should move.

7. Potentiometer: The potentiometer serves as a speed control option for the DC motor.

8. Temperature Sensor: The temperature sensor provides an alternative speed control option for the DC motor, based on the measured temperature value.

## User Authentication

When the system starts, the user is prompted to enter a username and password. The password is the reverse of the username. The user has a maximum of three attempts to enter the correct credentials. If the maximum number of attempts is exceeded, the system turns off.

## Motor Control Options

Upon successful authentication, the user is presented with three motor control options:

1. DC Motor Control:
   - The user can select the DC motor from the menu.
   - A sub-menu allows the user to choose the motor direction (CW or CCW).
   - Another sub-menu offers three speed control options: potentiometer, full speed, or using the temperature sensor value.

2. Stepper Motor Control:
   - The user can select the stepper motor from the menu.
   - A sub-menu allows the user to choose the motor direction (CW or CCW).
   - Another sub-menu prompts the user to enter the degree of rotation.

3. Servo Motor Control:
   - The user can select the servo motor from the menu.
   - A sub-menu allows the user to choose the absolute degree to which the servo motor should move.

## Installation and Setup

To set up and run the Motor Dashboard project, follow these steps:

1. Hardware Connections: Connect the AVR microcontroller, 4x4 keypad, 16x2 character LCD, DC motor, stepper motor, servo motor, potentiometer, and temperature sensor according to the hardware specifications and pin mappings.

2. Software Dependencies: Install the necessary software dependencies for programming the AVR microcontroller and interfacing with the LCD, keypad, and motor control.

3. Code Compilation: Compile and upload the provided source code to the AVR microcontroller using your preferred programming environment.

4. Power On: Power on the system by connecting the appropriate power supply to the AVR microcontroller and the motors.

5. User Authentication: When the system starts, enter the username and password as prompted. Remember that the password is the reverse of the username.

6. Motor Control: Once authenticated, navigate the menu using the keypad and LCD. Select the desired motor and follow the sub-menus to choose the desired motor control options.

7. Enjoy: Explore and control the motors using the Motor Dashboard project. Experiment with different settings and functionalities to observe the motor responses.

## Troubleshooting

If you encounter any issues while setting up or running the Motor Dashboard project, consider the following troubleshooting steps:

1. Hardware Connections: Verify that all the hardware components are properly connected according to the specifications and pin mappings.

2. Power Supply: Ensure that the power supply is supplying sufficient power to the AVR microcontroller and the motors.

3. Code Verification: Double-check the uploaded code for any errors or compatibility issues with the AVR microcontroller and the connected components.

4. Keypad and LCD: Check the keypad and LCD connections and confirm that they are functioning correctly. Verify that the displayed information on the LCD is accurate.

5. Motor Control: Ensure that the motor control signals are properly wired and connected to the corresponding pins of the AVR microcontroller.

6. Input Validation: Validate user inputs to prevent unexpected behavior or erroneous motor control actions.

7. Debugging: Utilize debugging tools and techniques to identify anypotential issues in the code or hardware connections. Consider using serial communication or additional debugging outputs to monitor the system's behavior and identify any errors or malfunctions.

## Conclusion

The Motor Dashboard project provides a user-friendly interface for controlling three types of motors: a DC motor, a stepper motor, and a servo motor. By utilizing an AVR microcontroller, a keypad, an LCD display, and various sensors, the system allows users to authenticate, select a motor, and configure its speed, direction, and degree of rotation. Follow the installation and setup instructions to enjoy controlling the motors with this interactive dashboard. Happy motor controlling!
