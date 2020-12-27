/**
  Generated Main Source File

  Company:
  ElectroniKa

  File Name:
    main.c

  Summary:
    This is the main file generated using PIC10 / PIC12 / PIC16 / PIC18 MCUs

  Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Product Revision  :  PIC10 / PIC12 / PIC16 / PIC18 MCUs - 1.81.6
        Device            :  PIC18F47Q43
        Driver Version    :  2.00
*/



#include "mcc_generated_files/mcc.h"
#include <math.h>

uint8_t     CTU1;
uint16_t    CTU2;   
uint8_t     Sinus[256];
float       Cal1,Cal2;

/*
                         Main application
 */
void main(void)
{
    // Initialize the device
    SYSTEM_Initialize();

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();
    for (CTU2=0; CTU2 <256 ; CTU2++)
    {
        uint8_t tmp;
        Cal1=(6.283185307/256)*CTU2;    
        Cal2=(1+(sin(Cal1)))*127.5;
        tmp=Cal2;
        Sinus[CTU2]=tmp;
     }
  
    while (1)
    {
        
        DAC1DATL=Sinus[CTU1++];
    }

    
}
/**
 End of File
*/