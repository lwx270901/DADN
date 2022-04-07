#include "input_reading.h"
// we aim to work with more than one buttons
#define N0_OF_BUTTONS 2
# define DURATION_FOR_AUTO_INCREASING 100
# define BUTTON_IS_PRESSED LOW
# define BUTTON_IS_RELEASED HIGH
static int buttonBuffer [ N0_OF_BUTTONS ];
// we define two buffers for debouncing
static int debounceButtonBuffer1 [ N0_OF_BUTTONS ];
static int debounceButtonBuffer2 [ N0_OF_BUTTONS ];
// chong rung 3 lan
static int flagForButtonPress1s [ N0_OF_BUTTONS ];
static int counterForButtonPress1s [ N0_OF_BUTTONS ];

void button_reading ()
{
  for ( int i = 0; i < N0_OF_BUTTONS ; i ++){
    int pin = 3+i;
    debounceButtonBuffer2 [i] = debounceButtonBuffer1 [i];
    debounceButtonBuffer1 [i] = digitalRead(pin);
    if( debounceButtonBuffer1 [i] == debounceButtonBuffer2 [i])
    {
      buttonBuffer [i] = debounceButtonBuffer1 [i];
      if( buttonBuffer [i] == BUTTON_IS_PRESSED ){
        // if a button is pressed , we start counting
        if( counterForButtonPress1s [i] < DURATION_FOR_AUTO_INCREASING ){
          counterForButtonPress1s [i ]++;
        }
        else {
          // the flag is turned on when 1 second has passed
          // since the button is pressed .
          flagForButtonPress1s [i] = 1;
          //todo
        }
      }
      else
      {
        counterForButtonPress1s [i] = 0;
        flagForButtonPress1s [i] = 0;
      }
    }
  }
}


int is_button_pressed( int index )
{
  return ( buttonBuffer [ index ] == BUTTON_IS_PRESSED );
}
int is_pir_pressed( int index )
{
  return ( buttonBuffer [ index ] == BUTTON_IS_RELEASED);
}

int is_button_pressed_1s(int index){
  return ( flagForButtonPress1s [ index ] == 1);
}
