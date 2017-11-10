/*    
Copyright (c) 2013, 东莞华中科技大学制造工程研究院 All rights reserved.
文件名称：CanRS.c 
摘    要：CAN寄存器操作接口函数头文件
运行环境：IAR6.3
当前版本：1.0 
完成日期：
*/

#ifndef _CAN_BUFFER_H__
#define _CAN_BUFFER_H__

#include "CanDataStructDef.h"
//#include "lpc43xx_can.h"
#include "DataType.h"


#define BUF_BLANK                    0x00//标记空白帧,用于队列写保护
#define CAN_BUF_RE_LENGTH       10//CAN报文接收软件缓冲区长度
#define CAN_BUF_TX_LENGTH       10//CAN报文发送软件缓冲区长度



//定义CAN接收环形缓冲区结构
typedef struct {
    Bit32           iFreeNum;
    uBit32 ulWriteIndex;                  //缓存Buffer[]写下标
    uBit32 ulReadIndex;                   //缓存Buffer[]读下标
    uBit32 ulLength;                      //记录缓存深度
    CanFrame *ptCanFramBuf;                        //指向数据场缓冲区
}CanCirBuf;

//如果定义了接收缓冲区宏
#ifdef _CAN_TX_BUFFER_FUN_
extern CanCirBuf GtCanTxCirBuf[ENABLE_CAN_NODE_NUM];   
//发送数据场缓冲区
extern CanFrame GtCanTxBuffer[ENABLE_CAN_NODE_NUM][CAN_BUF_TX_LENGTH]; 
#endif

//定义接收环形缓冲区
extern CanCirBuf GtCanReCirBuf[ENABLE_CAN_NODE_NUM]; 
//接收数据场缓冲区
extern CanFrame GtCanReBuffer[ENABLE_CAN_NODE_NUM][CAN_BUF_RE_LENGTH]; 

#ifdef __cplusplus
extern "C"
{
#endif
  
    /*
    功      能：    初始化CAN缓冲区
    参      数：    无
    返  回  值：    无
    注意 事 项：    无
    所在文件名：    CanBuf.c
    */
    extern void InitCanBuf(void);
    /*
    功      能：    向循环队列（软件FIFO）申请一块帧缓存区域 帧类型格式将被初始化为BUF_BLANK
    参      数：    ptBuf          指向循环队列的指针
    返  回  值：    ptCanFrame     帧缓存地址,若为0则表示循环队列满
    注意 事 项：    临界区保护
    所在文件名：    CanBuf.c
    */
    extern CanFrame *canCirBufMalloc(CanCirBuf *ptCanCirBuf);
    /*
    功      能：    从循环队列读取一帧数据
    参      数：    ptCanCirBuf   指向循环队列的指针
                    ptCanFrame    数据输出指针
    返  回  值：    EMPTY     循环队列为空,循环队列中无可用数据
                    NOT_EMPTY  循环队列非空
                    0  循环队列错误,操作失败
    注意 事 项：    临界区保护及误读保护
    所在文件名：    CanBuf.c
    */
    extern uBit32 canCirBufRead(CanCirBuf *ptCanCirBuf, CanFrame  *ptCanFrame);
    /*
    功      能：    往循环队列写一帧数据
    参      数：    ptCanCirBuf   指向循环队列的指针
                    ptCanFrame    数据输出指针
    返  回  值：    1     操作成功
                    0  操作失败
    注意 事 项：    无
    所在文件名：    CanApi.c
    */
    extern uBit32 canCirBufWrite(CanCirBuf *ptCanCirBuf, CanFrame *ptCanFrame);

#ifdef __cplusplus
}
#endif

#endif

/*===========================================End===========================================*/
