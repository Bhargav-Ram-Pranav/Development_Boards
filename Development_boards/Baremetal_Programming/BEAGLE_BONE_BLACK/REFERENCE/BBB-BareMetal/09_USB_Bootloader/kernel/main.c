/**
 * @file main.c
 * @author Alexis Marquet
 * @date 21 May 2015
 * @brief contains the main application
 **/


/**
 * @mainpage
 * 09_USB_Bootloader: This example implements a USB DFU bootloader. the device is connected via the mini USB port on the board (USB0) and 
 * enumerates itself as a DFU capable device. you then need to use dfu-util (http://dfu-util.sourceforge.net/) to download your code to the device.
 * The code is launched from 0x80000000, like it was in 07_Bootloader. This bootloader is about 20 times faster than the previous one, which was 
 * run via UART0.
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../core/llma.h"
#include "../proc/clock_module.h"
#include "../proc/interrupt.h"
#include "../proc/USB.h"
#include "../board/LED.h"
#include "../sys/DFU.h"
#include "../sys/types.h"
int main ()
{
   CPU_irqE();
   USB_init();
   
   printf("USB DFU bootloader ready, send FW using \"dfu-util -D <file>\"\n");
   
   while(!DFU_update_ready){
      asm volatile ("wfi \n");
   }
   
   printf("about to branchhhhh\n");
   LED_setValue(0x0);
   CPU_irqD();
   BRANCHTO(0x80000000);
   return 0;
}
