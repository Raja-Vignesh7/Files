#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>
Servo myservo

#define TRIGGER_PIN 13
#define ECHO_PIN 2
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
int pos=0;
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

  myservo.attach(10); // servo 1
  myservo.write(90);
  }

void loop() 
{
	uint8_t i;
	// Turn on motor
	motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  // move forward
	motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
	unsigned int distance = sonar.ping_cm();
  if(distance<=10){
  motor1.setSpeed(RELEASE);
  motor2.setSpeed(RELEASE);
  motor3.setSpeed(RELEASE);
  motor4.setSpeed(RELEASE);
  for(pos=90;pos>=0;pos-=1){
    myservo.write(pos);
    delay(15);
  }
  distance = sonar.ping_cm();
  }
	// Decelerate from maximum speed to zero
	for (i=200; i!=0; i--) 
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
	for (i=0; i<200; i++) 
	{
		motor1.setSpeed(i);
    motor2.setSpeed(i);
    motor3.setSpeed(i);
    motor4.setSpeed(i);  
		delay(10);
	}

	// Decelerate from maximum speed to zero
	for (i=200; i!=0; i--) 
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
void TrunRight(){
    motor1.run(FORWARD);
    motor2.run(FORWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  delay(500);
}

void TrunLeft(){
    motor1.run(BACKWARD);
    motor2.run(BACKWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  delay(500);
}

void MoveBack(){
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
  // set speed
  motor1.setSpeed(100);
  motor2.setSpeed(100);
  motor3.setSpeed(100);
  motor4.setSpeed(100);
  delay(1500);
}
