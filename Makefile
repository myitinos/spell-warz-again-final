UserInterface.o: lib/UserInterface.cpp lib/UserInterface.hpp
	g++ -c lib/UserInterface.cpp -o UserInterface.o

Battle.o: lib/Battle.cpp lib/Battle.hpp
	g++ -c lib/Battle.cpp -o Battle.o

Spell.o: lib/Spell.cpp lib/Spell.hpp
	g++ -c lib/Spell.cpp -o Spell.o

Character.o: lib/Character.cpp lib/Character.hpp
	g++ -c lib/Character.cpp -o Character.o

spell-warz-again: Spell.o Character.o UserInterface.o Battle.o main.cpp
	g++ main.cpp -o spell-warz-again Spell.o Character.o UserInterface.o Battle.o

clean: all
	rm Spell.o Character.o UserInterface.o Battle.o

all: spell-warz-again
