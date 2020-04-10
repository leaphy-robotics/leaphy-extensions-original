// Leahyoriginal1.cpp
// suitable for Fundumoto Shield
// Copyright Science4Kids& Stichting Leaphy 2018
// version 1.0.0    25 JULI 2018

#include "Leaphyoriginal1.h"

float getDistance()
{
    float duration, distance;
    int tries = 0;

    pinMode(US_TRIG, OUTPUT);
    digitalWrite(US_TRIG, LOW);
    delayMicroseconds(2);
    digitalWrite(US_TRIG, HIGH);
    delayMicroseconds(10);
    digitalWrite(US_TRIG, LOW);
        duration = pulseIn(US_ECHO, HIGH, 30000);
        distance = 0.034 * duration / 2;
    if(distance == 0 ){
      distance = distance + 1313;
    }


    return distance;
}

int getLineFollower(int fpSide)
{
    uint8_t pinLINE = fpSide == LEFT  ? LINE_LEFT :
                      fpSide == RIGHT ? LINE_RIGHT : -1;
    return digitalRead(pinLINE);
}

void setTone(int fpTone, int fpBeat)
{
    tone(TONE_PIN, fpTone, fpBeat);
}

void setMotor(int fpMotor, int fpSpeed)
{
    /* Select right pins for the given motor */
    uint8_t pinDIR = fpMotor == MOTOR_LEFT  ? M1_DIR :
                     fpMotor == MOTOR_RIGHT ? M2_DIR : -1;
    uint8_t pinPWM = fpMotor == MOTOR_LEFT  ? M1_PWM :
                     fpMotor == MOTOR_RIGHT ? M2_PWM : -1;
    /* Set DIR and PWM pins */
    pinMode(pinDIR, OUTPUT);
    pinMode(pinPWM, OUTPUT);
    uint8_t direction = fpSpeed > 0 ? 1 : 0;
    int speed = abs(fpSpeed);
    digitalWrite(pinDIR, direction);
    analogWrite(pinPWM, speed);
}

void moveMotors(int fpDirection, int fpSpeed)
{
    switch (fpDirection)
    {
        case FORWARD:
            setMotor(MOTOR_LEFT,   fpSpeed);
            setMotor(MOTOR_RIGHT,  fpSpeed);
            break;
        case BACKWARD:
            setMotor(MOTOR_LEFT,  -fpSpeed);
            setMotor(MOTOR_RIGHT, -fpSpeed);
            break;
        case LEFT:
            setMotor(MOTOR_LEFT,  -fpSpeed);
            setMotor(MOTOR_RIGHT,  fpSpeed);
            break;
        case RIGHT:
            setMotor(MOTOR_LEFT,   fpSpeed);
            setMotor(MOTOR_RIGHT, -fpSpeed);
            break;
    }
}

void setLed(int fpRed, int fpGreen, int fpBlue)
{
    analogWrite(LED1_RED, fpRed);
    analogWrite(LED1_GREEN, fpGreen);
    analogWrite(LED1_BLUE, fpBlue);
}
