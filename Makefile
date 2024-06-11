# Compiler
CC = c99

# Compiler flags
CFLAGS = -Wall 

# Source files
SRCS = 01-merge-sort.c 01-quick-sort.c 02-sin-cos.c 02-decrement.c 07-switch.c 08-clock.c 03-pi.c 05-complex-numbers.c 06-linear-algebra.c 07-adjacency-matrix.c 09-factorization.c 
		01-if.c 13-signed-long-long.c 14-unsigned.c 17-implicit-conversion.c 22-A\B.c 33-INT_MAX.c Man-struct-tm.c String-function.c

# object files
OBJS = $(SRCS:.c=.o)

# Files in folder
challanges exercises Makefile

TARGET = program

all : $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< -lm

# Cleaning Generated Code
clean:
	rm -rf $(OBJS)
