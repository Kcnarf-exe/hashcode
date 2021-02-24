CPPFLAG=g++
EXEC=main testScore

all: $(EXEC)

main: main.o Pizza.o Table.o
	$(CPPFLAG) -o $@ $^
testScore: testScore.o
	$(CPPFLAG) -o $@ $^ 
%.o: %.cpp
	$(CPPFLAG) -o $@ -c $^
clean:
	rm -rf *.o
mrproper: clean
	rm -rf *.exe