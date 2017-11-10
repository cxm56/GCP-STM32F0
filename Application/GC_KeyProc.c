/**
  ******************************************************************************
  * @file    Demo.c
  * @author  Duhanfneg
  * @version V1.0
  * @date    2017.11.07
  * @brief   demo
  ******************************************************************************
  * @attention
  * 
  * 
  * 
  * 
  ******************************************************************************
  */
  
/***********************************<INCLUDES>**********************************/
#include "GC_KeyProc.h"
#include "../DataType/DataType.h"
#include "../PeriDrivers/NixieTube/NixieTube.h"
#include "../SysPeripheral/KEY/KEY.h"
#include "../SysPeripheral/SysTick/SysTimer.h"

/*****************************************************************************
 * 私有成员定义及实现
 ****************************************************************************/
#define GC_KEY_SCAN_INTERVAL        (50)        //按键扫描间隔(MS)

static SYS_TIME_DATA m_ScanTimer  = {1};        //扫描定时器

static uBit8 m_uDisNumber = 0;

/*****************************************************************************
 * 按键处理线程接口
 ****************************************************************************/

/**
  * @brief  按键处理
  * @param  None
  * @retval None
  */
void GC_KeyProc(void)
{
    if (SysTime_CheckExpiredState(&m_ScanTimer))
    {
        SysTime_StartOneShot(&m_ScanTimer, GC_KEY_SCAN_INTERVAL); //设置下一次执行的时间
        
        uBit32 ulCurTrg = KEY_Scan(NULL);
        
        if (ulCurTrg)
        {
            NixieTube_DisNumber(m_uDisNumber++);
            
        }
        
    }
    
      
}