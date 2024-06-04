# Compiler
CC = c99

# Compiler flags
CFLAGS = -Wall 

# Source files
SRCS = 01-merge-sort.c 01-quick-sort.c 02-sin-cos.c 02-decrement.c 07-switch.c 08-clock.c

# Files in folder
challanges exercises Makefile

01-merge-sort : 01-merge-sort.c
	$(CC) $(CFLAGS) -o 01-merge-sort 01-merge-sort.c -lm
	
01-quick-sort : 01-quick-sort.c
	$(CC) $(CFLAGS) -o 01-quick-sort 01-quick-sort.c -lm
	
02-sin-cos : 02-sin-cos.c
	$(CC) $(CFLAGS) -o 02-sin-cos 02-sin-cos.c -lm
	
02-decrement : 02-decrement.c
	$(CC) $(CFLAGS) -o 02-decrement 02-decrement.c -lm
	
07-switch : 07-switch.c
	$(CC) $(CFLAGS) -o 07-switch 07-switch.c -lm
	
08-clock : 08-clock.c
	$(CC) $(CFLAGS) -o 08-clock 08-clock.c -lm

# Cleaning Generated Code
clean:
	rm -rf *.out 
