#include <iostream>
#include <vector>

#include "Animals.h"
#include "Herd.h"

/*
- uzytkownik wybiera liczbe lat symulacji
- menu do podejmowania decyzji w sprawie farmy (co chce kupic/sprzedac)
- petla do 4*liczba_lat, w kazdym obrocie powiekszaja sie stada, mozna sprzedawac zwierzeta/produkty, kupować zwierzeta. Przy kazdym obrocie musi
wyswietlac sie info: ile jakich zwierzat i jakiej plci ma uzytkownik, ile roslin, ile ma hajsu i czy ktos atakowal jego zwierzeta albo ukradł :p
- w każdym obrocie mogą zdarzyć się zdarzenia losowe - drapieżnik/złodziej -> usuwa losowe osobniki i wyswietla info, że zabrał kilka osobnikow
- zwierzeta przechowywane sa w vectorze (lepiej niz w kolejce, bo mozna usuwac srodkowe elementy tez)
*/

using namespace std; 

int main(int argc, char** argv)
{
	int rozmiar = 10;
	Animal * tab[rozmiar]; //tablica wskaźników swiń
	
	for (int i = 0; i < rozmiar; i++){
		Animal * pAnimal = new Animal(cow, i); 
		tab[i] = pAnimal;
	}
	
	Herd cows(tab, rozmiar); 
	
	cout << cows << endl; 
	for (int i = 0; i < 15; i++){
		cout << "Rok: " << i+1 << endl;
		cows.obsolescence(); //usun stare
		cows.procreation(); //rozmnoz mlode
		cows.attack(2); //atak lisa czy czegos :p
		cout << cows << endl << endl;
	}
	
	//cout << pigs << endl; 
	
	
	return 0;
}