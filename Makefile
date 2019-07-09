CC=g++
CFLAGS=-c -Wall 
SOURCES=todo.cpp main.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=todo_app

all: 
	g++ $(SOURCES) -o todo_app `pkg-config --cflags --libs gtkmm-3.0`


clean:
	rm -rf *.o todo_app
