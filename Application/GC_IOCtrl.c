/**
  ******************************************************************************
  * @file    GCIOCtrl.c
  * @author  Duhanfneg
  * @version V1.0
  * @date    2017.10.20
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
#include "GC_IOCtrl.h"
#include "../DataType/DataType.h"
#include "../SysPeripheral/GPIO/GPIO_Man.h"
#include "../PeriDrivers/NixieTube/NixieTube.h"


//输入IO表
static GPIO_DATA m_InputIOTable[] = 
{
    //按键
    {4,  28}, 
    
    //红外对射管
    {0,  18}, 
    
};


//输出IO表
static GPIO_DATA m_OutputIOTable[] = 
{
    //LED灯
    {0,  4 }, 
    

};



/**
  * @brief  IO初始化
  * @param  None
  * @retval None
  */
void GC_IOInit(void)
{
    GPIO_CTRL_TABLE GC_CtrlIOTable = {0};
    
    GC_CtrlIOTable.pOutIOTable = m_OutputIOTable;
    GC_CtrlIOTable.pInIOTable  = m_InputIOTable;
    GC_CtrlIOTable.ulOutIOCount = sizeof(m_OutputIOTable)/sizeof(GPIO_DATA);
    GC_CtrlIOTable.ulInIOCount  = 0;

    GPIO_SetCtrlTable(&GC_CtrlIOTable);
    GPIO_InitTableIO(&GC_CtrlIOTable);
    
}

