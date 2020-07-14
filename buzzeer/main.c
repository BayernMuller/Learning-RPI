#include <wiringPi.h>
#include <softTone.h>

#define SPKR 27
#define SW 25
#define SI 270
#define LA 220
#define SOL 170

int note[] = { SI, LA, SOL, LA, SI, SI, SI,0, LA, LA, LA,0, SI, SI,SI,0,SI,LA,SOL,LA,SI,SI,SI,0,LA,LA,SI,LA,SOL, -1};


void musicPlay()
{
	softToneCreate(SPKR);
	for (int i = 0; note[i] != -1; i++)
	{
		softToneWrite(SPKR, note[i]);
		delay(100);
		softToneWrite(SPKR, 0);
		delay(300);
	}
}

int main()
{
	wiringPiSetup();
	musicPlay();
	return 0;
}
