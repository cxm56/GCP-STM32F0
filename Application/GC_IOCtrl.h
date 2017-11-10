#ifndef  __GC_IO_CTRL_H
#define  __GC_IO_CTRL_H

//输出IO编号
typedef enum
{
    GC_OUTPUT_IO_LED,
    
}GC_OUTPUT_IO_TABLE;


//输入IO编号
typedef enum
{
    GC_INPUT_IO_KEY1 = 0,
    GC_INPUT_IO_INC0,

}GC_INPUT_IO_TABLE;


#ifdef __cplusplus
extern "C" {
#endif

/**
  * @brief  IO初始化
  * @param  None
  * @retval None
  */
void GC_IOInit(void);

#ifdef __cplusplus
}
#endif


#endif /* __GC_IO_CTRL_H */
