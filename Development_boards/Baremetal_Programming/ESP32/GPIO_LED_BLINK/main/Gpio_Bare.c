#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#define GPIO_SET 0x3ff44008
#define GPIO_CLEAR 0x3ff4400c
#define GPIO_ENABLE 0x3ff44020
void app_main(void)
{
	volatile unsigned int *enable =(volatile unsigned int *)GPIO_ENABLE;
	volatile unsigned int *set =(volatile unsigned int *)GPIO_SET;
	volatile unsigned int *clear =(volatile unsigned int *)GPIO_CLEAR;
	*enable = (1<<22);
	int i;

	while(1)
	{
		*set =(1<<22);
		 vTaskDelay(pdMS_TO_TICKS(1000));
		
		*clear =(1<<22);
		 vTaskDelay(pdMS_TO_TICKS(1000));
		
	}


}
