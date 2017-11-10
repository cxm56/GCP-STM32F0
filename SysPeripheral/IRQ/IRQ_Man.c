/**
  ******************************************************************************
  * @file    IRQ_Man.c
  * @author  Duhanfneg
  * @version V1.0
  * @date    2017.11.07
  * @brief   Hardware IRQ manage
  ******************************************************************************
  * @attention
  * 
  * 
  * 
  * 
  ******************************************************************************
  */
  
/***********************************<INCLUDES>**********************************/
#include "IRQ_Man.h"
#include "../HAL/HAL_IRQHandler.h"
#include <stdio.h>


/**
  * @brief  中断接口初始化
  * @param  None
  * @retval None
  * @note   本函数必须在所有硬件模块配置之前调用(重要)
  *         
  */
void IRQ_Init(void)
{
    HAL_IRQ_Init();
    
}


/**
  * @brief  设置中断触发回调
  * @param  ptr 回调指针
  * @param  TrgSource 触发源
  * @retval None
  */
void IRQ_SetTrgCallback(void (*ptr)(void), IRQ_TRIGGER_SOURCE TrgSource)
{
    if (ptr == NULL) 
    {
        return;
    }
    
    switch (TrgSource)
    {

    //系统滴答
    case IRQ_TRG_SYSTICK_UPDATE:        g_IRQInterface.pf_SysTick_Update                  = ptr; break;
    case IRQ_TRG_SYSTICK_OS:            g_IRQInterface.pf_SysTick_Handler                 = ptr; break;
    
    case IRQ_TRG_PVD:                   g_IRQInterface.pf_PVD_IRQHandler                  = ptr; break;
    case IRQ_TRG_RTC:                   g_IRQInterface.pf_RTC_IRQHandler                  = ptr; break;
    case IRQ_TRG_FLASH:                 g_IRQInterface.pf_FLASH_IRQHandler                = ptr; break;
    case IRQ_TRG_RCC:                   g_IRQInterface.pf_RCC_IRQHandler                  = ptr; break;
    case IRQ_TRG_EXTI0_1:               g_IRQInterface.pf_EXTI0_1_IRQHandler              = ptr; break;
    case IRQ_TRG_EXTI2_3:               g_IRQInterface.pf_EXTI2_3_IRQHandler              = ptr; break;
    case IRQ_TRG_EXTI4_15:              g_IRQInterface.pf_EXTI4_15_IRQHandler             = ptr; break;
    case IRQ_TRG_TS:                    g_IRQInterface.pf_TS_IRQHandler                   = ptr; break;
    case IRQ_TRG_DMA1_Channel1:         g_IRQInterface.pf_DMA1_Channel1_IRQHandler        = ptr; break;
    case IRQ_TRG_DMA1_Channel2_3:       g_IRQInterface.pf_DMA1_Channel2_3_IRQHandler      = ptr; break;
    case IRQ_TRG_DMA1_Channel4_5:       g_IRQInterface.pf_DMA1_Channel4_5_IRQHandler      = ptr; break;
    case IRQ_TRG_ADC1_COMP:             g_IRQInterface.pf_ADC1_COMP_IRQHandler            = ptr; break;
    case IRQ_TRG_TIM1_BRK_UP_TRG_COM:   g_IRQInterface.pf_TIM1_BRK_UP_TRG_COM_IRQHandler  = ptr; break;
    case IRQ_TRG_TIM1_CC:               g_IRQInterface.pf_TIM1_CC_IRQHandler              = ptr; break;
    case IRQ_TRG_TIM2:                  g_IRQInterface.pf_TIM2_IRQHandler                 = ptr; break;
    case IRQ_TRG_TIM3:                  g_IRQInterface.pf_TIM3_IRQHandler                 = ptr; break;
    case IRQ_TRG_TIM6_DAC:              g_IRQInterface.pf_TIM6_DAC_IRQHandler             = ptr; break;
    case IRQ_TRG_TIM14:                 g_IRQInterface.pf_TIM14_IRQHandler                = ptr; break;
    case IRQ_TRG_TIM15:                 g_IRQInterface.pf_TIM15_IRQHandler                = ptr; break;
    case IRQ_TRG_TIM16:                 g_IRQInterface.pf_TIM16_IRQHandler                = ptr; break;
    case IRQ_TRG_TIM17:                 g_IRQInterface.pf_TIM17_IRQHandler                = ptr; break;
    case IRQ_TRG_I2C1:                  g_IRQInterface.pf_I2C1_IRQHandler                 = ptr; break;
    case IRQ_TRG_I2C2:                  g_IRQInterface.pf_I2C2_IRQHandler                 = ptr; break;
    case IRQ_TRG_SPI1:                  g_IRQInterface.pf_SPI1_IRQHandler                 = ptr; break;
    case IRQ_TRG_SPI2:                  g_IRQInterface.pf_SPI2_IRQHandler                 = ptr; break;
    case IRQ_TRG_USART1:                g_IRQInterface.pf_USART1_IRQHandler               = ptr; break;
    case IRQ_TRG_USART2:                g_IRQInterface.pf_USART2_IRQHandler               = ptr; break;
    
    default: break;
    }
    
}


/**
  * @brief  释放中断触发回调
  * @param  TrgSource 触发源
  * @retval None
  */
void IRQ_ReleaseTrgCallback(IRQ_TRIGGER_SOURCE TrgSource)
{
    switch (TrgSource)
    {

    //系统滴答
    case IRQ_TRG_SYSTICK_UPDATE: g_IRQInterface.pf_SysTick_Update =  HAL_IRQ_NullEntry; break;
    case IRQ_TRG_SYSTICK_OS:  g_IRQInterface.pf_SysTick_Handler =  HAL_IRQ_NullEntry; break;
    

    default: break;
    }
    
}











