# Makefile projektui "Studentų analizės sistema"

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17
SRC = v2.cpp Studentas.cpp funkcijos.cpp
HEADERS = Studentas.h Zmogus.h funkcijos.h
TARGET = programa

TEST_SRC = test_studentas.cpp Studentas.cpp
TEST_TARGET = testai

.PHONY: all clean run test

all: $(TARGET)

$(TARGET): $(SRC) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

test: $(TEST_SRC)
	$(CXX) $(CXXFLAGS) -o $(TEST_TARGET) $(TEST_SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) $(TEST_TARGET)
