#include <iostream>
#include <vector>
#include <math.h>

#include "Animals.h"
#include "Herd.h"
#include "action.h"

void randomIncidents(Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void clear();
void pause();
int start();
void menu(double&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, int&, int&, int&, int&, int&, int&, int&);
void period(double&, int, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, int&, int&, int&, int&, int&, int&, int&);
void summary(double&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void bankruptcy(double&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
int isCorrect(int);

/*
- uzytkownik wybiera liczbe lat symulacji
- menu do podejmowania decyzji w sprawie farmy (co chce kupic/sprzedac)
- petla do liczba_lat, w kazdym obrocie powiekszaja sie stada, mozna sprzedawac zwierzeta/produkty, kupować zwierzeta. Przy kazdym obrocie musi
wyswietlac sie info: ile jakich zwierzat i jakiej plci ma uzytkownik, ile roslin, ile ma hajsu i czy ktos atakowal jego zwierzeta albo ukradł :p
- w każdym obrocie mogą zdarzyć się zdarzenia losowe - drapieżnik/złodziej -> usuwa losowe osobniki i wyswietla info, że zabrał kilka osobnikow
- zwierzeta przechowywane sa w vectorze (lepiej niz w kolejce, bo mozna usuwac srodkowe elementy tez)
*/

using namespace std; 

int main(int argc, char** argv){

	int semestr=start();

	int rozmiar = 0;

	srand(time(NULL));

	double money=(rand()%2+1)*10000;

	int newCows, newChickens, newDogs, newSheeps, newHorses, newPigs, newRabbits;			

	Herd cows;
	Herd rabbits;
	Herd sheeps;
	Herd chickens;
	Herd horses;
	Herd pigs;
	Herd dogs;

	int i=1;

	while(money>=0 && i<=semestr){

		period(money, i, dogs, cows, rabbits, sheeps, chickens, horses, pigs, newCows, newRabbits, newPigs, newHorses, newSheeps, newDogs, newChickens);

		menu(money, dogs, cows, rabbits, sheeps, chickens, horses, pigs, newCows, newRabbits, newPigs, newHorses, newSheeps, newDogs, newChickens);

		i++;

	}

	if(money>=0)
		summary(money, dogs, cows, rabbits, sheeps, chickens, horses, pigs);

	else
		bankruptcy(money, dogs, cows, rabbits, sheeps, chickens, horses, pigs);

	return 0;
	
}