include make_config
include make_consts_unix

.PHONY: force

base.o: base.h base.c
	$(GCC) -c base.c -o base.o

core.o: base.o core/ core/Makefile force
	$(MAKE) -C core/
	$(COPY) core/core.o ./

packs.o: base.o packs/ packs/Makefile force
	$(MAKE) -C packs/
	$(COPY) packs/packs.o ./

main.o: main.c base.h
	$(GCC) -c main.c -o main.o

eavm: main.o core.o base.o #packs.o
	$(GCC) main.o core.o base.o -o eavm
	$(COPY) ./eavm ./test


.PHONY: run
run: eavm test.eav
	cd test
	./eavm test.eav


.PHNOY: result_only
result_only:
	$(RM) -f core.o packs.o main.o base.o
	$(MAKE) -C core clean
	$(MAKE) -C packs clean


.PHONY: clean
clean:
	$(MAKE) result_only
	$(RM) -f eavm