#include<stdio.h>
#include "dht11Driver/bbb_dht_read.h"

int main(int argc, char *argv[]){
	int sensor = 11, base = 1,number = 13;
	float humidity = 0, temperature=0;
	// pin P8_11 is base 1, gpio 13
	int result = bbb_dht_read(sensor,base,number,&humidity,&temperature);

	printf("The temp is %4.2f and the Humidity is %4.2f",humidity,temperature);
	return 0;
}
