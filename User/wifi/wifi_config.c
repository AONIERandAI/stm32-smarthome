/**
  ******************************************************************************
  * @file    wifi_config.c
  * @author  fire
  * @version V1.0
  * @date    2014-xx-xx
  * @brief   WiFiģ��ӿ���������
  ******************************************************************************
  * @attention
  *
  * ʵ��ƽ̨:Ұ�� ISO-STM32 ������
  * ��̳    :http://www.chuxue123.com
  * �Ա�    :http://firestm32.taobao.com
  *
  ******************************************************************************
	*/

#include "wifi_config.h"
#include "bsp_wifigpio.h"
#include "bsp_usart1.h"
#include "bsp_usart2.h"
#include "wifi_function.h"


struct  STRUCT_USARTx_Fram strEsp8266_Fram_Record = { 0 };


/**
  * @brief  WiFi_Config wifi ��ʼ��
  * @param  ��
  * @retval ��
  */
void WiFi_Config( void )
{
	WiFi_RST_INIT();
  WiFi_USART1_INIT(); 
	WiFi_USART2_INIT(); 
	WiFi_NVIC_INIT();
  
}


/// ����NVIC�е�UART2�ж�
void NVIC_Configuration( void )
{
	NVIC_InitTypeDef NVIC_InitStructure; 
	
	/* Configure the NVIC Preemption Priority Bits */  
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);

	/* Enable the USART2 Interrupt */
	NVIC_InitStructure.NVIC_IRQChannel = USART2_IRQn;	 
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);

}
void wifi_Config(void)
{	
	ESP8266_Net_Mode_Choose(STA_AP);//STAģ
	//ESP8266_Rst();
	ESP8266_Enable_MultipleId(DISABLE);//������
	ESP8266_UnvarnishSend ( );//����͸��ģʽ
	
	
}
char* zhsj(uint32_t shuju)
{
	char str[5];
	str[0]=shuju/100+48;
	str[1]=shuju%100/10+48;
	str[2]=shuju%10+48;
	return str;
	
}

/*********************************************************end of file**************************************************/
