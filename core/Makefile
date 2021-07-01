include ../make_config
include ../make_consts_unix

core.o: main.c main.h ../base.h
	$(GCC) -c main.c -o core.o

clean:
	$(RM) -f core.o