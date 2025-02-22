# Set Version

CXX = g++
CXXFLAGS = -std=c++17

SRC = ThreadPool.cpp main.cpp

EXEC = threadPool

all: $(EXEC)

$(EXEC):
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(SRC)

clean:
	rm -f $(EXEC)