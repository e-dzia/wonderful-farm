#include <cstdlib>
#include <time.h>
#include "Animals.h"

Animal::Animal(animals type, int i){
	_type = type;
	srand(time(NULL)+i);
	_age = 0;
	_sex = (rand()%2+i%2)%2;
	switch(type){
	case chicken: 
			_procreate = 10;
			_dying = 2;
			if (_sex == 1) setProductiveness(20,40,i); //jajka
			else setProductiveness(0,0,i);
			break;
		case cow: 
			_procreate = 1;
			_dying = 5;
			if (_sex == 1) setProductiveness(40,80,i); //mleko
			else setProductiveness(0,0,i);
			break;
		case pig: 
			_procreate = 2;
			_dying = 3;
			setProductiveness(40,100,i); //kg mięsa
			break;
		case sheep: 
			_procreate = 7;
			_dying = 3;
			setProductiveness(10,50,i); //wełna
			break;
		case horse: 
			_procreate = 1;
			_dying = 10;
			setProductiveness(0,0);
			break;
		case rabbit:
			_procreate = 100;
			_dying = 1;
			setProductiveness(0,0);
			break;
	}
	
}

Animal::Animal(int proc, int die, int prod_x, int prod_y, int i){
	srand(time(NULL)+i);
	_age = 0;
	_sex = (rand()%2+i%2)%2;
	_procreate = proc;
	_dying = die;
	setProductiveness(prod_x, prod_y);
}

void Animal::setProductiveness(int x, int y, int i){
	srand(time(NULL) + i);
	if (y!=0 && x!= 0) _productiveness = (rand()*(i+1))%(y-x) + x;
	else _productiveness = 0;
}

bool Animal::ageing(){
	_age++;
	if (_age >= _dying) return false;
	else return true;
}

Dog::Dog(int proc, int die, int prod_x, int prod_y)
:Animal(proc, die, prod_x, prod_y)
{
	_attacks_protected = 0;
}
