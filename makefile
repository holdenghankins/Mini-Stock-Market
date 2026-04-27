run: security.o stock.o main.o
	g++ -g security.o stock.o main.o -o run

security.o: security.cpp
	g++ -c -g security.cpp

stock.o: security.h stock.cpp
	g++ -c -g stock.cpp

main.o: security.h stock.h main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o
	rm run

run: run
	./run

debug: run
	gdb run