#include "key.h"
#include "stm32f10x.h"
#include "delay.h"
void Key_Init(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC,ENABLE);//使能 PORTA,PORTC 时钟
    GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);
    //关闭 jtag，使能 SWD，可以用 SWD 模式调试
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_15;//PA15
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化 GPIOA15
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;//PC5
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; //设置成上拉输入
    GPIO_Init(GPIOC, &GPIO_InitStructure);//初始化 GPIOC5
	
    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;//PA0
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPD; //PA0 设置成输入，默认下拉 
    GPIO_Init(GPIOA, &GPIO_InitStructure);//初始化 GPIOA.0
    
}

u8 Key_Scan(u8 mode)
{

    static u8 key_up=1;//按键按松开标志
    if(mode)key_up=1; //支持连按 
    if(key_up&&(Key0==0 ||Key1==0||WK_UP==1))
    {
        delay_ms(10);//去抖动
         key_up=0;
         if(Key0==0)return KEY0_PRES;
         else if(Key1==0)return KEY1_PRES;
         else if(WK_UP==1)return Wkup_PRES; 
     }else if(Key0==1&&Key1==1&&WK_UP==0)key_up=1; 
    return 0;// 无按键按下

}
