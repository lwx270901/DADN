#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <avr/interrupt.h>
#include "input_reading.h"
#include "input_processing.h"

extern int timer2_counter;
extern int timer2_flag;



void setTimer2(int duration);
void timer2_run();
void setNew(int duration);

ISR (TIMER2_OVF_vect); //Chương trình ngắt Timer2
void timer_init();
#endif
