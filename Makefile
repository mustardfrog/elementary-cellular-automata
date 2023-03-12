CC=g++
SRCS=main.cpp Global.cpp Cell.cpp
FLAGS=-lSDL2 -lSDL2_image
WARNS=-Wall -Wextra

main: $(SRCS)
	$(CC) $(SRCS) -o main $(FLAGS) $(WARNS) 

test: main
	./main
