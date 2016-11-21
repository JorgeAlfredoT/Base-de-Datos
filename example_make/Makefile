gato: main.o message.o
	g++ main.o message.o -o gato
main.o : main.cpp
	g++ -c main.cpp
message.o : message.cpp message.h
	g++ -c message.cpp
clean:
	rm *.o gato
