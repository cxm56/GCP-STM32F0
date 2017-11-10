/*    
Copyright (c) 2013, 东莞华中科技大学制造工程研究院 All rights reserved.
文件名称：CanRS.c 
摘    要：CAN寄存器操作接口函数头文件
运行环境：IAR6.3
当前版本：1.0 
完成日期：
*/

#ifndef __CAN_API_H__
#define __CAN_API_H__

#include "CanBuf.h"

//帧类型及格式
#define STD_DATA               0xF0//标准格式数据帧 
#define XTD_DATA               0xF2//扩展格式数据帧

#define STD_RMRQS              0xF1//标准格式远程帧 
#define XTD_RMRQS              0xF3//扩展格式远程帧

#define XTD_MASK               0x02//扩展帧掩码
#define RMRQS_MASK             0x01//远程帧掩码


//宏定义接收、发送报文对象
#define RE_DATA_SN              0x00FFFFFFUL         //按位选择接收数据帧的报文对象
#define RE_REMOTE_SN            0x7F000000UL         //按位选择接收远程帧的报文对象
#define TX_MSG_SN               32                   //发送报文对象编号

//CAN中断回调函数的消息类型(CAN节点状态)
#define CAN_BUS_ERR_MASK        0x0F                 //节点错误屏蔽字

#define CAN_BUS_OFF             0x01                 //节点脱离总线
#define CAN_SEND_FAIL           0x02                 //发送失败
#define CAN_SEND_LOST           0x04                 //发送数据包丢失
#define CAN_REC_LOST            0x08                 //接收数据包丢失
#define CAN_SEND_OK             0x80                 //需要检测是否发送成功

#define CAN_NO_ERROR            0x00                 //没有错误

//定义验收过滤验收方式
#define EXT_ID_FILTER           1                    //验收扩展帧
#define STD_ID_FILTER           2                    //验收标准帧
#define STD_EXT_FILTER          3                    //验收标准帧和扩展帧

#define UNMASK                  0x00000000UL         //不使用ID滤波
#define MASK                    0x1FFFFFFFUL         //所有ID均参与验收滤波
/*
//波特率表索引宏定义
#define CANBAUD_1M              0
#define CANBAUD_500K            1
#define CANBAUD_250K            2
#define CANBAUD_125K            3
#define CANBAUD_100K            4
#define CANBAUD_50K             5
#define CANBAUD_25K             6
#define CANBAUD_20K             7
#define CANBAUD_10K             8
#define CANBAUD_5K              9
#define CANBAUD_2K5            10
*/

//定义CAN节点结构体
typedef struct {
    uBit32 ulBaseAddr;                      //CAN控制器基址
    uBit8 ucNodeState;                     //用于记录节点状态
    uBit8 ucBaudIndex;                     //波特率参数索引
    uBit32 ulBofStep;                       //本节点脱离总线后的回复步骤
    uBit32 ulDaReObjMsk;                    //接收数据帧的报文对象,按位选通
    uBit32 ulRmReObjMsk;                    //接收远程帧的报文对象,按位选通
    uBit32 ulTxMsgObjNr;                    //按位标记发送报文对象
    CanCirBuf *ptCanReCirBuf;                        //指向本节点的接收缓冲区
    CanCirBuf *ptCanTxCirBuf;                        //指向本节点的发送缓冲区
    void (*pfCanHandlerCallBack)(uBit32 ulMessage, Bit32 lParam1, Bit32 lParam2);
    void (*pfIsrHandler)(void);                     //CAN节点的中断服务函数
}CanNodeInfo;

//用于定义并初始化CAN节点结构体变量的宏
#define CANNODE(ulBaseAddr, ucBaudIndex, ulDaReObjMsk, ulRmReObjMsk,    \
                ulTxMsgObjNr,ptReCirBuf, pfCanHandlerCallBack,          \
                pfIsrHandler)                                           \
        {                                                               \
           ulBaseAddr,                                                  \
           0,                                                           \
           ucBaudIndex,                                                 \
           0,                                                           \
           ulDaReObjMsk,                                                \
           ulRmReObjMsk,                                                \
           ulTxMsgObjNr,                                                \
           (CanCirBuf *)ptReCirBuf,                                      \
           (CanCirBuf *)0,                                               \
           pfCanHandlerCallBack,                                        \
           pfIsrHandler,                                                \
        }


//触发指定循环队列中的帧数据的发送工作接口函数
extern uBit32 canCirBufSend(CanNodeInfo *ptCanNode);

//将CAN数据立即发送到CAN总线,不发送到缓冲区
extern uBit32 ForceSendData(CanNodeInfo *ptCanNode,uBit32 ulId , uBit8 *pData, uBit32 ulDataLen);

//接收一帧或者多针CAN到缓冲区
extern uBit32 ReceiveData(CanNodeInfo *ptCanNode);

//发送一帧CAN报文至总线
extern void canFrameSend(CanNodeInfo *ptCanNode, CanFrame  *pCANFrame);

//使能CAN中断
extern void canIntEnable (CanNodeInfo *ptCanNode);
    
//CAN控制器重新接入总线
extern void canNodeBusOn(CanNodeInfo *ptCanNode);

//初始化一个包含CAN节点信息的结构体变量
extern void canNodeCreate(CanNodeInfo *ptCanNode,
                          uBit32 ulBaseAddr,
                          uBit8 ucBaudIndex,
                          uBit32 ulDaReObjMsk,
                          uBit32 ulRmReObjMsk,
                          uBit32 ulTxMsgObjNr,
                          CanCirBuf *ptReCirBuf,
                          CanCirBuf *ptTxCirBuf,
                          void (*pfCanHandlerCallBack)(uBit32 ulMessage, Bit32 lParam1, Bit32 lParam2),
                          void (*pfIsrHandler)(void));

//设置节点回调函数
extern void canNodeCallBackSet(CanNodeInfo *ptCanNode,
                               void (*pfHandlerCallBack)(uBit32 ulMessage,
                                                         Bit32 lParam1, Bit32 lParam2));

//验收滤波设置
extern void canAcceptFilterSet(CanNodeInfo *ptCanNode,
                               uBit32 ulFrameID,
                               uBit32 ulFrameIDMask,
                               uBit8 ucFramType);

//设置接收数据帧及远程帧的报文对象接口函数
extern void canReMsgObjSet(CanNodeInfo *ptCanNode,
                          uBit32 ulMsgObjMask,
                           uBit32 ulFrameID,
                           uBit32 ulFrameIDMask,
                           uBit8 ucFramType,
                           uBit8 ucMsgType);
//CAN应用初始化接口函数
extern uBit32 canApplyInit(CanNodeInfo *ptCanNode,
                          uBit32 ulFrameID,
                          uBit32 ulFrameIDMsk,
                          uBit8 ucFramType);

extern uBit32 CheckCanBusStatus(CanNodeInfo *ptCanNode ,uBit32 CheckType);
  
extern void CheckCanBusOff(CanNodeInfo *ptCanNode);

#endif

/*===========================================End===========================================*/
