#include "Hal_Rs485.h"

extern UART_HandleTypeDef huart3;

#define UART3_RECEIVE_CACHE_LEN 100

uint8_t guart3_cache_buf[UART3_RECEIVE_CACHE_LEN];
uint8_t guart3_temp_value = 0;
uint8_t guart3_recvied_len=0;

#define RS485_PIN GPIO_PIN_1
#define RS485_GPIO_PROT GPIOC


void Init_Rs485(void)
{
	HAL_UART_Receive_IT(&huart3,(uint8_t *)&guart3_temp_value,1);
	HAL_GPIO_WritePin(RS485_GPIO_PROT, RS485_PIN, GPIO_PIN_RESET);//PC1 ʹ�ܽ���
}



uint8_t Rs485_Send_Data(uint8_t *data, uint8_t len)
{
	uint8_t ret =0;
	HAL_GPIO_WritePin(RS485_GPIO_PROT, RS485_PIN, GPIO_PIN_SET);//PC1 ʹ�ܷ���
	HAL_UART_Transmit(&huart3, data, len, 50);
	Delay_Us(100);
	HAL_GPIO_WritePin(RS485_GPIO_PROT, RS485_PIN, GPIO_PIN_RESET);//PC1 ʹ�ܽ���
	return ret;
}


void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart == &huart3) //����Ǵ���3
	{
		if(guart3_recvied_len<UART3_RECEIVE_CACHE_LEN) //�����ݱ����ڻ�����
		{
			guart3_cache_buf[guart3_recvied_len++]=guart3_temp_value;
		}
		HAL_UART_Receive_IT(huart,(uint8_t *)&guart3_temp_value,1);
	}
}



void Rs485_Test(void)
{
	if(guart3_recvied_len >=10)
	{
		Rs485_Send_Data(guart3_cache_buf,guart3_recvied_len);
		guart3_recvied_len=0;
	}

}
