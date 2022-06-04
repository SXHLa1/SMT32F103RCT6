#include "sys.h"
#include "usart.h"
#include "delay.h"
#include "led.h"



void My_usart_init()
{
    
    GPIO_InitTypeDef GPIO_Initstruct;
    USART_InitTypeDef USART_InitStruct;
    NVIC_InitTypeDef NVIC_InitStruct;

    //开启usart 串口时钟
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_USART1,ENABLE);

    //io 口初始化配置
    //PA9为TX ，配置为推挽输出
    GPIO_Initstruct.GPIO_Mode=GPIO_Mode_AF_PP;
    GPIO_Initstruct.GPIO_Pin=GPIO_Pin_9;
    GPIO_Initstruct.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_Initstruct);

    //PA10为Rx,配置为浮空输入
    GPIO_Initstruct.GPIO_Mode=GPIO_Mode_IN_FLOATING;
    GPIO_Initstruct.GPIO_Pin=GPIO_Pin_10;
    GPIO_Initstruct.GPIO_Speed=GPIO_Speed_10MHz;
    GPIO_Init(GPIOA,&GPIO_Initstruct);

    //初始化usart串口阐述配置
    USART_InitStruct.USART_BaudRate=115200;
    USART_InitStruct.USART_HardwareFlowControl=USART_HardwareFlowControl_None;
    USART_InitStruct.USART_Mode=USART_Mode_Rx|USART_Mode_Tx;
    USART_InitStruct.USART_Parity=USART_Parity_No;
    USART_InitStruct.USART_StopBits=USART_StopBits_1;
    USART_InitStruct.USART_WordLength=USART_WordLength_8b;
    USART_Init(USART1,&USART_InitStruct);

    #if EN_USART1_RX   //使能接收后
    //初始化中断
    NVIC_InitStruct.NVIC_IRQChannel=USART1_IRQn;
    NVIC_InitStruct.NVIC_IRQChannelCmd=ENABLE;
    NVIC_InitStruct.NVIC_IRQChannelPreemptionPriority=3;
    NVIC_InitStruct.NVIC_IRQChannelSubPriority=3;
    NVIC_Init(&NVIC_InitStruct);
    USART_ITConfig(USART1,USART_IT_RXNE,ENABLE);        //当读寄存器非空时开启中断
    #endif

    //使能USART
   
    USART_Cmd(USART1,ENABLE);
}



int main(void)
{
	delay_init();
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
    My_usart_init();
	
	
}	



