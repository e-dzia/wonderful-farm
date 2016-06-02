#include <iostream>
#include <vector>

#include "Animals.h"
#include "Herd.h"

void randomIncidents(Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);

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
	int rozmiar = 10;
	Animal * tab[rozmiar]; //tablica wskaźników 
	
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Dog(i); //new Animal(dog,i) zadziała tak samo jak coś
		tab[i] = pAnimal; 
	} 
	
	Herd dogs(tab, rozmiar);
	Herd cows;
	Herd rabbits;
	Herd sheeps; //liczba mnoga od sheep to ... sheep, ale inaczej nie zadziała, przepraszam XD
	Herd chickens;
	Herd horses;
	Herd pigs;

	double money = 10000;   

	cout << cows << endl; 
	money += cows.money(); 
	cout << "Pieniazki gospodarstwa: " << money << endl << endl;   
	for (int i = 0; i < 15; i++){ 
		cout << "Rok: " << i+1 << endl;
		cows.obsolescence(); //usun stare
		cows.procreation(); //rozmnoz mlode
		randomIncidents(dogs, cows, rabbits, sheeps, chickens, horses, pigs);
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

void randomIncidents(Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs)
{
	int marten, bat, wolf, fox, pilferer;
	int kills;

	marten = rand()%4;
	bat = rand()%6;
	wolf = rand()%6;
	fox = rand()%4;
	pilferer = rand()%4;
	int random = 1;

	if(random == marten)
	{
		kills = ((rand()%10)+3) - dogs[0]->productiveness();
		rabbits.attack(kills);

		cout << "Atak kuny! Z Twojego stadka pozostało " << kills << " królików." ;
		
		if(!dogs[0]->protect())
		{
			cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " królików." ;
			// zabić psa?
		}
	}

	if(random == bat)
	{
		kills = (rand()%5)+1;
		cows.attack(kills);

		cout << "Przyleciały krwiożercze nietoperze. Wyssały krew z " << kills << " Twoich krów." << endl ;
	}

	if(random == wolf)
	{
		kills = ((rand()%5)+1) - dogs[0]->productiveness();
		pigs.attack(kills);

		cout << "W nocy przybiegły wilki, pożerając " << kills << " Twoich świń." ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " świń." ;
				// zabić psa?
			}
	}

	if(random == fox)
	{
		int n;
		n = rand()%2;

		if(n == 0) //Lis je owce
		{
			kills = ((rand()%7)+1) - dogs[0]->productiveness();
			sheeps.attack(kills); // przepraszam jeszcze raz xD

			cout << "W nocy przybiegł lis chytrusek i zagryzł " << kills << " Twoich owiec." ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " owiec." ;
				// zabić psa?
			}
		}

		if(n == 1) // Lis je kury
		{
			kills = ((rand()%7)+1) - dogs[0]->productiveness();
			chickens.attack(kills);

			cout << "W nocy przybiegł lis chytrusek i zjadł " << kills << " Twoich kur." ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " kur." ;
				// zabić psa?
			}
		}
	}

	if(random == pilferer)
	{
		int n = (rand()%6)+1 ;
	
		if(n==1)
		{
			kills = ((rand()%10)+3);
			rabbits.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " królików." ;
		}

		if(n==2)
		{
			kills = (rand()%5)+1;
			cows.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " krów." ;
		}

		if(n==3)
		{	
			kills = (rand()%5)+1;
			pigs.attack(kills);
		
			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " świń." ;
		}

		if(n==4)
		{
			kills = (rand()%7)+1;
			sheeps.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " owiec." ;
		}

		if(n==5)
		{
			kills = (rand()%7)+1;
			chickens.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " owiec." ;
		}

		if(n==6)
		{
			horses.attack(1);

			cout << "Pod osłoną nocy przybył przebiegły złodziejaszek i odjechał na Twoim koniu." ;
		}
	}

}