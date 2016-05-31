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
			_dying = 14;
			_buy_price = 3.6; 
			_sell_price = 3; 
			_costs = 50; 
			_prod_price = 0.5;
			if (_sex == 1) setProductiveness(100,300,i); //jajka
			else setProductiveness(0,0,i);
			break;
		case cow: 
			_procreate = 1;
			_dying = 15;
			_buy_price = 4000; 
			_sell_price = 3000; 
			_costs = 500; 
			_prod_price = 1.5;
			if (_sex == 1) setProductiveness(5000,10000,i); //mleko
			else setProductiveness(0,0,i);
			break;
		case pig: 
			_procreate = 2;
			_dying = 20;
			_buy_price = 200; 
			_costs = 300; 
			_prod_price = 5.2;
			setProductiveness(40,300,i); //kg mięsa
			_sell_price = _productiveness * _prod_price;
			break;
		case sheep: 
			_procreate = 7;
			_dying = 12;
			_buy_price = 200; 
			_sell_price = 150; 
			_costs = 300; 
			_prod_price = 2;
			setProductiveness(100,500,i); //wełna
			break;
		case horse: 
			_procreate = 1;
			_dying = 30;
			_buy_price = 7000; 
			_sell_price = 5000; 
			_costs = 400; 
			_prod_price = 0;
			setProductiveness(0,0);
			break;
		case rabbit:
			_procreate = 100;
			_dying = 8;
			_buy_price = 30; 
			_sell_price = 20; 
			_costs = 50; 
			_prod_price = 0;
			setProductiveness(0,0);
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

Dog::Dog(int proc, int die, int prod_x, int prod_y, double buy, double sell, double cost, double prodp)
:Animal(proc, die, prod_x, prod_y, buy, sell, cost, prodp)
{
	_attacks_protected = 0;
}


bool Dog::protect(){
	_attacks_protected++;
	if (_attacks_protected > productiveness()) return false;
	else return true;
}