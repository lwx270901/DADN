#ifndef INPUT_READING_H
#define INPUT_READING_H

#include <Arduino.h>
#include <avr/interrupt.h>
#include "timer.h"
#include "input_processing.h"

void button_reading ();
int is_button_pressed(int index);
int is_button_pressed_1s(int index);
int is_pir_pressed( int index );

# endif /* INC_INPUT_READING_H_ */
