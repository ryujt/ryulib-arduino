#include <digit_image.h>


void draw_number(Adafruit_GFX *gfx, int x, int y, int anumber)
{
	// 자릿수 계산, log를 사용하는 것보다 빠를 거 같아서.
	int count = 1;
	int number = anumber; 
	while (number >= 10) {
		count = count + 1;
		number = number / 10;
	}

	number = anumber; 

	for (int i=count-1; i>=0; i--) {
		int n = number % 10;
		number = number / 10;
        gfx->drawBitmap(84 - DIGIT_WIDTH - y, i * (DIGIT_HEIGHT+1) + x, digit_image[n], DIGIT_WIDTH, DIGIT_HEIGHT, 1);                
	}
}
