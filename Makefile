.PHONY: clean

DIST = dist
SRC = src

$(DIST)/%: %.o
	$(CC) $< -o $@

%.o: $(SRC)/%.c
	$(CC) -g -o $@ -c $<

1: $(DIST)/1-linear-search
2: $(DIST)/2-binary-search
3: $(DIST)/3-stack
4: $(DIST)/4-queue

clean:
	rm -f $(DIST)/*
