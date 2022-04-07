#ifndef PIRDOOR_H
#define PIRDOOR_H

#include <Arduino.h>
#include <Servo.h>
#include "timer.h"
#include "input_reading.h"
#include <avr/interrupt.h>


#define PIN_RC A1
extern Servo myservo;

extern int door_state;

void init_pir();
void pir_control_door();




#endif
