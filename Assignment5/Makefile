CXX = g++
CCXFLAGS = -I. -std=c++17 -Wall -g -fPIC

SRC = tests.cpp rational.cpp
OBJ = tests.o rational.o

TARGET = test

LDFLAGS = -lgtest -lgtest_main -pthread

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS)

$(OBJ): $(SRC)
	$(CXX) $(CXXFLAGS) -I/usr/local/include -c $(SRC)

clean:
	rm -f $(OBJ) $(TARGET)

run: $(TARGET)
	./$(TARGET)