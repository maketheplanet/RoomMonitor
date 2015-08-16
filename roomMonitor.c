#include<stdio.h>
#include <time.h>
#include "dht11Driver/bbb_dht_read.h"

int main(int argc, char *argv[]){
	time_t timer;
	char buffer[26];
	struct tm* tm_info;
	time(&timer);
	tm_info = localtime(&timer);
	strftime(buffer,26,"%Y%m%d%H%M",tm_info);
	// pin P8_11 is base 1, gpio 13
	int sensor = 11, base = 1,number = 13;
	float humidity = 0, temperature=0,tempF=0 ;
	int timeout=0;
	FILE *datFile=fopen("temperatureData.txt","a");
	while(humidity==0){
		int result = bbb_dht_read(sensor,base,number,&humidity,&temperature);
		++timeout;
		if(timeout > 10)
		{
			break;
		}
	
	}
	if(temperature > 0){
		tempF = (temperature*9)/5+32;//offset for more accurate temp
	}
	printf("%s The Humidity is %4.2f and the Temperature is %4.2f\n",buffer,humidity,tempF);
	fprintf(datFile,"%s\t%4.2f\t%4.2f\n",buffer,humidity,tempF);
	fclose(datFile);

	return 0;
}
