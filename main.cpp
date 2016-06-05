#include <iostream>
#include <vector>
#include <math.h>

#include "Animals.h"
#include "Herd.h"

void randomIncidents(Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void clear();
void pause();
int start();
void menu(double&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void period(double&, int, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
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

	double money=1000;

	Herd cows;
	Herd rabbits;
	Herd sheeps;
	Herd chickens;
	Herd horses;
	Herd pigs;
	Herd dogs;

	for(int i=1; i<=semestr; i++){

		period(money, i, dogs, cows, rabbits, sheeps, chickens, horses, pigs);
		menu(money, dogs, cows, rabbits, sheeps, chickens, horses, pigs);

	}

	return 0;
	
}

int isCorrect(int range){

	int number;

	while(number > range || number <= 0){

		cin >> number;

		if (cin.fail() || number > range || number <= 0){

			cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(1024, '\n');

		}	

	}

	return number;

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
	int random = 1, a;

	if(random == marten && rabbits.size()>0)
	{
		a = (rand()%10)+3 ;
		dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		rabbits.attack(kills);

		cout << "Atak kuny! Z Twojego stadka pozostało " << kills << " królików." << endl ;
		
		if(!dogs[0]->protect())
		{
			cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " królików." << endl ;
			dogs.sell(1);
		}
	}

	if(random == bat && cows.size()>0)
	{
		a = (rand()%5)+1;
		dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		cows.attack(kills);

		cout << "Przyleciały krwiożercze nietoperze. Wyssały krew z " << kills << " Twoich krów." << endl ;
	}

	if(random == wolf && pigs.size()>0)
	{
		a = (rand()%5)+1;
		dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		pigs.attack(kills);

		cout << "W nocy przybiegły wilki, pożerając " << kills << " Twoich świń." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " świń." << endl ;
				dogs.sell(1);
			}
	}

	if(random == fox)
	{
		int n;
		n = rand()%2;

		if(n == 0 && sheeps.size()>0) //Lis je owce
		{
			a = (rand()%7)+1;
			dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			sheeps.attack(kills); // przepraszam jeszcze raz xD

			cout << "W nocy przybiegł lis chytrusek i zagryzł " << kills << " Twoich owiec." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " owiec." << endl ;
				dogs.sell(1);
			}
		}

		if(n == 1 && chickens.size()>0) // Lis je kury
		{
			a = (rand()%7)+1;
			dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			chickens.attack(kills);

			cout << "W nocy przybiegł lis chytrusek i zjadł " << kills << " Twoich kur." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " kur." << endl ;
				dogs.sell(1);
			}
		}
	}

	if(random == pilferer)
	{
		int n = (rand()%6)+1 ;
		
		if(dogs.size()>=3)
		{
			dogs.sell(3);
			cout << "Pod osłoną nocy przybył złodziej, jednak Twoje trzy dzielne psy poświęciły się dla obrony gospodarstwa. Reszta zwierząt może spać spokojnie." << endl ;
		} else
	
		if(n==1 && rabbits.size()>0)
		{
			kills = (rand()%10)+3;
			rabbits.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " królików." << endl ;
		}

		if(n==2 && cows.size()>0)
		{
			kills = (rand()%5)+1;
			cows.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " krów." << endl ;
		}

		if(n==3 && pigs.size()>0)
		{	
			kills = (rand()%5)+1;
			pigs.attack(kills);
		
			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " świń." << endl ;
		}

		if(n==4 && sheeps.size()>0)
		{
			kills = (rand()%7)+1;
			sheeps.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " owiec." << endl ;
		}

		if(n==5 && chickens.size()>0)
		{
			kills = (rand()%7)+1;
			chickens.attack(kills);

			cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << kills << " owiec." << endl ;
		}

		if(n==6 && horses.size()>0)
		{
			horses.attack(1);

			cout << "Pod osłoną nocy przybył przebiegły złodziejaszek i odjechał na Twoim koniu." << endl ;
		}
	}

}

void clear() {
 
    cout << "\x1B[2J\x1B[H";

}

void pause(){

	cout << "Wciśnij enter żeby kontynuować ..." << endl;
    cin.get(); 

}

int start(){

	clear();
	cout << "Drogi użytkowniku, wcielisz się dziś w postać rolnika." << endl;
	cout << "Przed Tobą ciężka droga. Będą lały się pot, krew i łzy, zwyciężysz tylko dzięki determinacji." << endl;
	cout << "Ile lat chcesz spędzić na farmie? (Od roku do 50 lat)" << endl;

	int years=0;

	while (years<=0 || years>50){

		cin >> years;

		if (cin.fail() || years > 50 || years<=0){

			cout << "Podałeś niepoprawną liczbę lat, spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(1024, '\n');

		}

	}

	cout << years*2;
	pause();
	return years*2;

}

