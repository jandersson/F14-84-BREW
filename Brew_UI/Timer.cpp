#include "Timer.h"
#include <iostream>
#include <ctime>
//#include <sys/time.h>
#include <stdio.h>

Timer::Timer()
{
}


Timer::~Timer()
{
}


void Timer::CountDown(int hours, int minutes, int seconds)
{
	int sec = seconds, min =  minutes, hrs = hours;
	for (sec; sec < 100; sec--)
	{

		if (sec == -1)
		{
			min--;
			sec = 59;
		}
		if (min == -1)
		{
			hrs = hrs - 1;
			min = 59;
		}
				
		if (hrs == -1)
			break;
		std::cout << hrs << ":" << min << ":" << sec << std::endl;
		
		clock_t temp;
		temp = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < temp) {}
	}
}

void Timer::CountUp()
{
	int sec = 0, min = 0, hrs = 0;
	for (sec = 0; sec < 61; sec++)
	{
		if (sec == 60)
		{
			min++;
			sec = 0;
		}

		if (min == 60)
		{
			hrs++;
			min = 0;
		}

		if (hrs == 24)
			hrs = 0;
		
		std::cout << hrs << ":" << min << ":" << sec << std::endl;
		
		clock_t temp;
		temp = clock() + 1 * CLOCKS_PER_SEC;
		while (clock() < temp) {}
	}
}

/*int SetTimer(struct timeval &tv, int usec)
{
	gettimeofday(&tv, NULL);
	tv.tv_usec += usec;

	return 1;
}

int CheckTimer(struct timeval &tv, int usec)
{
	struct timeval ctv;
	gettimeofday(&ctv, NULL);

	if ((ctv.tv_usec &gt; = tv.tv_usec) || (ctv.tv_sec &gt; tv.tv_sec))
	{
		gettimeofday(&tv, NULL);
		tv.tv_usec += usec;
		return 1;
	}
	else
		return 0;
}*/