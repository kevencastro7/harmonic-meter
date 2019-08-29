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
//#include "port.h"
#include "led.h"
#include "kiss_fft.h"
#include "kiss_fftr.h"
#include "math.h"
#include "structs.h"
#include "spi.h"
#define PI 3.14159265359
int last_page_read = 0;
/* SCK = PA5, MOSI = PA7, MISO = PA6 */
controller* ct;
int main(void)
{
	ct = (controller *) malloc(sizeof(controller));
	//port_init();
	led_init();
	spi_init();
	irq0_init();
	led_write(LED6_PIN, configuracao_default());
	//port_sleep_ms(1000);

	while (1)
	{
	}
}

void DMA2_Stream2_IRQHandler(void)
{
	/* Clear DMA Stream Transfer Complete interrupt pending bit */
	DMA_ClearITPendingBit(DMA2_Stream2, DMA_FLAG_TCIF2);
	chip_deselect();
	irq0_init();
}

/* Handle PD0 interrupt */
void EXTI0_IRQHandler(void) {
    /* Make sure that interrupt flag is set */
    if (EXTI_GetITStatus(EXTI_Line0) != RESET) {
        /* Clear interrupt flag */
        EXTI_ClearITPendingBit(EXTI_Line0);
        int last_page = get_last_page();
    	dma_init( ct->bust_read, last_page);
    }
}
