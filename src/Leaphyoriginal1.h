// Leaphyoriginal1.h
// suitable for Fundumoto Shield
// Copyright Science4Kids 2017
// version 1.0.0    1 February 2017
#ifndef LEAPHYORIGINAL1_H_
#define LEAPHYORIGINAL1_H_

#include <Arduino.h>
#include <avr/interrupt.h>
#include <avr/io.h>
#include "wiring_private.h"
#ifndef F_CPU
#define  F_CPU 16000000UL
#endif
#include <util/delay.h>
#include <stdint.h>
#include <stdlib.h>

#define MOTOR_LEFT      (9)     // M1
#define MOTOR_RIGHT     (10)    // M2
#define TRUE            (1)
#define FALSE           (0)
#define FORWARD         (1)
#define BACKWARD        (2)
#define LEFT            (3)
#define RIGHT           (4)

// PIN definitions for Fundumoto L298P motor shield with built in buzzer
#define TONE_PIN        (4)     // DIG-OUT
#define LED1_RED        (6)     // PWM-OUT
#define LED1_GREEN      (5)     // PWM-OUT
#define LED1_BLUE       (3)     // PWM-OUT
#define LINE_LEFT       (16)    // DIG-IN       A2 tinkerkit In2
#define LINE_RIGHT      (17)    // DIG-IN       A3 tinkerkit In3

struct {
    int m1_pwm = 10;
    int m1_dir = 12;
    int m2_pwm = 11;
    int m2_dir = 13;
} motor_pins;

struct {
    int echo = 8;
    int trig = 7;
} us_pins;

void setMotorPins(int m1_pwm, int m1_dir, int m2_pwm, int m2_dir);
void setUSPins(int echo, int trig);
float getDistance();
int getLineFollower(int fpSide);
void setTone( int fpTone, int fpBeat);
void setMotor(int fpMotor, int fpSpeed);
void moveMotors(int fpDirection, int fpSpeed);
void setLed(int fpRed, int fpGreen, int fpBlue);

#endif
