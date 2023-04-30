simulator: main.o RequestArray.o KeyedItem.o PriorityQueue.o Heap.o Simulator.o
	g++ main.o RequestArray.o KeyedItem.o PriorityQueue.o Heap.o Simulator.o -o simulator -std=c++11
	
main.o: main.cpp
	g++ -c main.cpp -std=c++11

RequestArray.o: RequestArray.cpp
	g++ -c RequestArray.cpp

KeyedItem.o: KeyedItem.cpp
	g++ -c KeyedItem.cpp

PriorityQueue.o:	PriorityQueue.cpp
	g++ -c PriorityQueue.cpp
	
Heap.o:	Heap.cpp
	g++ -c Heap.cpp

Simulator.o: Simulator.cpp
	g++ -c Simulator.cpp

clean:
	rm *.o simulator