#include "Temp_Probe.h"
#include <iostream>
#include <string>
#include "GPIO.h"
#include <ctime>

using namespace std;


Temp_Probe::Temp_Probe()
{
}


Temp_Probe::~Temp_Probe()
{
}

double Temp_Probe::getTemperature(){
    return this->temperature;
}

int Temp_Probe::Read_Temp()
{
	string inputstate;
	GPIOClass* gpio4 = new GPIOClass("4"); //create new GPIO obtect to attach to GPIO4
	GPIOClass* gpio17 = new GPIOClass("17"); //create new GPIO obtect to attach to GPIO17
	
	gpio17->setdir_gpio("in"); //GPIO4 set to output
	gpio4->setdir_gpio("out"); // GPIO17 set to input
	
	while (1)
	{
		clock_t temp;
		temp = clock() + .5 * CLOCKS_PER_SEC;
		while (clock() < temp) {}// wait for 0.5 seconds

		gpio17->getval_gpio(inputstate); //read state of GPIO17 input pin
		cout << "Current input pin state is " << inputstate << endl;
		if (inputstate == "0") // if input pin is at state "0" i.e. button pressed
		{
			cout << "input pin state is Pressed \n Will check input pin state again in 20ms " << endl;

			temp = clock() + .02 * CLOCKS_PER_SEC;
			while (clock() < temp) {}// wait for 20 milliseconds

			cout << "Checking again ....." << endl;
			gpio17->getval_gpio(inputstate); // checking again to ensure that state "0" is due to button press and not noise
			if (inputstate == "0")
			{
				cout << "Input pin state is definitely Pressed. Turning LED ON" << endl;
				gpio4->setval_gpio("1"); // turn LED ON

				cout << " Waiting until pin is unpressed....." << endl;
				while (inputstate == "0"){
					gpio17->getval_gpio(inputstate);
				};
				cout << "pin is unpressed" << endl;

			}
			else
				cout << "input pin state is definitely not pressed. That was just noise." << endl;

		}
		gpio4->setval_gpio("0");

	}

	int Temp, Reset = 0, presence = 0;
	int ConvertTemp = 0x44, GetTemp = 0xBE, ReadRom = 0x33;

  //currently in sudo code until i can get to work on the pi
	Reset; //Send reset signal to probe
	presence = 1; //ans   presence watis for response from probe
	int Address = ReadRom; //Master reads in the address of the probe so it can talk to it specifically
	Address + ConvertTemp; //Tells probe to read in the current temp and store it in its memory
	Temp = Address + GetTemp; //reads in the memory of the probe, LSB first
	if (sizeof(Temp) == 4)
		Reset; // Once it has read in the first 2 bytes it sends a reset pulse to stop the memory read

	return Temp;
}

double Temp_Probe::Convert_Temp(int Temp)
{
	double bit, decimal = 0, Converted_Temp, combined_temp;
	double array[4] = {0.5, 0.25, 0.125, 0.0625};
	cout << Temp << endl;
	int dec = Temp & 0x0F;
	int sign = (Temp >> 11) & 0x1F;
	int Main_Temp = (Temp >> 4) & 0x07F;
	int a = sizeof(Temp);
	cout << a << endl; 
	printf("Sign: %i \nDec: %i \nTemp: %i Celcius\n", sign, dec, Main_Temp);

	if (dec > 0)
	{
		for (int i = 1; i <= 4; i++)
		{
			bit = (dec >> i-1) & 0x1;
			//std::cout << array[i - 1] << std::endl;
			bit = bit * array[i-1];
			decimal = decimal + bit;
		}
	}

	if (sign > 0)
	{
		printf("Temperature is below freezing.\n");
	}
	combined_temp = Main_Temp + decimal;
	Converted_Temp = (1.8 * combined_temp) + 32;
	
    this->temperature = Converted_Temp;
}
