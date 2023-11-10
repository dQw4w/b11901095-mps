# CC and CFLAGS are varilables
CC = g++
CFLAGS = -c
AR = ar
ARFLAGS = rcv
# -c option ask g++ to compile the source files, but do not link.
# -g option is for debugging version
# -O2 option is for optimized version


all	: bin/mps
	@echo -n ""

# optimized version
bin/mps	:  main.o lib
			$(CC) $(OPTFLAGS)  main.o -ltm_usage -Llib -o bin/mps
main.o 	: src/main.cpp lib/tm_usage.h
			$(CC) $(CFLAGS) $< -Ilib -o $@
mst.o	:  src/mst.h
			$(CC) $(CFLAGS) $(DBGFLAGS) $< -o $@


# clean all the .o and executable files
clean:
		rm -rf *.o lib/*.a lib/*.o bin/*

