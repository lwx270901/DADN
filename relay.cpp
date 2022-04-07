#include "relay.h"

static int state = 0;
void fsm_for_button2 ()
{
  switch(state)
  {
    case 0:
    if(is_button_pressed (1))
    {
      state = 1;
    }
    break;
    case 1:
    if(!is_button_pressed (1))
    {
      purifier_state = !purifier_state;
      digitalWrite(6, purifier_state);
      state = 2;
     Serial.print("!5:FAN:");
    Serial.print(purifier_state + 4);
    Serial.print("#");
      
    }
    break;
    case 2:
    if(is_button_pressed (1))
    {
      state = 3;
    }
    break;
    case 3:
    if(!is_button_pressed (1)){
      purifier_state = !purifier_state;
      digitalWrite(6, purifier_state);
      state = 0;
      Serial.print("!5:FAN:");
  Serial.print(purifier_state + 4);
  Serial.print("#");
    }
    break;
    default:
    break;
  }
  
}
