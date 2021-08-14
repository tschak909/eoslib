CC=zcc +coleco -subtype=adam -leos

all: scratchpad 

clean:
	$(RM) -f scratchpad *.o *.ddp *bin

main.o: scratchpad.c
	$(CC) -o scratchpad.o -c scratchpad.c

scratchpad: scratchpad.o
	$(CC) -oscratchpad -create-app scratchpad.o
