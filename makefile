sim: security.o stock.o fund.o sector.o market.o main.o
	g++ -g security.o stock.o fund.o sector.o market.o main.o -o sim

security.o: security.cpp
	g++ -c -g security.cpp

stock.o: security.h stock.cpp
	g++ -c -g stock.cpp

fund.o: security.h fund.cpp
	g++ -c -g fund.cpp

sector.o: security.h stock.h fund.h sector.cpp
	g++ -c -g sector.cpp

market.o: security.h stock.h fund.h sector.h market.cpp
	g++ -c -g market.cpp

main.o: security.h stock.h fund.h sector.h market.h main.cpp
	g++ -c -g main.cpp

clean:
	rm *.o
	rm sim

run: sim
	./sim

debug: sim
	gdb sim