#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <time.h>
extern "C"{
#include "dht11Driver/bbb_dht_read.h"
}
using namespace std;

int main(){
	string to("heathcasey@maketheplanet.com");
	string subject("Office Climate Reading");
	string body("Temperature and Humidity Reading from 3102.\n");
	stringstream command;
	float humidity = 0, temperature =0, tempF=0;
	int timeOut=0;
	int sensor =11, base =1, number =13;
	while(humidity == 0){
		int result = bbb_dht_read(sensor,base,number,&humidity,&temperature);
		++timeOut;
		if(timeOut >10){break;}
	}
	if(temperature > 0){
		tempF=(temperature*9)/5+32;
	}
	if(tempF > 75){
		command << "./roomMonitor | mail -s \"" << subject <<"\" " << to;
		int result = system(command.str().c_str());
	}
	//cout << "Command: " << command_str() << endl;
	//cout << "the return value was " << result << endl;
	cout << "The humidity is "<<humidity << " and the Temperature is "<<tempF << endl;


	return tempF;

	

}
