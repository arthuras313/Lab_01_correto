#include <stdint.h>
#include <stdbool.h>
// includes da biblioteca driverlib
#include "inc/hw_memmap.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/systick.h"


uint8_t LED_D4 = 0;
uint32_t cont  = 0;


void main(void){


  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF); // Habilita GPIO F (LED D4 = PF0)
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)); // Aguarda final da habilitação
    
  GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4); // LED D4 como saída
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0); // LED D4 apagados
  GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_12MA, GPIO_PIN_TYPE_STD);



  while(1){

    for(cont=0; cont<1110000; cont++){     
   
  } 
  
  if(LED_D4==0){
      LED_D4 = 1;
  }else{
  LED_D4 = 0;
  }
  
  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, LED_D4);
  
  
  }
  
  // while
} // main