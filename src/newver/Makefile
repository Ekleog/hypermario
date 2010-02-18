DEBUG=yes

EXEC=executable

ifeq ($(DEBUG),yes)
	CXXFLAGS=-g -W -Wall -pedantic
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

corres_gen: main_corres_gen.o
	$(CXX) main_corres_gen.o -o corres_gen

Game.o: Game.h Mario.h Map.h Tile.h TileAttributes.h ImageManager.h
ImageManager.o: ImageManager.h Exception_ImageNotLoaded.h Exception.h
main.o: Tile.h Map.h Mario.h TileAttributes.h ImageManager.h
main_corres_gen.o: TileAttributes.h
Map.o: Map.h Tile.h TileAttributes.h Mario.h ImageManager.h
Mario.o: Mario.h TileAttributes.h Map.h
Tile.o: Tile.h ImageManager.h

$(EXEC): ImageManager.o Tile.o Map.o main.o Game.o Mario.o
	$(CXX) ImageManager.o Tile.o Map.o main.o Game.o Mario.o -o $(EXEC) $(LDFLAGS)
clean:
	$(RM) -f *~
	$(RM) -f maps/*~
	$(RM) -f images/*~
	$(RM) -f *.o
mrproper: clean
	$(RM) -f $(EXEC)
	$(RM) -f corres_gen

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

