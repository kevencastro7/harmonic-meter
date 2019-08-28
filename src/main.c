/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "port.h"
#include "led.h"
#include "kiss_fft.h"
#include "kiss_fftr.h"
#include "math.h"
#include "structs.h"
#include "spi.h"
#define PI 3.14159265359

int main(void)
{
	port_init();
	led_init();
	spi_init();
	/* SCK = PA5, MOSI = PA7, MISO = PA6 */
	irq0_init();
	led_write(GPIO_Pin_All, configuracao_default());
	port_sleep_ms(1000);
	while (1)
	{
	}
}

void DMA2_Stream2_IRQHandler(void)
{
/* Clear DMA Stream Transfer Complete interrupt pending bit */
DMA_ClearITPendingBit(DMA2_Stream2, DMA_FLAG_TCIF2);
chip_deselect();


}

/* Handle PD0 interrupt */
void EXTI0_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    //if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        /* Do your stuff when PD0 is changed */

        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line0);
    	irq0_init();
    //}
}
