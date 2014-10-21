#define SERVOPINLIFT  2
#define SERVOPINLEFT  3
#define SERVOPINRIGHT 4

#define trigPin 9
#define echoPin 8

#include <Servo.h>

Servo servo1;  // 
Servo servo2;  // 
Servo servo3;  // 

void setup()
{
  Serial.begin(9600);
  servo1.attach(SERVOPINLIFT);  //  lifting servo
  servo2.attach(SERVOPINLEFT);  //  left servo
  servo3.attach(SERVOPINRIGHT);  //  right servo
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  
   servo1.write(25);
   servo2.write(30);  
   servo3.write(150);
  
}

void loop()
{
  Serial.begin(9600);
  
  int duration,distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin,LOW);
  duration=pulseIn(echoPin,HIGH);
  distance=(duration/2)/29.1;
  Serial.println(distance);
  delay(100);
  

//up down 
  if(distance>37){
     servo2.write(30);  
     servo3.write(150);
     delay(15);
  }

  if(distance>27 && distance<=37){
    for(int i=20; i<50; i+=1)
    {
      servo2.write(i);
      servo3.write(180-i);
      delay(15);
    }
    
     for(int i=50; i>20; i-=1)
    {
      servo2.write(i);
      servo3.write(180-i);
      delay(15);
    }
  }

//left right  
  if(distance>20 && distance<=27){
    for(int i=85; i>20; i-=1)
    {
      servo2.write(i);
      servo3.write(180+i-85);
      delay(15);
    }
    for(int i=20; i<85; i+=1)
    {
      servo2.write(i);
      servo3.write(180+i-85);
      delay(15);
    }
  }

//rectangle
  if(distance>10 && distance<=20){
   for(int i=85; i>45; i-=1)
    {
      servo2.write(i);
      servo3.write(160+(0.37*(85-i)));
      delay(15);
    } 
  for(int i=45; i>15; i-=1)
    {
      servo2.write(i);
      servo3.write(175+i-45);
      delay(15);
    }
  for(int i=15; i<40; i+=1)
    {
      servo2.write(i);
      servo3.write(145-i+15);
      delay(15);
    }
  for(int i=40; i<85; i+=1)
    {
      servo2.write(i);
      servo3.write(120+(i-35)*0.7);
      delay(15);
    } 
  }
  
//???
  if(distance>0 && distance<=10){
   for(int i=65; i>30; i-=1)
      {
        servo2.write(i);
        servo3.write(168-(0.5*(65-i)));
        delay(15);
      } 
    for(int i=30; i>25; i-=1)
      {
        servo2.write(i);
        servo3.write(150-4.4*(30-i));
        delay(15);
      }
    for(int i=25; i<62.5; i+=1)
      {
        servo2.write(i);
        servo3.write(128+0.4*(62.5-i));
        delay(15);
      }
    for(int i=62.5; i<65; i+=1)
      {
        servo2.write(i);
        servo3.write(143+10*(65-i));
        delay(15);
      } 
  }
     
  Serial.println(distance);
}


