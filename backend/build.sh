gcc ./lib/rs232.c -o ./lib/rs232.o -c
gcc main.c -o main.o -c
gcc ./lib/httpd.c -o ./lib/httpd.o -c
gcc main.o ./lib/rs232.o ./lib/httpd.o -o main