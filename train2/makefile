CPPFLAG=g++
EXEC=main testScore

all: $(EXEC)

main: main.o Pizza.o Table.o Score.o StringHandler.o
	$(CPPFLAG) -o $@ $^
testScore: testScore.o Table.o Score.o Pizza.o StringHandler.o
	$(CPPFLAG) -o $@ $^ 
%.o: %.cpp
	$(CPPFLAG) -o $@ -c $^
clean:
	rm -rf *.o
mrproper: clean
	rm -rf *.exe