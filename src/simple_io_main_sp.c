#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h> 
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"




void main(void){
  SysTickPeriodSet(12000000); // f = 1Hz para clock = 24MHz
  
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
  
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4); // LED4 como SAÍDA
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, 0); // LED APAGADO
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0 | GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);

  SysTickIntEnable();
  SysTickEnable();
  uint8_t LED4 = 0;
  time_t cont1,cont2;


  while(1){
	      
       time( &cont1 );
       do{
         time( &cont2 );
         }
       while(difftime(cont2, cont1) < 1); // Verifica se passou 1 segundo
  
        
        if(LED4 == 1) // Verifica o estado e altera (acende ou apaga o LED4)
        {
          LED4 = 0;
        }
        else
        {
          LED4 = 1;
        }
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED4);
        
  } // while
} // main