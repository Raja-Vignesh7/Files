#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;
const int LED=13;
const int touch_sensor=8; //Note : vcc of the module should connect to 3.3v pin in arduino
int state=0;
int val;
int old_val=LOW;

void setup() {
  pinMode(LED,OUTPUT);
  pinMode(touch_sensor,INPUT);
  Serial.begin(9600);
}

void loop() {
  val=digitalRead(touch_sensor);
  if(val==HIGH && old_val==LOW){
    state=1-state;
    delay(50);
  }
  old_val=val;
  if(state==1){
    digitalWrite(LED,HIGH);
    Serial.println();

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Humidity (%): ");
  Serial.println((float)DHT11.humidity, 2);

  Serial.print("Temperature  (C): ");
  Serial.println((float)DHT11.temperature, 2);

  delay(1000);

  }
  else{
    digitalWrite(LED,LOW);
  }
}
