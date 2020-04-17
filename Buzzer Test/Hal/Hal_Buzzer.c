#include "Hal_Buzzer.h"

void Test_Buzzer(void)
{
	static int count=0;
	if(count== 1)
	{
		LOG("buzzer!\r\n");
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_SET);
		Delay_Ms(50); //�����ӳ��ܵõ���ͬ������
		HAL_GPIO_WritePin(BUZZER_GPIO_TYPE,BUZZER_PIN,GPIO_PIN_RESET);
		Delay_Ms(100);
	}
	count++; //count ��ʱ���Ƿ������ķ�ʽ�ӳ�
	if(count > 100) 
	{
		count=0;
	}
}