void menu(double& money, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	int quit=1;

	int option=0;

	int quantity=1000;

	int number=0;

	Animal * tab[quantity];



	/*while(quit==1){

*/
	do{

	clear();

	cout << "Cóż chcesz dziś uczynić Wieśniaku?" << endl << endl;

	cout << "[1] Kupić zwierzynę." << endl << endl;

	cout << "[2] Sprzedać zwierzynę." << endl << endl;

	option=isCorrect(2);

	clear();

	switch (option){

		case 1:

		cout << "Które zwierzęta chcesz kupić?" << endl;

		cout << "[1] Psy" << endl;

		cout << "[2] Krowy" << endl;

		cout << "[3] Króliki" << endl;

		cout << "[4] Owce" << endl;

		cout << "[5] Kurczaki" << endl;

		cout << "[6] Konie" << endl;

		cout << "[7] Świnie" << endl;

		number = isCorrect(7);

		switch(number){

			case 1:

			clear();
			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			cout << "Cena psa: " << Animal::_buy_dog << endl;
			cout << "Koszt utrzymania: " << Animal::costs_dog << endl;
			cout << "Ile psów chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_dog) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_dog<=money){

				if (quantity==1){

					Animal * pAnimal = new Dog(quantity);
					dogs.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Dog(i);
						tab[i] = pAnimal;

					}

					dogs.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_dog;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}

			break;

			case 2:

			clear();
			cout << "Liczba Twoich krów: " << cows.size() << endl;
			cout << "Cena krowy: " << Animal::_buy_cow << endl;
			cout << "Koszt utrzymania: " << Animal::costs_cow << endl;
			cout << "Ile krów chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_cow) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_cow<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(cow,quantity);
					cows.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(cow,i);
						tab[i] = pAnimal; 

					}

					cows.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_cow;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}

			break;

			case 3:

			clear();
			cout << "Liczba Twoich królików: " << rabbits.size() << endl;
			cout << "Cena królika: " << Animal::_buy_rabbit << endl;
			cout << "Koszt utrzymania: " << Animal::costs_rabbit << endl;
			cout << "Ile królików chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_rabbit) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_rabbit<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(rabbit,quantity);
					rabbits.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(rabbit,i);
						tab[i] = pAnimal; 

					}

					rabbits.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_rabbit;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}

			break;

			case 4:

			clear();
			cout << "Liczba Twoich owiec: " << sheeps.size() << endl;
			cout << "Cena owiec: " << Animal::_buy_sheep << endl;
			cout << "Koszt utrzymania: " << Animal::costs_sheep << endl;
			cout << "Ile owiec chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_sheep) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_sheep<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(sheep,quantity);
					sheeps.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(sheep,i);
						tab[i] = pAnimal; 

					}

					sheeps.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_sheep;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}

			break;
			
			case 5:

			clear();
			cout << "Liczba Twoich kurczaków: " << chickens.size() << endl;
			cout << "Cena kurczaka: " << Animal::_buy_chicken << endl;
			cout << "Koszt utrzymania: " << Animal::costs_chicken << endl;
			cout << "Ile kurczaków chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_chicken) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_chicken<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(chicken,quantity);
					chickens.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(chicken,i);
						tab[i] = pAnimal; 

					}

					chickens.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_chicken;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}


			break;

			case 6:
		
			clear();
			cout << "Liczba Twoich koni: " << horses.size() << endl;
			cout << "Cena konia: " << Animal::_buy_horse << endl;
			cout << "Koszt utrzymania: " << Animal::costs_horse << endl;
			cout << "Ile koni chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_horse) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_horse<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(horse,quantity);
					horses.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(horse,i);
						tab[i] = pAnimal; 

					}

					horses.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_horse;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}


			break;

			case 7:
			
			clear();
			cout << "Liczba Twoich świń: " << pigs.size() << endl;
			cout << "Cena świni: " << Animal::_buy_pig << endl;
			cout << "Koszt utrzymania: " << Animal::costs_pig << endl;
			cout << "Ile świń chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_pig) << endl;

			quantity=isCorrect(1000);

			if(quantity*Animal::_buy_pig<=money){

				if (quantity==1){

					Animal * pAnimal = new Animal(pig,quantity);
					pigs.add(pAnimal);

				}

				else{

					for(int i=0; i<quantity; i++){

						Animal * pAnimal = new Animal(pig,i);
						tab[i] = pAnimal; 

					}

					pigs.add(tab, quantity);

				}

				money-=quantity*Animal::_buy_pig;

			}

			else{

				cout << "Nie masz wystarczająco pieniędzy." << endl;
				pause();

			}


			break;
			
		}

		break;

		case 2:

		cout << "Które zwierzęta chcesz sprzedać?" << endl;

		cout << "[1] Psy" << endl;

		cout << "[2] Krowy" << endl;

		cout << "[3] Króliki" << endl;

		cout << "[4] Owce" << endl;

		cout << "[5] Kurczaki" << endl;

		cout << "[6] Konie" << endl;

		cout << "[7] Świnie" << endl;

		number=isCorrect(7);

		switch(number){

			case 1:

			clear();
			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich psów: " << Animal.sell() << endl;
			cout << "Ile psów chcesz sprzedać?" << endl;

			quantity=isCorrect(dogs.size());

			money+=dogs.sell(quantity);

			break;

			case 2:

			clear();
			cout << "Liczba Twoich krów: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich krów: " << Animal.sell() << endl;
			cout << "Ile krów chcesz sprzedać?" << endl;

			quantity=isCorrect(cows.size());

			money+=cows.sell(quantity);

			break;

			case 3:

			clear();
			cout << "Liczba Twoich królików: " << rabbits.size() << endl;
			//cout << "Cena sprzedaży Twoich królików: " << Animal.sell() << endl;
			cout << "Ile królików chcesz sprzedać?" << endl;

			quantity=isCorrect(rabbits.size());

			money+=rabbits.sell(quantity);

			break;

			case 4:

			clear();
			cout << "Liczba Twoich owiec: " << sheeps.size() << endl;
			//cout << "Cena sprzedaży Twoich owiec: " << Animal.sell() << endl;
			cout << "Ile owiec chcesz sprzedać?" << endl;

			quantity=isCorrect(sheeps.size());

			money+=sheeps.sell(quantity);

			break;
			
			case 5:

			clear();
			cout << "Liczba Twoich kurczaków: " << chickens.size() << endl;
			//cout << "Cena sprzedaży Twoich kurczaków: " << Animal.sell() << endl;
			cout << "Ile kurczaków chcesz sprzedać?" << endl;

			quantity=isCorrect(chickens.size());

			money+=chickens.sell(quantity);

			break;
		
			case 6:

			clear();
			cout << "Liczba Twoich koni: " << horses.size() << endl;
			cout << "Ile koni chcesz sprzedać?" << endl;

			quantity=isCorrect(horses.size());

			money+=horses.sell(quantity);

			break;
			
			case 7:

			clear();
			cout << "Liczba Twoich świń: " << pigs.size() << endl;
			cout << "Ile świń chcesz sprzedać?" << endl;

			quantity=isCorrect(pigs.size());

			money+=pigs.sell(quantity);

			break;
			
		}

		break;

	}
	clear();

	cout << "Czy chcesz coś jeszcze dzisiaj zrobić?" << endl << endl;

	cout << "[1] Tak" << endl;
	cout << "[2] Nie" << endl;

	quit=isCorrect(2);

	pause();

	}while(quit==1);

}	

