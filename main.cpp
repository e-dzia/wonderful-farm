#include <iostream>
#include <vector>
#include <math.h>

#include "Animals.h"
#include "Herd.h"
#include "action.h"

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