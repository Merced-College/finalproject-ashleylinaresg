CXX = g++
CXXFLAGS = -std=c++11

TARGET = adventure

SOURCES = main.cpp Player.cpp Enemy.cpp Room.cpp LinkedList.cpp GameMap.cpp InventoryManager.cpp SaveManager.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJECTS) $(TARGET)