include make_config

core.o: core/ core/Makefile
	$(MAKE) -C core/
	$(COPY) core/core.o ./

packs.o: packs/ packs/Makefile
	$(MAKE) -C packs/
	$(COPY) packs/packs.o ./

eavm: core.o packs.o
	$(GCC) core.o packs.o -o eavm
