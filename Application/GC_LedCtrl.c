/**
  ******************************************************************************
  * @file    GCLedCtrl.c
  * @author  Duhanfneg
  * @version V1.0
  * @date    2017.10.23
  * @brief   
  ******************************************************************************
  * @attention
  * 
  * 
  * 
  * 
  ******************************************************************************
  */
   
   
/***********************************<INCLUDES>**********************************/
#include "GC_LedCtrl.h"
#include "GC_IOCtrl.h"
#include "../DataType/DataType.h"
#include "../SysPeripheral/GPIO/GPIO_Man.h"
#include "../SysPeripheral/SysTick/SysTimer.h"
#include "../SysPeripheral/UART/UART.h"

/*****************************************************************************
 * 私有成员定义及实现
 ****************************************************************************/
#define GC_LED_TOGGLE_TIME          (100)       //LED翻转时间(MS)
static SYS_TIME_DATA m_LedCtrlTimer  = {1};     //LED控定时器


/*****************************************************************************
 * 主线程LED显示接口
 ****************************************************************************/

/**
  * @brief  LED 流水灯循环
  * @param  None
  * @retval None
  */
void GC_MainWorkLedShow(void)
{
    if (SysTime_CheckExpiredState(&m_LedCtrlTimer))
    {
        SysTime_StartOneShot(&m_LedCtrlTimer, GC_LED_TOGGLE_TIME); //设置下一次执行的时间
        
        GPIO_ToggleOutputState(GC_OUTPUT_IO_LED);
    }

}