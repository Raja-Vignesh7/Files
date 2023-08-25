#include <dht11.h>
#define DHT11PIN 4
dht11 DHT11;
const int LED_RED=7;
const int LED_YELLOW=12;
const int LED_GREEN=9;
const int TOUCH=8;
const int PHOTON_SENSOR=2;
int val;
int old_val=LOW;
int state=0;
int psval;
int DN=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LED_RED,OUTPUT);
  pinMode(LED_YELLOW,OUTPUT);
  pinMode(LED_GREEN,OUTPUT);
  pinMode(TOUCH,INPUT);
  pinMode(PHOTON_SENSOR,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int RB=0;
  int YB=0;
  int GB=0;

  val=digitalRead(TOUCH);
  if(val==HIGH && old_val==LOW){
    state=1-state;
    delay(50);
  }
  old_val=val;
  if(state==1){
    digitalWrite(LED_GREEN,HIGH);
    int chk=DHT11.read(DHT11PIN);
    psval=digitalRead(PHOTON_SENSOR);
    Serial.println();
    Serial.println();
    Serial.print("Temperatuce  (c): ");
    Serial.println((float)DHT11.temperature,2);
    Serial.print(" Humidity  (%): ");
    Serial.println((float)DHT11.humidity,2);
    Serial.println();
    if(psval==LOW && (float)DHT11.temperature<=30){
      Serial.println("sunny\nGood to go out");
      // digitalWrite(LED_GREEN,HIGH);
      // digitalWrite(LED_RED,LOW);   
      // digitalWrite(LED_YELLOW,LOW);
      GB=255;
      //Serial.println("abcd");
      //delay(1000);
    }
    else if(psval==LOW && (float)DHT11.temperature<=35){
      Serial.println("HOT and sunny");
      Serial.println("Not recomended to go out in noon");
      // digitalWrite(LED_YELLOW,HIGH);
      // digitalWrite(LED_RED,LOW);
      // digitalWrite(LED_GREEN,LOW);
      YB=1;
      //delay(1000);
    }
    else if(psval==LOW && (float)DHT11.temperature>35){
      Serial.println("UV Radiation");
      Serial.println("Better to stay in room");
      // digitalWrite(LED_RED,HIGH);
      // digitalWrite(LED_YELLOW,LOW);
      // digitalWrite(LED_GREEN,LOW);
      //delay(1000);
      RB=1;
    }
    else if(psval==HIGH){
      Serial.println("Dark Night");
      // digitalWrite(LED_RED,HIGH);
      // digitalWrite(LED_YELLOW,HIGH);
      // digitalWrite(LED_GREEN,HIGH);
      //delay(2500);
      // digitalWrite(LED_RED,LOW);
      // digitalWrite(LED_YELLOW,LOW);
      // digitalWrite(LED_GREEN,LOW);
      //delay(1500);
      RB=1;
      YB=1;
      GB=255;
    }
  }
  else{
    RB=0;
    YB=0;
    GB=0;
    // digitalWrite(LED_RED,LOW);
    // digitalWrite(LED_YELLOW,LOW);
    // digitalWrite(LED_GREEN,LOW);
    //delay(1500);
  }
  analogWrite(LED_GREEN,GB);
  digitalWrite(LED_RED,RB);   
  digitalWrite(LED_YELLOW,YB);
  delay(2000);
}
