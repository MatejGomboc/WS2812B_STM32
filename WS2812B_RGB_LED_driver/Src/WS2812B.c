/*
 * WS2812B.c
 *
 * Created on: 13. okt. 2016
 * Author: Matej
 */

#include "gpio.h"
#include "WS2812B.h"

inline void WS2812B_send_0(void)
{
	LED_sdata_GPIO_Port->BSRR = LED_sdata_Pin;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");

	LED_sdata_GPIO_Port->BSRR = (uint32_t)LED_sdata_Pin << 16U;
	for(int indx = 0; indx < 10; indx++)
	{
		asm("nop");
	}
}

inline void WS2812B_send_1(void)
{
	LED_sdata_GPIO_Port->BSRR = LED_sdata_Pin;
	for(int indx = 0; indx < 10; indx++)
	{
		asm("nop");
	}

	LED_sdata_GPIO_Port->BSRR = (uint32_t)LED_sdata_Pin << 16U;
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
	asm("nop");
}

inline void WS2812B_send_RET(void)
{
	LED_sdata_GPIO_Port->BSRR = (uint32_t)LED_sdata_Pin << 16U;
	for(int indx = 0; indx < 1000; indx++)
	{
		asm("nop");
	}
	LED_sdata_GPIO_Port->BSRR = LED_sdata_Pin;
}

void WS2812B_send_packet(WS2812B_color_t* packet, uint32_t length)
{
	WS2812B_send_RET();

	for(uint32_t i = 0; i < length; i++)
	{
		for(uint32_t j = 0; j < 8; j++)
		{
			if((packet[i].green >> j) & 0x01) WS2812B_send_1();
			else WS2812B_send_0();
		}

		for(uint32_t j = 0; j < 8; j++)
		{
			if((packet[i].red >> j) & 0x01) WS2812B_send_1();
			else WS2812B_send_0();
		}

		for(uint32_t j = 0; j < 8; j++)
		{
			if((packet[i].blue >> j) & 0x01) WS2812B_send_1();
			else WS2812B_send_0();
		}
	}

	WS2812B_send_RET();
}
