#include "input_processing.h"


static int counter_led = 0;

enum ButtonState { BUTTON_RELEASED , BUTTON_PRESSED , BUTTON_PRESSED_MORE_THAN_1_SECOND } ;
enum ButtonState buttonState = BUTTON_RELEASED ;
int ledstate = LOW; 
void fsm_for_input_processing ()
{
  switch ( buttonState )
  {
    case BUTTON_RELEASED :
    if( is_button_pressed (0))
    {
      buttonState = BUTTON_PRESSED ;
    }
    break;
    case BUTTON_PRESSED :
    if (!is_button_pressed (0))
    {
      buttonState = BUTTON_RELEASED ;
      ledstate = !ledstate;
      digitalWrite(7,ledstate);
      Serial.print("!4:LED:");
        Serial.print(ledstate);
        Serial.print("#");
      
    }
    else
    {
      if( is_button_pressed_1s(0) )
      {
        buttonState = BUTTON_PRESSED_MORE_THAN_1_SECOND ;
        ledstate = !ledstate;
        digitalWrite(7,ledstate);
        Serial.print("!4:LED:");
        Serial.print(ledstate);
        Serial.print("#");
        counter_led= 0;
      }
    }
    break;
    case BUTTON_PRESSED_MORE_THAN_1_SECOND :
    if (!is_button_pressed (0))
    {
      buttonState = BUTTON_RELEASED ;
    }
    if(counter_led == 100)
    {
      ledstate = !ledstate;
        digitalWrite(7,ledstate);
        Serial.print("!4:LED:");
        Serial.print(ledstate);
        Serial.print("#");
        counter_led = 0;
    }
    
    // todo
    break;
  }
}
void increase_timer()
{
  if(counter_led < 100)
  {
    counter_led++;
  }
}
