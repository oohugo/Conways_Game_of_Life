


ERRORS=-Wall -Wextra -Wpedantic
DEBUG=-g
FILES=game_of_life.cpp Grid.cpp
LIB=-lncurses 
O=-o app

app: game_of_life.cpp
	g++ $(O) $(FILES) $(LIB) $(ERRORS) $(DEBUG)

#END
