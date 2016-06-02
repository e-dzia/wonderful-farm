#include <iostream>
#include <vector>

#include "Animals.h"
#include "Herd.h"

/*
- uzytkownik wybiera liczbe lat symulacji
- menu do podejmowania decyzji w sprawie farmy (co chce kupic/sprzedac)
- petla do liczba_lat, w kazdym obrocie powiekszaja sie stada, mozna sprzedawac zwierzeta/produkty, kupować zwierzeta. Przy kazdym obrocie musi
wyswietlac sie info: ile jakich zwierzat i jakiej plci ma uzytkownik, ile roslin, ile ma hajsu i czy ktos atakowal jego zwierzeta albo ukradł :p
- w każdym obrocie mogą zdarzyć się zdarzenia losowe - drapieżnik/złodziej -> usuwa losowe osobniki i wyswietla info, że zabrał kilka osobnikow
- zwierzeta przechowywane sa w vectorze (lepiej niz w kolejce, bo mozna usuwac srodkowe elementy tez)
*/

using namespace std; 

int main(int argc, char** argv)
{
	int rozmiar = 13;
	Animal * tab[rozmiar]; //tablica wskaźników 
	
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Dog(i); //new Animal(dog,i) zadziała tak samo jak coś
		tab[i] = pAnimal; 
	} 
	
	Herd cows(tab, rozmiar); //chwilowo krowy są psami XD
	double money = 10000;   

	cout << cows << endl; 
	money += cows.money(); 
	cout << "Pieniazki gospodarstwa: " << money << endl << endl;   
	for (int i = 0; i < 15; i++){ 
		cout << "Rok: " << i+1 << endl;
		cows.obsolescence(); //usun stare
		cows.procreation(); //rozmnoz mlode
		cows.attack(2); //atak lisa czy czegos :p
		money += cows.sell(); //sprzedaje jedna losowa krowe
		money += cows.money(); //zwraca przychody minus koszty utrzymania
		cout << cows << endl; 
		cout << "Pieniazki gospodarstwa: " << money << endl << endl;  
		cows[0]->protect(5);
	}
	cows.sell_all();
	cout << cows << endl << endl;
	
	
	return 0;
}