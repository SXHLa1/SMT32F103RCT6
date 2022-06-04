#ifndef __LED_H
#define __LED_H

#define LED0 PAout(8)
#define LED1 PDout(2)

// #define LED1_up GPIO_SetBits(GPIOA,GPIO_Pin_8)
// #define LED1_dw GPIO_ResetBits(GPIOA,GPIO_Pin_8)

void LED_Init(void);

#endif
