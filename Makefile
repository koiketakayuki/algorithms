.PHONY: 1 2 clean

DIST = dist
SRC = src

$(DIST)/%: $(DIST)/%.o
	$(CC) $< -o $@

$(DIST)/%.o: $(SRC)/%.c
	$(CC) -o $@ -c $<

1: $(DIST)/1-linear-search
	./$<

2: $(DIST)/2-binary-search
	./$<

clean:
	rm -f $(DIST)/*
