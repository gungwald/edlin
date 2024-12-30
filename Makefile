.PHONY: all edlin clean


all: edlin


edlin:
	$(MAKE) -C edlin


clean:
	$(MAKE) -C edlin clean

