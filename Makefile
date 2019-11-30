CC = gcc

all:main.o admin_login.o booking_copy.o c.o CP.o c_pro1.o c_project.o flights.o printing.o seat.o user_login.o
	$(CC) main.c admin_login.c booking_copy.c c.c CP.c c_pro1.c c_project.c flights.c printing.c seat.c user_login.c -o airlines
clean:
	rm *.o airlines