void period(double& money, int semestr, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	clear();

	if(semestr>1){

		double income=0;

		
		income+=dogs.money();
		dogs.procreation();

		if(dogs.size(0))
			cout << "Urodziło się: " << dogs.size(0) << " psów" << endl;

		dogs.obsolescence();


		income+=cows.money();
		cows.procreation();

		if(cows.size(0))
			cout << "Urodziło się: " << cows.size(0) << " krów" << endl;

		cows.obsolescence();


		income+=rabbits.money();
		rabbits.procreation();

		if(rabbits.size(0))
			cout << "Urodziło się: " << rabbits.size(0) << " królików" << endl;

		rabbits.obsolescence();


		income+=sheeps.money();
		sheeps.procreation();

		if(sheeps.size(0))
			cout << "Urodziło się: " << sheeps.size(0) << " owiec" << endl;

		sheeps.obsolescence();


		income+=chickens.money();
		chickens.procreation();

		if(chickens.size(0))
			cout << "Urodziło się: " << chickens.size(0) << " kurczaków" << endl;

		chickens.obsolescence();


		income+=horses.money();
		horses.procreation();

		if(horses.size(0))
			cout << "Urodziło się: " << horses.size(0) << " koni" << endl;

		horses.obsolescence();


		income+=pigs.money();
		pigs.procreation();

		if(pigs.size(0))
			cout << "Urodziło się: " << pigs.size(0) << " świń" << endl;

		pigs.obsolescence();


		money+=income;

		cout << "Przez ostatnie pół roku:" << endl;

		if(income>=0)
			cout << "Do Twojej sakwy wpadło: " << income << " miedziaków" << endl;

		else
			cout << "Utrzymanie pochłonęło: " << income << " miedziaków" << endl;

		randomIncidents(dogs, cows, rabbits, sheeps, chickens, horses, pigs);

		cout << endl << endl;
		pause();
		clear();

	}

	cout << "Drogi Wieśniaku! W Twojej sakwie jest: " << money << " miedziaków." << endl;
	cout << "Oto stan Twojej farmy na " << semestr << " półrocze." << endl << endl;

	cout << dogs << endl;

	cout << cows << endl;

	cout << rabbits << endl;

	cout << sheeps << endl;

	cout << chickens << endl;

	cout << horses << endl;

	cout << pigs << endl;


	pause();


}