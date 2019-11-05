/*
 * Copyright 2016-2019 NXP
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 *
 * o Redistributions of source code must retain the above copyright notice, this list
 *   of conditions and the following disclaimer.
 *
 * o Redistributions in binary form must reproduce the above copyright notice, this
 *   list of conditions and the following disclaimer in the documentation and/or
 *   other materials provided with the distribution.
 *
 * o Neither the name of NXP Semiconductor, Inc. nor the names of its
 *   contributors may be used to endorse or promote products derived from this
 *   software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
 * ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
 * ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
 
/**
 * @file    testk22.c
 * @brief   Application entry point.
 */
#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MK22F51212.h"
#include "fsl_gpio.h"
/* TODO: insert other include files here. */

/* TODO: insert other definitions and declarations here. */
static void delay(int volatile i){
	while(i>0){
		__asm ("nop");
		i--;
	}


}

void decToBinary(int n)
{
    int binaryNum[4]={0,0,0,0};


    int i = 3;
    while (n > 0) {


        binaryNum[i] = n % 2;
        n = n / 2;
        i--;


   }


    //led1 toggle
    if (binaryNum[0]==1)
    {
    	 GPIO_PortSet(BOARD_INITPINS_led1_GPIO,(1<< BOARD_INITPINS_led1_PIN));


    }
    else
    {
    	GPIO_PortClear(BOARD_INITPINS_led1_GPIO,(1<< BOARD_INITPINS_led1_PIN));

    }

    //led2 toggle
    if (binaryNum[1]==1)
    {
    	 GPIO_PortSet(BOARD_INITPINS_led2_GPIO,(1<< BOARD_INITPINS_led2_PIN));


    }
    else
    {
    	GPIO_PortClear(BOARD_INITPINS_led2_GPIO,(1<< BOARD_INITPINS_led2_PIN));

    }
    //led3 toggle
    if (binaryNum[2]==1)
    {
    	 GPIO_PortSet(BOARD_INITPINS_led3_GPIO,(1<< BOARD_INITPINS_led3_PIN));


    }
    else
    {
    	GPIO_PortClear(BOARD_INITPINS_led3_GPIO,(1<< BOARD_INITPINS_led3_PIN));

    }

   //led4 toggle
    if (binaryNum[3]==1)
    {
    	 GPIO_PortSet(BOARD_INITPINS_led4_GPIO,(1<< BOARD_INITPINS_led4_PIN));


    }
    else
    {
    	GPIO_PortClear(BOARD_INITPINS_led4_GPIO,(1<< BOARD_INITPINS_led4_PIN));

    }
    delay(2000000);
    GPIO_PortClear(BOARD_INITPINS_led1_GPIO,(1<< BOARD_INITPINS_led1_PIN));
    GPIO_PortClear(BOARD_INITPINS_led2_GPIO,(1<< BOARD_INITPINS_led2_PIN));
    GPIO_PortClear(BOARD_INITPINS_led3_GPIO,(1<< BOARD_INITPINS_led3_PIN));
    GPIO_PortClear(BOARD_INITPINS_led4_GPIO,(1<< BOARD_INITPINS_led4_PIN));
    delay(4000000);
}
/*
 * @brief   Application entry point.
 */
int main(void) {
  	/* Init board hardware. */
     BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();

    printf("Hello World\n");

    /* Force the counter to be placed into memory. */
    /* Enter an infinite loop, just incrementing a counter. */
    for (int i=0;i<16;i++)
{
    	decToBinary(i);
    	if(i==15)
    	{
    		i=0;
    	}

}
    return 0 ;
}
