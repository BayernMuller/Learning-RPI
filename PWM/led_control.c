#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>
#include <softPwm.h>
int led_list[] = {6,26,27,28,29,28,27,26};
int led_bright[5] = {0,};

int ledPwmControl(int gpio)
{
	softPwmCreate(gpio, 0, 255);
	for (int i = 0; i < 256; i++)
	{
		softPwmWrite(gpio, i);
		delay(5);
	}
}

int ledControl()
{
	for (int i = 0; i < 5; i++)
	{
		softPwmWrite(led_list[i], (i + 1) * 51);
		led_bright[i] = i + 1;
		delay(100);
	}
	for (int i = 0; i < 5; i++)
	{
		softPwmWrite(led_list[i], 0);
	}	
	for (int i = 4; i >= 0; i--)
	{
		softPwmWrite(led_list[i], (5-i ) * 51);
		delay(100);
	
	}
	for (int i = 0; i < 5; i++)
	{
		softPwmWrite(led_list[i], 0);
	}
}

int main(int argc, char argv[])
{
	wiringPiSetup();
	for (int i = 0; i < 5; i++)
	{
		pinMode(led_list[i], OUTPUT);
		digitalWrite(led_list[i], LOW);
		softPwmCreate(led_list[i], 0, 255);
	}

	while (1)
	{
		ledControl();
	}
	return 0;
}
