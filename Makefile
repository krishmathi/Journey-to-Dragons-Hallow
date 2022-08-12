final:	main.o Fighter.o Hero.o Player.o Quest.o random.o Dragon.o
	g++ -o final main.o Fighter.o Hero.o Player.o Quest.o random.o Dragon.o

Fighter.o: Fighter.cc Fighter.h
	g++ -c Fighter.cc

Dragon.o: Dragon.cc Dragon.h
	g++ -c Dragon.cc

Hero.o: Hero.cc Hero.h
	g++ -c Hero.cc

Player.o: Player.cc Player.h
	g++ -c Player.cc

Quest.o: Quest.cc Quest.h View.h
	g++ -c Quest.cc

main.o:	main.cc Quest.h
	g++ -c main.cc

random.o: random.cc
	g++ -c random.cc

clean:
	rm -f *.o final
