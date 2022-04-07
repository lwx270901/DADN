#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include "timer.h"
#include "sensor.h"
#include "input_processing.h"
#include "input_reading.h"
#include "relay.h"
#include "pirdoor.h"

int x;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  setTimer2(10);
  timer_init();
  init_lcd();
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  init_pir();
}

void loop() {


 if (Serial.available() > 0)
 {
  x = Serial.readString().toInt();
 if(x == 1)
 {
  digitalWrite(7, HIGH);
 }
 else if(x == 0)
 {
  digitalWrite(7,LOW);
 }
 else if(x == 2)
 {
  myservo.write(0);
 }
 else if(x ==3)
 {
  myservo.write(180);
 }
 else if(x == 5)
 {
  digitalWrite(6, HIGH);
 }
 else if(x==4){
  digitalWrite(6, LOW);
 }
}
 
  
//    x = Serial.readString().toInt();
//  switch(x)
//    {
//      case 0:
//      enable_led = !enable_led;
//      ledstate = LOW;
//      pinMode(7, LOW);
//      Serial.print("!4:LED:0#");
//      break;
//      case 1:
//      enable_led = !enable_led;
//      ledstate = HIGH;
//      pinMode(7, HIGH);
//      Serial.print("!4:LED:1#");
//      break;
//      case 2:
//      door_state = LOW;
//      myservo.write(0);
//      Serial.print("!6:DOOR:2#");
//      break;
//      case 3:
//      door_state = HIGH;
//      myservo.write(0);
//      Serial.print("!6:DOOR:3#");
//      break;
//      case 4:
//      purifier_state = LOW;
//      digitalWrite(6, purifier_state);
//      Serial.print("!5:FAN:4#");
//      break;
//      case 5:
//      purifier_state = HIGH;
//      digitalWrite(6, purifier_state);
//      Serial.print("!5:FAN:5#");
//      break;
//      default:
//      break;
//    }
  





// put your main code here, to run repeatedly:
  fsm_for_input_processing();
  fsm_for_button2();
  pir_control_door();

//    Serial.print("!4:LED:");
//        Serial.print(ledstate);
//        Serial.print("#");
//
//     Serial.print("!5:FAN:");
//  Serial.print(purifier_state + 4);
//  Serial.print("#");
//    
//        Serial.print("!6:DOOR:");
//  Serial.print(door_state + 2);
//  Serial.print("#");
  
 
  
  if(timer2_flag == 1){
    display_dht();
    setTimer2(10000);
  }








  
}
