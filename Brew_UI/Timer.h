#pragma once
class Timer
{
public:
	Timer();
	~Timer();
	void CountDown(int, int, int);
	void CountUp();
//	int SetTimer(struct timeval, time_t); //These ones should work on the pi
//	int CheckTimer(struct timeval, time_t); //THey do not on windows
private:
    int hour;
    int minute;
    int second;
};
