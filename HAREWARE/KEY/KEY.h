#ifndef __KEY_H
#define __KEY_H
#include "sys.h"


#define Key0 GPIO_ReadInputDataBit(GPIOC,GPIO_Pin_5)
#define Key1 GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_15)
#define WK_UP GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0)



#define KEY0_PRES 1
#define KEY1_PRES 2
#define Wkup_PRES 3



void Key_Init(void);
u8 Key_Scan(u8 mode);

#endif
