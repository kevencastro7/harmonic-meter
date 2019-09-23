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
#include "led.h"
#include "fft.h"
#include "math.h"
#include "structs.h"
#include "spi.h"
#define PI 3.14159265359
/* SCK = PA5, MOSI = PA7, MISO = PA6 */
controller* ct;
int main(void)
{
	ct = (controller *) malloc(sizeof(controller));
	ct->count = 0;
	led_init();
	spi_init();
	init_fft();
	led_write(LED6_PIN, configuracao_default());
	irq0_init();

	while (1)
	{
		if (ct->full_buffer == 1)
		{
			ct->full_buffer = 0;
			led_write(LED5_PIN, ct->buffer);
		}
	}
}

void DMA2_Stream2_IRQHandler(void)
{
	/* Clear DMA Stream Transfer Complete interrupt pending bit */
	DMA_ClearITPendingBit(DMA2_Stream2, DMA_FLAG_TCIF2);
	chip_deselect();
	led_write(LED3_PIN, 1);
	burst_to_buffer(ct);
	irq0_init();
}

/* Handle PD0 interrupt */
void EXTI0_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line0);
        int last_page = get_last_page();
        led_write(LED4_PIN, last_page);
    	dma_init( ct->burst_read, last_page);
    }
}
