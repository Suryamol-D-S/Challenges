# Compiler
CC = c99

# Compiler flags
CFLAGS = -Wall 

LDFLAGS := -lm
# Source files
objects = exercises/02-decrement \
	exercises/14-unsigned \
	exercises/13-signed-long-long \
	exercises/04-macro-max \
	exercises/Man-struct-tm \
	exercises/59-hexatridecimal \
	exercises/07-rat-get-prod \
	exercises/01-if \
	exercises/17-implicit-conversion \
	exercises/22-a-b \
	exercises/33-INT_MAX \
	exercises/String-function \
	exercises/09-shift-numbers-pointers \
	exercises/03-macro-sum \
	exercises/08-clock \
	exercises/54-stdout \
	exercises/07-switch \
	challanges/05-complex-numbers \
	challanges/01-merge-sort \
	challanges/06-linear-algebra \
	challanges/09-factorization \
	challanges/10-performance-comparison \
	challanges/07-adjacency-matrix \
	challanges/04-Union-find \
	challanges/03-pi \
	challanges/01-quick-sort \
	challanges/02-sin-cos \
	exercises/08--type-computation

all: $(objects)

$(objects): %: %.c
	$(CC) $(CFLAGS)  -o $@  $< $(LDFLAGS)


# Cleaning Generated Code
clean:
	rm -rf $(objects)
