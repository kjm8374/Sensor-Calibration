#Standard compile flags

SOURCE1   = hw11.c DynamicArrays.c
SOURCE2   = correction.c
PROG1     = hw11 
PROG2     = correction
CC        = gcc
CFLAGS    = -Wall -std=c99  -g -lgsl -lgslcblas  
HW8       = -DHW8
VALGRIND  = valgrind --tool=memcheck --leak-check=yes --track-origins=yes
REAL      = realDevice
ERROR     = detError
PLOT      = myplot
VAl       = diffVal
GRAPH     = graph.png
POINT     = -p
CHMOD     = chmod +x
ORDER     = -o 3
MEMOUT    = mem.txt
DATA      = data.txt
REALTXT   = realdevice.txt
CORRTXT   = correction.txt
ALLTXT    = alldata.txt

all: $(PROG1) $(PROG2)

$(PROG1): $(SOURCE1)
	$(CC) $(CFLAGS) $(HW8) $(SOURCE1) -o $(PROG1)

$(PROG2): $(SOURCE2)
	$(CC) $(CFLAGS) $(SOURCE2) -o $(PROG2)

base: 
	./$(REAL) | ./$(ERROR)

correct: $(PROG2)
	./$(REAL) | ./$(PROG2) | ./$(ERROR)

plot: $(PROG2)
	./$(REAL) > $(REALTXT)
	./$(REAL) | ./$(PROG2) > $(CORRTXT)
	paste $(REALTXT) $(CORRTXT) > $(ALLTXT)
	./$(PLOT) -i $(ALLTXT) -out $(GRAPH)

mem: $(PROG1)
	$(VALGRIND) ./$(PROG1) $(ORDER) $(POINT) $(DATA) &> $(MEMOUT)

x: 
	$(CHMOD) $(REAL) $(ERROR) $(PLOT) $(VAL)

clean:
	-rm -f $(OBJS) $(PROG1) $(PROG2) $(MEMOUT) $(REALTXT) $(CORRTXT) $(ALLTXT) $(GRAPH)  

.PHONY: clean

.SILENT:

.PHONY: help  

help:
	echo "make options: all, base, correct, plot, mem, x, help, clean"
