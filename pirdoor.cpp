#include "pirdoor.h"

Servo myservo;
int door_state = LOW;
int val = 0;
static int state = 0;


void init_pir()
{
  myservo.attach(PIN_RC);
}
void pir_control_door()
{
  switch(state)
  {
    case 0:
    if(digitalRead(5) == HIGH){
      door_state = !door_state;
      myservo.write(180);
      state = 1;
      Serial.print("!6:DOOR:3#");
    }
    break;
    case 1:
    if(digitalRead(5) == LOW){
      door_state = !door_state;
      myservo.write(0);
      state = 0;
      Serial.print("!6:DOOR:2#");
    }
    break;
    default:
    break;
  }
}
