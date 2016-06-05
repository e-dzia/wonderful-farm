#include <cstdlib>
#include <time.h>
#include "Animals.h"

double Animal::_buy_chicken = 3.6;
double Animal::_buy_cow = 4000;
double Animal::_buy_pig = 200;
double Animal::_buy_sheep = 200;
double Animal::_buy_horse = 7000;
double Animal::_buy_rabbit = 30;
double Animal::_buy_dog = 800;

double Animal::costs_chicken = 50;
double Animal::costs_cow = 500;
double Animal::costs_pig = 300;
double Animal::costs_sheep = 300;
double Animal::costs_horse = 400;
double Animal::costs_rabbit = 50;
double Animal::costs_dog = 400;

Animal::Animal(animals type, int i){
	_type = type;
	srand(time(NULL)+i);
	_age = 0;
	_sex = (rand()%2+i%2)%2;
	switch(type){
	case chicken: 
			if ((rand()+i)%6 == 0) _sex = 0;
			else _sex = 1;
			_procreate = 10;
			_dying = 14;
			_sell_price = 3; 
			_buy_price = _buy_chicken;
			_costs = costs_chicken; 
			_prod_price = 0.5;
			if (_sex == 1) setProductiveness(100,300,i); //jajka
			else setProductiveness(0,0,i);
			break;
		case cow: 
			if ((rand()+i)%6 == 0) _sex = 0;
			else _sex = 1;
			_procreate = 1;
			_dying = 15;
			_buy_price = _buy_cow;
			_sell_price = 3000; 
			_costs = costs_cow; 
			_prod_price = 1.5;
			if (_sex == 1) setProductiveness(5000,10000,i); //mleko
			else setProductiveness(0,0,i);
			break;
		case pig: 
			_procreate = 2;
			_dying = 20;
			_costs = costs_pig; 
			_buy_price = _buy_pig;
			_prod_price = 5.2;
			setProductiveness(40,300,i); //kg mięsa
			_sell_price = _productiveness * _prod_price;
			break;
		case sheep: 
			_procreate = 7;
			_dying = 12;
			_buy_price = _buy_sheep;
			_sell_price = 150; 
			_costs = costs_sheep; 
			_prod_price = 2;
			setProductiveness(100,500,i); //wełna
			break;
		case horse: 
			_procreate = 1;
			_dying = 30;
			_sell_price = 5000; 
			_buy_price = _buy_horse;
			_costs = costs_horse; 
			_prod_price = 0;
			setProductiveness(0,0);
			break;
		case rabbit:
			_procreate = 100;
			_dying = 8;
			_buy_price = _buy_rabbit;
			_sell_price = 20; 
			_costs = costs_rabbit; 
			_prod_price = 0;
			setProductiveness(0,0);
			break;
		case dog:
			_procreate = 1;
			_dying = 15;
			_sell_price = 500; 
			_buy_price = _buy_dog;
			_costs = costs_dog; 
			_prod_price = 0;
			setProductiveness(2,10);
			break;
	}
	
}

Animal::Animal(int proc, int die, int prod_x, int prod_y, double buy, double sell, double cost, double prodp, int i){
	srand(time(NULL)+i);
	_age = 0;
	_sex = (rand()%2+i%2)%2;
	_procreate = proc;
	_dying = die;
	_buy_price = buy; 
	_sell_price = sell; 
	_costs = cost; 
	_prod_price = prodp;
	setProductiveness(prod_x, prod_y);
	_type = dog;
}

void Animal::setProductiveness(int x, int y, int i){
	srand(time(NULL) + i);
	if (y!=0 || x!= 0) _productiveness = (rand()*(i+1))%(y-x) + x;
	else _productiveness = 0;
}

bool Animal::ageing(){
	_age++;
	_sell_price += _buy_price * 0.15;
	if (_age >= _dying) return false;
	else return true;
}

Dog::Dog(int i, int proc, int die, int prod_x, int prod_y, double buy, double sell, double cost, double prodp)
:Animal(proc, die, prod_x, prod_y, buy, sell, cost, prodp, i)
{
	_attacks_protected = 0;
}

bool Animal::protect(int n){}

bool Dog::protect(int n){
	_attacks_protected += n;
	if (_attacks_protected > productiveness()) return false;
	else return true;
}

bool Dog::ageing(){
	_attacks_protected = 0;
	return Animal::ageing();
}
