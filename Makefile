## @author Lenoa

DEBUG=yes

EXEC=executable

ifeq ($(DEBUG),yes)
	CXXFLAGS=-g -W -Wall -pedantic
	LDFLAGS=$(CXXFLAGS) -lsfml-system -lsfml-window -lsfml-graphics
else
	CXXFLAGS=-O3
	LDFLAGS=$(CXXFLAGS) -lsfml-system -lsfml-window -lsfml-graphics
endif

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

/home/lenoa/programmes/hypermario/Map.o: Collision.h ImageManager.h Map.h Tile.h TileAttributes.h config.h
/home/lenoa/programmes/hypermario/Game.o: Game.h ImageManager.h Map.h Mario.h Tile.h TileAttributes.h config.h
/home/lenoa/programmes/hypermario/ImageManager.o: Exception.h Exception_ImageNotLoaded.h ImageManager.h
/home/lenoa/programmes/hypermario/main_corres_gen.o: TileAttributes.h
/home/lenoa/programmes/hypermario/main.o: Game.h ImageManager.h Map.h Tile.h TileAttributes.h config.h
/home/lenoa/programmes/hypermario/Collision.o: Collision.h
/home/lenoa/programmes/hypermario/Mario.o: Collision.h ImageManager.h Map.h Mario.h Tile.h TileAttributes.h config.h

$(EXEC): Collision.o Game.o ImageManager.o main.o Map.o Mario.o
	$(CXX) Collision.o Game.o ImageManager.o main.o Map.o Mario.o -o $(EXEC) $(LDFLAGS)
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

