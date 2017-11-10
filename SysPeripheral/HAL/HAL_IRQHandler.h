#ifndef  __HAL_IRQ_HANDLER_H
#define  __HAL_IRQ_HANDLER_H


typedef struct 
{
    void (*pf_SysTick_Update                )(void);
    void (*pf_SysTick_Handler               )(void);
    void (*pf_PVD_IRQHandler                )(void);
    void (*pf_RTC_IRQHandler                )(void);
    void (*pf_FLASH_IRQHandler              )(void);
    void (*pf_RCC_IRQHandler                )(void);
    void (*pf_EXTI0_1_IRQHandler            )(void);
    void (*pf_EXTI2_3_IRQHandler            )(void);
    void (*pf_EXTI4_15_IRQHandler           )(void);
    void (*pf_TS_IRQHandler                 )(void);
    void (*pf_DMA1_Channel1_IRQHandler      )(void);
    void (*pf_DMA1_Channel2_3_IRQHandler    )(void);
    void (*pf_DMA1_Channel4_5_IRQHandler    )(void);
    void (*pf_ADC1_COMP_IRQHandler          )(void);
    void (*pf_TIM1_BRK_UP_TRG_COM_IRQHandler)(void);
    void (*pf_TIM1_CC_IRQHandler            )(void);
    void (*pf_TIM2_IRQHandler               )(void);
    void (*pf_TIM3_IRQHandler               )(void);
    void (*pf_TIM6_DAC_IRQHandler           )(void);
    void (*pf_TIM14_IRQHandler              )(void);
    void (*pf_TIM15_IRQHandler              )(void);
    void (*pf_TIM16_IRQHandler              )(void);
    void (*pf_TIM17_IRQHandler              )(void);
    void (*pf_I2C1_IRQHandler               )(void);
    void (*pf_I2C2_IRQHandler               )(void);
    void (*pf_SPI1_IRQHandler               )(void);
    void (*pf_SPI2_IRQHandler               )(void);
    void (*pf_USART1_IRQHandler             )(void);
    void (*pf_USART2_IRQHandler             )(void);
    
}STM32F0XX_IRQ_INTERFACE;

extern STM32F0XX_IRQ_INTERFACE  g_IRQInterface;

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


#ifdef __cplusplus
}
#endif

#endif /* __HAL_IRQ_HANDLER_H */
