const int LED = 9; // the pin for the LED
const int BUTTON = 7; // input pin of the pushbutton
const int PHOTON_SENSOR = 2; // input pin of the photon sensor
//const int PTMR=A0; // Potentiometer input pin
int pval=0;
int brightness=0;
int val = 0; // stores the state of the input pin
int old_val = 0; // stores the previous value of "val"
int state = 0; // 0 = LED off while 1 = LED on

void setup() {
  pinMode(LED, OUTPUT); // tell Arduino LED is an output
  pinMode(BUTTON, INPUT); // and BUTTON is an input
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(BUTTON); // read input value and store it
  
  // check if there was a transition
  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state; // change the state from off to on or vice-versa
    delay(10);
  }
  
  old_val = val; // val is now old, let's store it
  
  if (state == 1) {
    brightness = digitalRead(PHOTON_SENSOR); // read the value from the photon sensor
    pval=analogRead(A0);
    if(brightness==LOW){
       brightness=pval/4;
      analogWrite(LED,pval/4); // turn LED ON at the current brightness level
    }
    else{
      if((pval/4)>5){
        analogWrite(LED,50);
        brightness=125;
      }
      else{
        analogWrite(LED,0);
        brightness=0;
      }
    }
    
    
   }
  else {
    analogWrite(LED, 0); // turn LED OFF
  }
  Serial.println(brightness);
}
