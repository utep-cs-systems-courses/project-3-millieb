#makefile configuration
COMMON_ONJECTS =
CPU	       = msp430g2553
CFLAGS	       = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

#switch the compiler (for the internal make rules)
CC	       = msp430-elf-gcc
AS             = msp430-elf-as -mcpu=msp430 --traditional-format -mp

all: button.elf

#additional rules for files
button.elf: ${COMMON_OBJECTS} p2_interrupt_handler.o song.o dog.o lcddraw.o lcdutils.o font-8x12.o WDInterruptHandler.o switches.o buzzer.o main.o stateMachines.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^


load: button.elf
	msp430loader.sh button.elf


clean:
	rm -f *.o *.elf
