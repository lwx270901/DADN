#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "MQ135.h"    //gọi thư viện MQ135
#include "DHT.h"      //gọi thư viện DHT11
#include "input_processing.h"
#define PIN_MQ135 A2
#define PIN_LIGHT A0
#include "timer.h"

extern int purifier_state;
extern boolean enable_led;

void init_lcd();
void display_dht();
#endif
