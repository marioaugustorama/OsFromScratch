all: bootwriter

bootwriter: bootwriter.o
	gcc -o $@ $<

bootwriter.o: bootwriter.c
	gcc -c $<

clean:
	rm *.o bootwriter *.bin *.img
