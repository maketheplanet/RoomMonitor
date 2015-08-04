#include<stdio.h>
#include "dht11Driver/bbb_dht_read.h"

int main(int argc, char *argv[]){
	// pin P8_11 is base 1, gpio 13
	int sensor = 11, base = 1,number = 13;
	float humidity = 0, temperature=0,tempF=0 ;
	int timeout=0;
	while(humidity==0){
		int result = bbb_dht_read(sensor,base,number,&humidity,&temperature);
		++timeout;
		if(timeout > 10)
		{
			break;
		}
	
	}
	if(temperature > 0){
		tempF = (temperature*9)/5+32;
	}
	printf("The Humidity is %4.2f and the Temperature is %4.2f\n",humidity,tempF);
	return 0;
}
