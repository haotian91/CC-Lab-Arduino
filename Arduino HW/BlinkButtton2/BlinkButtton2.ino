/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led = 13;
int buttonPin = 2;
int buttonState = 0;
int ledState = -1;
long lastDebounceTime = 0;
long debounceDelay = 200;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  pinMode(buttonPin, OUTPUT);  
}

// the loop routine runs over and over again forever:
void loop() {
  buttonState = digitalRead(buttonPin);
  
  if((millis()-lastDebounceTime)>debounceDelay){
    if(buttonState == HIGH && ledState<0){
      digitalWrite(led,HIGH);
      ledState= -ledState;
      lastDebounceTime=millis();
    }
    else if(buttonState ==HIGH && ledState>0){
      digitalWrite(led,LOW);
      ledState= -ledState;
      lastDebounceTime=millis();
    }
  }
//  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
//  delay(1000);               // wait for a second
//  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
//  delay(1000);               // wait for a second
}
