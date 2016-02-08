/*
 * File:   main.c
 * Author: Megha Agarwal
 * Description: Lab 0 Part 2.
 * Created on February 2, 2016.
 */

#include <xc.h>
#include <sys/attribs.h>
#include "timer.h"
#include "led.h"
#include "switch.h"
#include "interrupt.h"
#include "config.h"

#define OUTPUT 0
#define INPUT 1

typedef enum stateTypeEnum{
    s1,s2,s3, none
} stateType;

volatile stateType state = s1;
volatile stateType next = s2;
volatile stateType prev = s3;
volatile int flag;

int main() {
    SYSTEMConfigPerformance(10000000);    //Configures low-level system parameters for 10 MHz clock
    enableInterrupts();                   //This function is necessary to use interrupts.
    initLEDs();
    initSW1();
    initTimer1();

    while(1){
        switch(state){
            case s1:
                next = s2;
                prev = s3;
                LATDbits.LATD0 = 1;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 0;
                break;
            case s2:
                next = s3;
                prev = s1;
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 1;
                LATDbits.LATD2 = 0;
                break;
            case s3:
                next = s1;
                prev = s2;
                LATDbits.LATD0 = 0;
                LATDbits.LATD1 = 0;
                LATDbits.LATD2 = 1;
                break;
            case none:
                break;
        }
    }
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL7SRS) _T1Interrupt(){
    IFS0bits.T1IF = 0;
    flag = 1;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) _CNInterrupt( void ){
    IFS1bits.CNDIF = 0;
    if(SW1 == 0) {
        flag = 0;
        TMR1 = 0;
        state = none;
    }
    else if(SW1 == 1)
    {
        if(flag == 0)
            state = next;
        else if(flag == 1)
            state = prev;
    }
}
