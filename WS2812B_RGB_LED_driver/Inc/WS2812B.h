/*
 * WS2812B.h
 *
 * Created on: 13. okt. 2016
 * Author: Matej
 */

#ifndef WS2812B_H_
#define WS2812B_H_

typedef struct
{
	uint8_t green;
	uint8_t red;
	uint8_t blue;
}WS2812B_color_t;

extern void WS2812B_send_packet(WS2812B_color_t* packet, uint32_t length);

#endif /* WS2812B_H_ */
