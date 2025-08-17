all:
	g++ Orbito_game.cc Orbito.cc -o Orbito_game.out
	./Orbito_game.out
Wall:
	g++ -Wall Orbito_game.cc Orbito.cc -o Orbito_game.out
	./Orbito_game.out
exe:
	g++ Orbito_game.cc Orbito.cc -o Orbito_game.exe
	./Orbito_game.exe

project:
	g++ Bot_Project.cc Orbito.cc -o Bot_Project.out
