mainFile = main.cpp
libFile = lib.cpp

lib: $(libFile)
	g++ -c $(libFile)

main: $(mainFile)
	g++ -c $(mainFile)

build: lib.o main.o
	g++ lib.o main.o -lsfml-graphics -lsfml-window -lsfml-system -Ofast -o main

clear:
	rm main main.o lib.o
