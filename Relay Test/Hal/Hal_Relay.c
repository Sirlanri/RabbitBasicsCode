#include "Hal_Relay.h"

/**
*���Ƽ̵�������
*�ߵ�ƽOut2,�͵�ƽout1
*/
void Control_Relay(char state)
{
		if (state == 1)
		{
			HAL_GPIO_WritePin(RELAY_GPIO_TYPE,RELAY_PIN,GPIO_PIN_SET);
		}
		else
		{
			HAL_GPIO_WritePin(RELAY_GPIO_TYPE,RELAY_PIN,GPIO_PIN_RESET);
		}
}



void Relay_Test(void)
{
	static int count = 0;
	if(count == 1)
	{
		Control_Relay(1);
	}
	
	if(count == 1000)
	{
		Control_Relay(0);
	}
	
	if(count >2000)
	{
		count = 0;
	}
	
	count ++;
		
		

}