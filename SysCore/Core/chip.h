#ifndef __CHIP_H_
#define __CHIP_H_

#if defined(STM32F030)
#include "stm32f0xx.h"
#endif

#ifndef __cplusplus

#define bool _Bool
#define true 1
#define false 0

#endif /* !__cplusplus */

#ifdef __CC_ARM
#define INLINE  __inline
#else
#define INLINE inline
#endif

#endif /* __CHIP_H_ */
