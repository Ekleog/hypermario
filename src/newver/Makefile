DEBUG=yes

EXEC=executable

ifeq ($(DEBUG),yes)
	CXXFLAGS=-g -W -Wall
else
	CXXFLAGS=-O3
endif
LDFLAGS=$(CXXFLAGS) -lsfml-graphics

CXX=g++
RM=rm

.PHONY: all, clean, mrproper
.SUFFIXES:

all: $(EXEC)
ifeq ($(DEBUG),yes)
	@echo "Compiled in DEBUG mode"
else
	@echo "Compiled in RELEASE mode"
endif

$(EXEC): ImageManager.o Tile.o Map.o main.o
	$(CXX) ImageManager.o Tile.o Map.o main.o -lsfml-graphics -o $(EXEC) $(LDFLAGS)
clean:
	$(RM) -f *~
	$(RM) -f *.o
mrproper: clean
	$(RM) -f $(EXEC)

ImageManager.o: ImageManager.h Exception_ImageNotLoaded.h Exception.h
Tile.o: Tile.h ImageManager.h
Map.o: Map.h Tile.h ImageManager.h
main.o:


%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

