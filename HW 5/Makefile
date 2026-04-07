#Variables
CXX = c++
CXXFLAGS = -std=c++23 -Wall -Wextra -g
TARGET = solution
SRC = solution.cpp

all: $(TARGET)

$(TARGET):$(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS)


clean:
	rm -f $(TARGET)
	rm -f *.csv


test: $(TARGET)
	pytest test_game.py	




