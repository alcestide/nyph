CXX = g++
CXXFLAGS = -O3 -Wall -std=c++17

LDFLAGS = -lSDL2

TARGET = build/nyph

all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
