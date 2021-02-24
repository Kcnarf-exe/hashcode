CPPFLAG=g++
EXEC=makeAij

all: $(EXEC)

makeAij: makeAij.o
	$(CPPFLAG) -o $@ $^
%.o: %.cpp
	$(CPPFLAG) -o $@ -c $^
clean:
	rm -rf *.o
mrproper: clean
	rm -rf *.exe