#include <stdio.h>
#include <stdlib.h>
#include <wiringPi.h>


int pinList[] = {6,26,27,28,29, 28, 27,26}; 
int pinSw = 25;

int isPress(int sw)
{
	return digitalRead(sw) == LOW;
}

void waitForPress(int sw)
{
	while (1)
	{
		if (isPress(sw))
			break;
	}
}


int main(int argc, char* argv[])
{
	wiringPiSetup();

	puts("start");

	pinMode(pinSw, INPUT);
	for (int i = 0; i < 5; i++)
	{
		pinMode(pinList[i], OUTPUT);
	}
	
	unsigned int cnt = 0;
	while (1)
	{
		digitalWrite(pinList[cnt % 8], HIGH);
		delay(80);

		if (isPress(pinSw))
		{
			delay(500);
			waitForPress(pinSw);
			delay(100);
		}

		digitalWrite(pinList[cnt % 8], LOW);
		cnt++;
	}
	return 0;
}
