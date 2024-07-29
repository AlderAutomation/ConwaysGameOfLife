CXX=g++
CXXFLAGS=-std=c++11 -Wall -g
LDFLAGS=-lsfml-graphics -lsfml-window -lsfml-system

SOURCES=ConwayGOL.cpp LifeForm.cpp GOLWorld.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=ConwayGOL.out

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
