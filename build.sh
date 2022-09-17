gcc rs232.c -o rs232.o -c
gcc test.c -o test.o -c
gcc httpd.c -o httpd.o -c
gcc test.o rs232.o httpd.o -o test