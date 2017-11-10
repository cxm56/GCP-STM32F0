/**
  ******************************************************************************
  * @file    HAL_IRQHandler.c
  * @author  Duhanfneg
  * @version V1.0 
  * @date    2017.08.08
  * @brief   LPC17xx IRQ Callback Funtion interface
  ******************************************************************************
  * @attention
  * 
  * 
  ******************************************************************************
  */
  
/***********************************<INCLUDES>**********************************/
#include "chip.h"
#include "HAL_IRQHandler.h"



STM32F0XX_IRQ_INTERFACE  g_IRQInterface;  //全局中断回调指针接口


/**
  * @brief  空指针入口
  * @param  None
  * @retval None
  */
void HAL_IRQ_NullEntry(void){}


/**
  * @brief  中断回调指针初始化
  * @param  None
  * @retval None
  */
void HAL_IRQ_Init(void)
{
    g_IRQInterface.pf_SysTick_Update         = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_SysTick_Handler        = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_PVD_IRQHandler                 = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_RTC_IRQHandler                 = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_FLASH_IRQHandler               = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_RCC_IRQHandler                 = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_EXTI0_1_IRQHandler             = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_EXTI2_3_IRQHandler             = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_EXTI4_15_IRQHandler            = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TS_IRQHandler                  = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_DMA1_Channel1_IRQHandler       = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_DMA1_Channel2_3_IRQHandler     = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_DMA1_Channel4_5_IRQHandler     = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_ADC1_COMP_IRQHandler           = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM1_BRK_UP_TRG_COM_IRQHandler = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM1_CC_IRQHandler             = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM2_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM3_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM6_DAC_IRQHandler            = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM14_IRQHandler               = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM15_IRQHandler               = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM16_IRQHandler               = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_TIM17_IRQHandler               = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_I2C1_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_I2C2_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_SPI1_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_SPI2_IRQHandler                = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_USART1_IRQHandler              = HAL_IRQ_NullEntry;
    g_IRQInterface.pf_USART2_IRQHandler              = HAL_IRQ_NullEntry;
    
}



/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
    g_IRQInterface.pf_SysTick_Update();
    g_IRQInterface.pf_SysTick_Handler();
    
}

void PVD_IRQHandler                 (void){g_IRQInterface.pf_PVD_IRQHandler                ();}
void RTC_IRQHandler                 (void){g_IRQInterface.pf_RTC_IRQHandler                ();}
void FLASH_IRQHandler               (void){g_IRQInterface.pf_FLASH_IRQHandler              ();}
void RCC_IRQHandler                 (void){g_IRQInterface.pf_RCC_IRQHandler                ();}
void EXTI0_1_IRQHandler             (void){g_IRQInterface.pf_EXTI0_1_IRQHandler            ();}
void EXTI2_3_IRQHandler             (void){g_IRQInterface.pf_EXTI2_3_IRQHandler            ();}
void EXTI4_15_IRQHandler            (void){g_IRQInterface.pf_EXTI4_15_IRQHandler           ();}
void TS_IRQHandler                  (void){g_IRQInterface.pf_TS_IRQHandler                 ();}
void DMA1_Channel1_IRQHandler       (void){g_IRQInterface.pf_DMA1_Channel1_IRQHandler      ();}
void DMA1_Channel2_3_IRQHandler     (void){g_IRQInterface.pf_DMA1_Channel2_3_IRQHandler    ();}
void DMA1_Channel4_5_IRQHandler     (void){g_IRQInterface.pf_DMA1_Channel4_5_IRQHandler    ();}
void ADC1_COMP_IRQHandler           (void){g_IRQInterface.pf_ADC1_COMP_IRQHandler          ();}
void TIM1_BRK_UP_TRG_COM_IRQHandler (void){g_IRQInterface.pf_TIM1_BRK_UP_TRG_COM_IRQHandler();}
void TIM1_CC_IRQHandler             (void){g_IRQInterface.pf_TIM1_CC_IRQHandler            ();}
void TIM2_IRQHandler                (void){g_IRQInterface.pf_TIM2_IRQHandler               ();}
void TIM3_IRQHandler                (void){g_IRQInterface.pf_TIM3_IRQHandler               ();}
void TIM6_DAC_IRQHandler            (void){g_IRQInterface.pf_TIM6_DAC_IRQHandler           ();}
void TIM14_IRQHandler               (void){g_IRQInterface.pf_TIM14_IRQHandler              ();}
void TIM15_IRQHandler               (void){g_IRQInterface.pf_TIM15_IRQHandler              ();}
void TIM16_IRQHandler               (void){g_IRQInterface.pf_TIM16_IRQHandler              ();}
void TIM17_IRQHandler               (void){g_IRQInterface.pf_TIM17_IRQHandler              ();}
void I2C1_IRQHandler                (void){g_IRQInterface.pf_I2C1_IRQHandler               ();}
void I2C2_IRQHandler                (void){g_IRQInterface.pf_I2C2_IRQHandler               ();}
void SPI1_IRQHandler                (void){g_IRQInterface.pf_SPI1_IRQHandler               ();}
void SPI2_IRQHandler                (void){g_IRQInterface.pf_SPI2_IRQHandler               ();}
void USART1_IRQHandler              (void){g_IRQInterface.pf_USART1_IRQHandler             ();}
void USART2_IRQHandler              (void){g_IRQInterface.pf_USART2_IRQHandler             ();}
