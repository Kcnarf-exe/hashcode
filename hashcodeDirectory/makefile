CPPFLAG=g++
EXEC=main evaluate

all: $(EXEC)

evaluate: evaluate.o Problem.o Score.o
	$(CPPFLAG) -o $@ $^
main: main.o Car.o Intersection.o Street.o Problem.o
	$(CPPFLAG) -o $@ $^
%.o: %.cpp
	$(CPPFLAG) -o $@ -c $^
clean:
	rm -rf *.o
mrproper: clean
	rm -rf *.exe