PROJECT = transformer
LIBPROJECT = $(PROJECT).a
TESTPROJECT = test-$(PROJECT)

CXX = g++
A = ar
AFLAGS = rsv

CCXFLAGS = -I. -std=c++17 -Wall -g -fPIC
LDXXFLAGS = $(CCXFLAGS) -L. -l:$(LIBPROJECT)
LDGTESTFLAGS = $(LDXXFLAGS) -lgtest -lgtest_main -lpthread

DEPS=$(wildcard *.h)

OBJ=Transformer.o PrimaryWeapon.o SparkCore.o Scout.o Warrior.o AerialBot.o
TEST-OBJ=test-transformer.o test-scout.o

.PHONY: default

default: all;

%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(LIBPROJECT): $(OBJ)
	$(A) $(AFLAGS) $@ $^

$(PROJECT): main.o $(LIBPROJECT)
	$(CXX) -o $@ main.o $(LDXXFLAGS)


$(TESTPROJECT): $(LIBPROJECT) $(TEST-OBJ)
	$(CXX) -o $@ $(TEST-OBJ) $(LDGTESTFLAGS)

test: $(TESTPROJECT)

all: $(PROJECT)

.PHONY: clean

clean:
	rm -f *.o
	rm -f $(PROJECT)
	rm -f $(LIBPROJECT)
	rm -f $(TESTPROJECT)