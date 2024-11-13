
#include "stm8s.h"
#include "data.h"
#include "stm8s_exti.h"



void Delay(uint16_t ms){
    uint32_t t = (F_CPU/11000UL)*ms;

    while(t)
        t--;
}


void main(void)
{
  /* Initialize I/Os in Output Mode */
  GPIO_Init(GPIOB, (GPIO_Pin_TypeDef)GPIO_PIN_5, GPIO_MODE_OUT_PP_LOW_FAST);
  GPIO_Init(GPIOA, (GPIO_Pin_TypeDef)GPIO_PIN_1, GPIO_MODE_OUT_PP_LOW_FAST);
  
  GPIO_Init(GPIOC, (GPIO_Pin_TypeDef)GPIO_PIN_3, GPIO_MODE_IN_PU_IT);
  
  disableInterrupts();
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOC, EXTI_SENSITIVITY_FALL_ONLY);
  enableInterrupts();
  // GPIO_WriteLow(GPIOD, (GPIO_Pin_TypeDef)GPIO_PIN_5);
  while (1)
  {
    /* Toggles LEDs */
    GPIO_WriteReverse(GPIOB, (GPIO_Pin_TypeDef)GPIO_PIN_5);
        // GPIO_WriteReverse(GPIOA, (GPIO_Pin_TypeDef)GPIO_PIN_1);
    if (statusButton==0){
        GPIO_WriteHigh(GPIOA, (GPIO_Pin_TypeDef)GPIO_PIN_1);
        Delay(100);
        GPIO_WriteLow(GPIOA, (GPIO_Pin_TypeDef)GPIO_PIN_1 );
           statusButton=1;
           EXTI_DeInit();
    }
    Delay(10);
    
       }

}


#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/