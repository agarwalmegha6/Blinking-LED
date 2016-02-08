/*
 * File:   timer.c
 * Author: Megha Agarwal
 * Description: Lab 0 Part 2.
 * Created on February 2, 2016.
 */

#include <xc.h>
#include "timer.h"

void initTimer1(){
    TMR1 = 0;// clear TMR1
    PR1 = 39061;// Initialize PR1
    T1CONbits.TCKPS = 3; // Initialize pre-scalar
    IEC0bits.T1IE = 1;// Enable the interrupt
    IFS0bits.T1IF = 0;// Put the flag down
    IPC1bits.T1IP = 7;// Configure the Interrupt Priority
    T1CONbits.TON = 1;// Turn the timer on
    //IPC1bits.T1IS = 3;
   //T1CONbits.TCS = 0;
}

/*void initTimer2(){
    TMR2 = 0;
    T2CONbits.TCKPS = 0;
    T2CONbits.TCS = 0;
    IFS0bits.T2IF = 0;
}

void delayMs(unsigned int delay){
    TMR2 = 0;
    PR2 = delay*624;
    IFS0bits.T2IF = 0;
    T2CONbits.ON = 1;
    while(IFS0bits.T2IF == 0);
    T2CONbits.ON = 0;
}

void resetTimer1(){
    TMR1 = 0;
    T1CONbits.ON = 0;
}
 */
