const int INPUT_PIN;
const int OUTPUT_PIN;
double dt,last_time;
double integral, previous, output=0;
double Kp,Kd,Ki;
double setpoint=100; // desired value
void setup() {
  Kp=0.78;  // Prportional const
  Kd=0.5;   // derivative const
  Ki=0.1;   // integral const
  Serial.begin(9600);
  analogWrite(OUTPUT_PIN,0);  // initialise to zero
  for(int i=0;i<50;i++){     
    Serial.print(setpoint);
    Serial.print(",");
    Serial.print(0);
    delay(100);
  }
  delay(100);
}

void loop() {
  double now=millis();
  dt=(now-last_time)/1000.00;
  last_time=now;
  double actual =map(analogRead(INPUT_PIN),0,1024,0,225);
  double error =setpoint-actual;
  output=pid(error);
  analogWrite(OUTPUT_PIN,output);
  Serial.println(error);
}
// PID function
double pid(double error){   
  double proportional=error;
  integral+=error*dt;
  double derivative=(error-proportional)/dt;
  previous=error;
  double output=(Kp*proportional)+(Ki*integral)+(Kd*derivative);
  return output;
}
