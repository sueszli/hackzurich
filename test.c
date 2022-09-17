#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "rs232.h"

int main()
{
	const int SIZE = 4096;
	const char *mode = "8N1";
  	int bdrate = 115200;     
  	unsigned char buf[SIZE];

  	int cport_nr = RS232_GetPortnr("ttyUSB0");

  	if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
    	return -1;

  	while(1) {
    	
		int bytes = RS232_PollComport(cport_nr, buf, 4095);

		if(bytes <= 0)
			continue;

      	buf[bytes] = 0; 

      	for(int i = 0; i < bytes; i++)
        	if(buf[i] < 32)
          		buf[i] = ' ';

      	printf("%s\n", (char *)buf);

    	usleep(100000); 
  }

  return 0;
}