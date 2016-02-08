/*
 * File:   timer.c
 * Author: Megha Agarwal
 * Description: Lab 0 Part 2.
 * Created on February 2, 2016.
 */

#include <xc.h>
#include "switch.h"

#define INPUT 1
#define OUTPUT 0


void initSW1(){
    TRISDbits.TRISD6 = INPUT;   // Enable input for switch
    CNCONDbits.ON = 1;          // Turn on CN device
    CNENDbits.CNIED6 = 1;       // Enable CN interrupt for pin
    IEC1bits.CNDIE = 1;         // Enable overall CN Interrupt
    IFS1bits.CNDIF = 0;         // Put Interrupt flag down
    CNPUDbits.CNPUD6 = 1;        // Enable Internal Pull-up resistor
    IPC8bits.CNIP = 7;
   // IPC8bits.CNIS = 3; //subpriority
}
