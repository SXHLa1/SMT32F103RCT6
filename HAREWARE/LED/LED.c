#include"led.h"
#include"stm32f10x.h"


void LED_Init(void){
	
	
	GPIO_InitTypeDef GPIO_InitStruct;
	
	//打开PD和PA时钟
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	//初始化


	GPIO_InitStruct.GPIO_Mode=GPIO_Mode_Out_PP;
	GPIO_InitStruct.GPIO_Speed=GPIO_Speed_50MHz;
	
	GPIO_SetBits(GPIOD,GPIO_Pin_2);
	GPIO_Init(GPIOD,&GPIO_InitStruct);
	GPIO_SetBits(GPIOD,GPIO_Pin_2);

	GPIO_InitStruct.GPIO_Pin=GPIO_Pin_8;
	GPIO_Init(GPIOA,&GPIO_InitStruct);
	GPIO_SetBits(GPIOA,GPIO_Pin_8);
	
}
