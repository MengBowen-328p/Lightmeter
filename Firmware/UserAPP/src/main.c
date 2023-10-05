#include "main.h"

uint8_t switchstatus =0;

int main()
{
	rccInitHSE();
	switchInit();
	while (1)
	{
		switchstatus = switchClick();
	}
	return 0;
}