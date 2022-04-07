#ifndef INC_INPUT_PROCESSING_H
#define INC_INPUT_PROCESSING_H
#include <Arduino.h>
#include <avr/interrupt.h>
#include "input_reading.h"
#include "timer.h"


extern int ledstate;
void fsm_for_input_processing ();
void increase_timer();

#endif /* INC_INPUT_PROCESSING_H_ */
