
ERRORS=-Wall -Wextra -Wpedantic
DEBUG=-g
FILES=game_of_life.cpp Grid.cpp graphic.hpp
LIB=-lncurses -lSDL2
O=-o app

app: game_of_life.cpp
	g++ $(O) $(FILES) $(LIB) $(ERRORS) $(DEBUG)

#END
