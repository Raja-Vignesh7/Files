#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() 
{
	//Set initial speed of the motor & stop
	motor1.setSpeed(200);
	motor1.run(RELEASE);
  motor2.setSpeed(200);
	motor2.run(RELEASE);
  motor3.setSpeed(200);
	motor3.run(RELEASE);
  motor4.setSpeed(200);
	motor4.run(RELEASE);
  }

void loop() 
{
	uint8_t i;

	// Turn on motor
	motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
	
	// Accelerate from zero to maximum speed
	for (i=0; i<255; i++) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}
	
	// Decelerate from maximum speed to zero
	for (i=255; i!=0; i--) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}

	// Now change motor direction
	motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
	
	// Accelerate from zero to maximum speed
	for (i=0; i<255; i++) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}

	// Decelerate from maximum speed to zero
	for (i=255; i!=0; i--) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}

	// Now turn off motor
  motor1.setSpeed(RELEASE);
  motor2.setSpeed(RELEASE);
  motor3.setSpeed(RELEASE);
  motor4.setSpeed(RELEASE);
	delay(1000);
}
