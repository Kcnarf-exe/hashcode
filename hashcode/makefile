CPPFLAG=g++
EXEC=main

all: $(EXEC)

main: main.o Problem.o
	$(CPPFLAG) -o $@ $^
%.o: %.cpp
	$(CPPFLAG) -o $@ -c $^
clean:
	rm -rf *.o
mrproper: clean
	rm -rf *.exe