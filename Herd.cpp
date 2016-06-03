#include "Herd.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Herd::Herd(Animal * tab[], int n){
	_vecAnimals.push_back(tab[0]);
	for (int i = 1; i < n; i++){
		if (tab[i]->type() == _vecAnimals.back()->type())
			_vecAnimals.push_back(tab[i]);
		else{
			cout << "Blad! Nie udalo sie stworzyc klasy :(" << endl;
			break;
		}
	}
}

Herd::Herd(){
	;
}

int Herd::size(int years) const {
	if (years == -1) return _vecAnimals.size();
	else{
		int n = 0;
		for (int i = 0; i < _vecAnimals.size(); i++){
			if (_vecAnimals[i]->age()==years) n++;
		}
		return n;
	}
}

int Herd::males(int years) const{
	int n = 0;
	if (years == -1) {
		for (int i = 0; i < _vecAnimals.size(); i++){
			if (_vecAnimals[i]->sex()==0) n++;
		}
	}
	else{
		for (int i = 0; i < _vecAnimals.size(); i++){
			if (_vecAnimals[i]->age()==years && _vecAnimals[i]->sex()==0) n++;
		}
	}
	return n;
}

int Herd::females(int years) const{
	int n = 0;
	if (years == -1) {
		for (int i = 0; i < _vecAnimals.size(); i++){
			if ( _vecAnimals[i]->sex()==1) n++;
		}
	}
	else{
		for (int i = 0; i < _vecAnimals.size(); i++){
			if (_vecAnimals[i]->age()==years && _vecAnimals[i]->sex()==1) n++;
		}
	}
	return n;
}

void Herd::obsolescence(){
	if (size()==0) return;
	for (int i = 0; i < _vecAnimals.size(); i++){
		if (!_vecAnimals[i]->ageing()){
			_vecAnimals.erase(_vecAnimals.begin()+i);
			i--;
		}
	}
}

void Herd::attack(int n){
	if (size()==0) return;
	if (n <= 0) return;
	if (n >= _vecAnimals.size())
		_vecAnimals.clear();
	else {
		for (int i = 0; i < n; i++){
			_vecAnimals.erase(_vecAnimals.begin()+rand()%(_vecAnimals.size()));
		}
	}
}

void Herd::add(Animal * new_one){
	if (_vecAnimals.size() == 0 || _vecAnimals.back()->type() == new_one->type())
		_vecAnimals.push_back(new_one);
	else cout << "Zle zwierzeta dodajesz do siebie, ziomek!\n";
}

void Herd::add(Animal * new_ones[], int n){
	for (int i = 0; i < n; i++){
		add(new_ones[i]);
	}
}

int Herd::assets(){
	int sum = 0;
	for (int i = 0; i < _vecAnimals.size(); i++){
		sum += _vecAnimals[i]->productiveness();
	}
	return sum;
}

double Herd::money(){
	if (_vecAnimals.size()==0) return 0;
	if (_vecAnimals.back()->type()!=pig){
		double sum = assets()*(_vecAnimals.back()->prod_price()) - (_vecAnimals.back()->costs())*size();
		return sum;
	}
	return 0;
}

double Herd::sell(int n){
	if (size()==0) return 0;
	if (n >= _vecAnimals.size())
		sell_all();
	else {
		double sum = 0;
		for (int i = 0; i < n; i++){
			int random = rand()%(_vecAnimals.size());
			sum += _vecAnimals[i]->sell();
			_vecAnimals.erase(_vecAnimals.begin()+random);
		}
	}
}

double Herd::sell_all(){
	if (_vecAnimals.size()==0) return 0;
	double sum = 0;
	for (int i = 0; i < _vecAnimals.size(); i++){
		sum += _vecAnimals[i]->sell();
	}
	_vecAnimals.clear();
	return sum;
}

void Herd::procreation(){
	if (size()==0) return;
	int male = males() - males(0) - males(1) - males(2);
	int female = females()  - females(0) - females(1);
	int min = (male < female ? male: female)*_vecAnimals.back()->procreate();
	if (min == 0) return;
	Animal * tab[min];
	for (int i = 0; i < min; i++){
		if (_vecAnimals.back()->type() == dog){
			Animal * pAnimal = new Dog(i);
			tab[i] = pAnimal;
		}
		else {
			Animal * pAnimal = new Animal(_vecAnimals.back()->type(), i);
			tab[i] = pAnimal;
		}
	}
	add(tab,min);
}

Animal* Herd::operator[](int n){
	return _vecAnimals[n];
}

ostream & operator<<(ostream &os, Herd & h){
	if (h.size()==0) return os;
	switch(h[h.size()-1]->type()){
		case chicken: 
			os << "Stado kur. Ko ko ko ko!\n";
			break;
		case cow: 
			os << "Stado krow. Muuuuuu!\n";
			break;
		case pig: 
			os << "Stado swin. Chrum chrum!\n";
			break;
		case sheep: 
			os << "Stado owiec. Beee beee!\n";
			break;
		case horse: 
			os << "Stado koni. Iiiihaha!\n";
			break;
		case rabbit:
			os << "Stado krolikow.\n";
			break;
		case dog: 
			os << "Stado psow. Hau hau!\n";
			break;
	}
	os << "Rozmiar stada: " << h.size() << endl
	   << "Samice: " << h.females() << endl
	   << "Samce: " << h.males() << endl
	   //<< "Pieniazki: " << h.money() << endl
	   //<< "Staruszki (gina w nastepnej rundzie): " << h.size(h[h.size()-1]->dying()-1)
	   ;
	return os;
}

									