#pragma once

class Temp_Probe
{
public:
	Temp_Probe();
	~Temp_Probe();
	int Read_Temp();
    double getTemperature();
private:
    double temperature;
    double Convert_Temp(int);
};
