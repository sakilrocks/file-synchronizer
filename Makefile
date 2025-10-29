
CXX = g++
CXXFLAGS = -std=c++17 -pthread -Wall
LIBS = -lcrypto
SRC = src/main.cpp src/filehasher.cpp src/filescanner.cpp src/syncmanager.cpp
OUT = bin/filesync

all:
	mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(OUT) $(LIBS)

clean:
	rm -rf bin