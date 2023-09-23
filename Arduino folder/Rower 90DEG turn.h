#include <AFMotor.h>
#include <math.h>
int state=0;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
void setup() {
  // put your setup code here, to run once:
  motor1.setSpeed(200);
  motor1.run(RELEASE);
  motor2.setSpeed(200);
	motor2.run(RELEASE);
  motor3.setSpeed(200);
	motor3.run(RELEASE);
  motor4.setSpeed(200);
	motor4.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
	uint8_t i;

    // To rotate 90DEG towards right
  
  if(state==1){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  delay(500);
  state=0;
  }
	// Turn on motor
	motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
	
	// Accelerate from zero to maximum speed
	for (i=0; i<150; i++) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}
	
	// Decelerate from maximum speed to zero
	for (i=150; i!=0; i--) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}
  state+=1;
}
