CXX = g++
CXXFLAGS = -std=c++11 -Wall

all: examheap

examheap: examheap.o heap.o
	$(CXX) $(CXXFLAGS) -o examheap examheap.o heap.o

examheap.o: examheap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c examheap.cpp

heap.o: heap.cpp heap.h
	$(CXX) $(CXXFLAGS) -c heap.cpp

clean:
	rm -f *.o examheap