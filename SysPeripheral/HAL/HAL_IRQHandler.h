#ifndef  __HAL_IRQ_HANDLER_H
#define  __HAL_IRQ_HANDLER_H

#include "chip.h"

typedef enum
{
    //系统滴答
    IRQ_TRG_SYSTICK_UPDATE = 0,
    IRQ_TRG_SYSTICK_OS,
    
    IRQ_TRG_PVD,
    IRQ_TRG_RTC,
    IRQ_TRG_FLASH,
    IRQ_TRG_RCC,
    IRQ_TRG_EXTI0_1,
    IRQ_TRG_EXTI2_3,
    IRQ_TRG_EXTI4_15,
    IRQ_TRG_TS,
    IRQ_TRG_DMA1_Channel1,
    IRQ_TRG_DMA1_Channel2_3,
    IRQ_TRG_DMA1_Channel4_5,
    IRQ_TRG_ADC1_COMP,
    IRQ_TRG_TIM1_BRK_UP_TRG_COM,
    IRQ_TRG_TIM1_CC,
    IRQ_TRG_TIM2,
    IRQ_TRG_TIM3,
    IRQ_TRG_TIM6_DAC,
    IRQ_TRG_TIM14,
    IRQ_TRG_TIM15,
    IRQ_TRG_TIM16,
    IRQ_TRG_TIM17,
    IRQ_TRG_I2C1,
    IRQ_TRG_I2C2,
    IRQ_TRG_SPI1,
    IRQ_TRG_SPI2,
    IRQ_TRG_USART1,
    IRQ_TRG_USART2,
    
}IRQ_TRIGGER_SOURCE;


#ifdef __cplusplus
extern "C" {
#endif


/**
  * @brief  空指针入口
  * @param  None
  * @retval None
  */
void HAL_IRQ_NullEntry(void);


/**
  * @brief  中断回调指针初始化
  * @param  None
  * @retval None
  */
void HAL_IRQ_Init(void);


/**
  * @brief  设置中断触发回调
  * @param  ptr 回调指针
  * @param  ulTrgSource 触发源
  * @retval None
  */
void HAL_IRQ_SetTrgCallback(void (*ptr)(void), uint32_t ulTrgSource);


/**
  * @brief  释放中断触发回调
  * @param  ulTrgSource 触发源
  * @retval None
  */
void HAL_IRQ_ReleaseTrgCallback(uint32_t ulTrgSource);


#ifdef __cplusplus
}
#endif

#endif /* __HAL_IRQ_HANDLER_H */
