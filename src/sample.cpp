#include <iostream>
#include <stdio.h>
#include <string.h>

#include "RoboteqDevice.h"
#include "ErrorCodes.h"
#include "Constants.h"

using namespace std;

int main(int argc, char *argv[])
{
	string response = "";
	string devname = argv[1];
	RoboteqDevice device;
	int status = device.Connect(devname);

	if(status != RQ_SUCCESS)
	{
		cout<<"Error connecting to device " << devname << ": "<<status<<"."<<endl;
		return 1;
	}
#if 0
	cout<<"- SetConfig(_DINA, 1, 1)...";
	if((status = device.SetConfig(_DINA, 1, 1)) != RQ_SUCCESS)
		cout<<"failed --> "<<status<<endl;
	else
		cout<<"succeeded."<<endl;

	//Wait 10 ms before sending another command to device
	sleepms(10);
#endif
	int result;
	cout<<"- GetConfig(_DINA, 1)...";
	if((status = device.GetConfig(_DINA, 1, result)) != RQ_SUCCESS)
		cout<<"failed --> "<<status<<endl;
	else
		cout<<"returned --> "<<result<<endl;

	//Wait 10 ms before sending another command to device
	sleepms(10);

	cout<<"- GetValue(_ANAIN, 1)...";
	if((status = device.GetValue(_ANAIN, 1, result)) != RQ_SUCCESS)
		cout<<"failed --> "<<status<<endl;
	else
		cout<<"returned --> "<<result<<endl;

	//Wait 10 ms before sending another command to device
	sleepms(10);
#if 0
	cout<<"- SetCommand(_GO, 1, 1)...";
	if((status = device.SetCommand(_GO, 1, 1)) != RQ_SUCCESS)
		cout<<"failed --> "<<status<<endl;
	else
		cout<<"succeeded."<<endl;
#endif
	device.Disconnect();
	return 0;
}
