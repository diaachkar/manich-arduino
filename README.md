Manich- future engineers- Lebanon

Engineering materials of our Manich self-driven vehicle's model participating in the WRO Future Engineers competition in the season 2022:
arduino uno, battery, the model consisted of two bases, an extension board, cables, 4 motors, color sensors, ultrasonic sensor, 4 wheels, a H bridge, and a camera.

## Introduction
In the beginning of the program, we used two integers to stock the number of the pin in the two variable that we named it "motor1" and "motor2" . Then in the void setup, a function that run only once in the beginning, we put the serial begin at 9600 bits, the rate of the connection. We wrote the mode of the first and second motor, that is output, because we are gonna precise later the value of the speed. In the void loop, a function that is on repeat all the time, we wrote analogue write for each of our motors at the speed of 255 so the robot can run a straight line.
To build the robot, we started by putting the four motors, the battery and the color sensor in the base. Then we put the wheels on the motors. In the upper model, we put the arduino uno and connected the cables to the pins. We also added an ultrasonic sensor, and a camera on the top of the motor, and an extension board for more cables. 
To connect the software to the hardware, we put a cable then selected in the tools the type of the arduino, an arduino uno, and selected the port and finally uploaded the code in the robot.

## The code 
int motor1= 4;
int motor2 =2;
void setup() {
  Serial.begin (9600);
  pinMode (motor1,OUTPUT);
  pinMode (motor2, OUTPUT);
}

void loop() {
  analogWrite (motor1, 255);
  analogWrite (motor2, 255);
}
