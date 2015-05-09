#
# ICP 2014/2015 Makefie
#

all: gui cli

gui:
	@cd src && qmake -o Makefile && make
	mv src/labyrinth ./labyrinth2015

#fedora
fgui:
	@cd src && qmake-qt5 -o Makefile && make
	mv src/labyrinth ./labyrinth2015

cli:
	g++ src/test.cpp src/map.cpp src/player.cpp src/block.cpp -o labyrinth2015-cli

run: all
	./labyrinth2015-cli
	./labyrinth2015

clean:
	rm src/*.o  -rf
	rm src/Makefile  -rf
	rm labyrinth2015  -rf
	rm labyrinth2015-cli  -rf
	rm src/labyrinth -rf
