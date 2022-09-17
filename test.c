#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "rs232.h"
#include "httpd.h"

const char *seps = ": ";
char *_;
int cport_nr;
const int SIZE = 512;

void parse_string(char *str){
	
	// extract CO2 levels
	_ = strtok(str, seps);
	int co2 = atoi(strtok(NULL, seps));

	// extract temperature
	_  = strtok(NULL, seps);
	double temp = strtod(strtok(NULL, seps), &_);

	// extract humidity
	_ = strtok(NULL, seps);
	double humidity = strtod(strtok(NULL, seps), &_);
}

int main()
{
	const char *mode = "8N1";
  	int bdrate = 115200;     

  	cport_nr = RS232_GetPortnr("ttyUSB1");

  	if(RS232_OpenComport(cport_nr, bdrate, mode, 0))
    	return -1;

	serve_forever("8000");
  	return 0;
}

void route() {

	unsigned char buf[SIZE];

	fprintf(stderr, "%s", uri);

	if (strcmp("/", uri) == 0 && strcmp("GET", method) == 0) {

		
  		printf("HTTP/1.1 200 OK\r\n");
		printf("Access-Control-Allow-Origin: *\r\n");
		printf("Accept: text/plain\r\n\r\n");

		int bytes = RS232_PollComport(cport_nr, buf, SIZE-1);

		if(bytes > 0 && bytes < SIZE) {
  	    	buf[bytes] = 0; 
      		for(int i = 0; i < bytes; i++) {
       		 	if(buf[i] < 32)
        	  		buf[i] = ' ';
			}
			printf("%s\n", (char *)buf);
		}
		else { 
			printf("NO DATA RECEIVED FROM SENSOR.");
		}

  		printf("\r\n\r\n");


	} else {
		printf(\
			"HTTP/1.1 500 Not Handled\r\n\r\n" \
			"The server has no handler to the request.\r\n" \
		);
	}


		
		// int bytes = RS232_PollComport(cport_nr, buf, SIZE-1);

		// if(bytes > 0 && bytes < SIZE) {
  	    // 	buf[bytes] = 0; 
      	// 	for(int i = 0; i < bytes; i++) {
       	// 	 	if(buf[i] < 32)
        // 	  		buf[i] = ' ';
		// 	}
		// 	printf("%s\n", (char *)buf);
		// }
		// else {
		// 	printf("no.");
		// }

		// if(strchr((char *)buf, ':') != NULL) {
		// 	parse_string((char *)buf);
		// }
		// else {
		// 	handle incorrect data
		// }

}