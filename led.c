/*
 * File:   led.c
 * Author: Megha Agarwal
 * Description: Lab 0 Part 2.
 * Created on February 2, 2016.
 */

#include <xc.h>
#include "led.h"
#define OUTPUT 0
#define INPUT 1

void initLEDs(){
    LATDbits.LATD0 =1;
    TRISDbits.TRISD0 = OUTPUT;
    LATDbits.LATD1 = 1;
    TRISDbits.TRISD1 = OUTPUT;
    LATDbits.LATD2= 1;
    TRISDbits.TRISD2 = OUTPUT;
}
