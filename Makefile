CC=g++
CFLAGS=-c -Wall 
SOURCES=todo.cc main.cc
OBJECTS=$(SOURCES:.cc=.o)
EXECUTABLE=todo_app

all: $(SOURCES) $(EXECUTABLE) 

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ `pkg-config gtkmm-3.0 --libs`

.cc.o:
	$(CC) $(CFLAGS) $< -o $@ `pkg-config gtkmm-3.0 --cflags`

clean:
	rm -rf *.o todo_app
