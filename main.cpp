#include <iostream>
#include <vector>

#include "Animals.h"
#include "Herd.h"

void randomIncidents(Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void clear();
void pause();
int start();
void menu(Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);
void period(int, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&, Herd&);

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

	//start();
	//int semestr=4;
	int semestr=start();

	int rozmiar = 0;

	//Animal * tab[rozmiar]; //tablica wskaźników 
	
	/*
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Dog(i);
		tab[i] = pAnimal; 
	} 
	Herd dogs(tab, rozmiar);
	rozmiar = 5;
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Animal(cow,i);
		tab[i] = pAnimal; 
	}
	*/
	Herd cows;
	Herd rabbits;
	Herd sheeps; //liczba mnoga od sheep to ... sheep, ale inaczej nie zadziała, przepraszam XD
	Herd chickens;
	Herd horses;
	Herd pigs;
	Herd dogs;

	for(int i=1; i<=semestr; i++){

		period(i, dogs, cows, rabbits, sheeps, chickens, horses, pigs);
		menu(dogs, cows, rabbits, sheeps, chickens, horses, pigs);

	/*int rozmiar = 0;
	Animal * tab[rozmiar]; //tablica wskaźników 
	
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Dog(i);
		tab[i] = pAnimal; 
	} 
	Herd dogs(tab, rozmiar);
	rozmiar = 5;
	for (int i = 0; i < rozmiar; i++){ 
		Animal * pAnimal = new Animal(cow,i);
		tab[i] = pAnimal; 
	}
	Herd cows (tab,rozmiar);
	Herd rabbits;
	Herd sheeps; //liczba mnoga od sheep to ... sheep, ale inaczej nie zadziała, przepraszam XD
	
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
		//money += cows.sell(); //sprzedaje jedna losowa krowe
		money += cows.money(); //zwraca przychody minus koszty utrzymania
		cout << cows << endl; 
		cout << "Pieniazki gospodarstwa: " << money << endl << endl;  
	}
	cows.sell_all();
	cout << cows << endl << endl;
	*/
	
	}

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
	int random = 1, a;

	if(random == marten && rabbits.size()>0)
	{
		a = (rand()%10)+3 ;
		dogs[0]->productiveness(); > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		rabbits.attack(kills);

		cout << "Atak kuny! Z Twojego stadka pozostało " << kills << " królików." << endl ;
		
		if(!dogs[0]->protect())
		{
			cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " królików." << endl ;
			dogs.attack(1);
		}
	}

	if(random == bat && cows.size()>0)
	{
		a = (rand()%5)+1;
		dogs[0]->productiveness(); > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		cows.attack(kills);

		cout << "Przyleciały krwiożercze nietoperze. Wyssały krew z " << kills << " Twoich krów." << endl ;
	}

	if(random == wolf && pigs.size()>0)
	{
		a = (rand()%5)+1;
		dogs[0]->productiveness(); > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		pigs.attack(kills);

		cout << "W nocy przybiegły wilki, pożerając " << kills << " Twoich świń." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " świń." << endl ;
				dogs.attack(1);
			}
	}

	if(random == fox)
	{
		int n;
		n = rand()%2;

		if(n == 0 && sheeps.size()>0) //Lis je owce
		{
			a = (rand()%7)+1;
			dogs[0]->productiveness(); > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			sheeps.attack(kills); // przepraszam jeszcze raz xD

			cout << "W nocy przybiegł lis chytrusek i zagryzł " << kills << " Twoich owiec." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " owiec." << endl ;
				dogs.attack(1);
			}
		}

		if(n == 1 && chickens.size()>0) // Lis je kury
		{
			a = rand()%7)+1;
			dogs[0]->productiveness(); > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			chickens.attack(kills);

			cout << "W nocy przybiegł lis chytrusek i zjadł " << kills << " Twoich kur." << endl ;
	
		if(!dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " kur." << endl ;
				dogs.attack(1);
			}
		}
	}

	if(random == pilferer)
	{
		int n = (rand()%6)+1 ;
		
		if(dogs.size()>=3)
		{
			dogs.attack(3);
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

void menu(Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	//bool quit=1;

	int option;

	int quantity=1;

	int number;

	Animal * tab[quantity];

	/*while(quit==1){

*/

	clear();

	cout << "Cóż chcesz dziś uczynić Wieśniaku?" << endl << endl;

	cout << "[1] Kupić zwierzynę." << endl << endl;

	cout << "[2] Sprzedać zwierzynę." << endl << endl;

	cout << "[3] Sprzedać produkty." << endl << endl;

	while(option > 3 || option <= 0){

		cin >> option;

		if (cin.fail() || option > 3 || option <= 0){

			cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(1024, '\n');

		}	

	}

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

		while(number > 7 || number <= 0){

		cin >> number;

			if (cin.fail() || number > 7 || number <= 0){

				cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
				cin.clear();
				cin.ignore(1024, '\n');

			}	

		}

		switch(number){

			case 1:

			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			cout << "Cena psa: 800" << endl;
			cout << "Ile psów chcesz kupić?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}	

			}

			if (quantity=1){

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

			break;

			case 2:

			cout << "Liczba Twoich krów: " << dogs.size() << endl;
			cout << "Ile krów chcesz kupić?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 3:

			cout << "Liczba Twoich królików: " << dogs.size() << endl;
			cout << "Ile królików chcesz kupić?" << endl;

			while(quantity > 200 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 200 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 4:

			cout << "Liczba Twoich owiec: " << dogs.size() << endl;
			cout << "Ile owiec chcesz kupić?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
			
			case 5:

			cout << "Liczba Twoich kurczaków: " << dogs.size() << endl;
			cout << "Ile kurczaków chcesz kupić?" << endl;

			while(quantity > 200 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 200 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
		
			case 6:

			cout << "Liczba Twoich koni: " << dogs.size() << endl;
			cout << "Ile koni chcesz kupić?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
			
			case 7:

			cout << "Liczba Twoich świń: " << dogs.size() << endl;
			cout << "Ile świń chcesz kupić?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

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

		while(number > 7 || number <= 0){

		cin >> number;

			if (cin.fail() || number > 7 || number <= 0){

				cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
				cin.clear();
				cin.ignore(1024, '\n');

			}	

		}

		switch(number){

			case 1:

			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich psów: " << Animal.sell() << endl;
			cout << "Ile psów chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}	

			}

			if (quantity=1){

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

			break;

			case 2:

			cout << "Liczba Twoich krów: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich krów: " << Animal.sell() << endl;
			cout << "Ile krów chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 3:

			cout << "Liczba Twoich królików: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich królików: " << Animal.sell() << endl;
			cout << "Ile królików chcesz sprzedać?" << endl;

			while(quantity > 200 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 200 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 4:

			cout << "Liczba Twoich owiec: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich owiec: " << Animal.sell() << endl;
			cout << "Ile owiec chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
			
			case 5:

			cout << "Liczba Twoich kurczaków: " << dogs.size() << endl;
			//cout << "Cena sprzedaży Twoich kurczaków: " << Animal.sell() << endl;
			cout << "Ile kurczaków chcesz sprzedać?" << endl;

			while(quantity > 200 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 200 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
		
			case 6:

			cout << "Liczba Twoich koni: " << dogs.size() << endl;
			cout << "Ile koni chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
			
			case 7:

			cout << "Liczba Twoich świń: " << dogs.size() << endl;
			cout << "Ile świń chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;
			
		}

		break;

		case 3:

		cout << "Które produkty chcesz sprzedać?" << endl;

		cout << "[1] Jajka" << endl;

		cout << "[2] Mleko" << endl;

		cout << "[3] Mięso" << endl;

		cout << "[4] Wełnę" << endl;

		while(number > 4 || number <= 0){

		cin >> number;

			if (cin.fail() || number > 4 || number <= 0){

				cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
				cin.clear();
				cin.ignore(1024, '\n');

			}	

		}

		switch(number){

			case 1:

			cout << "Liczba posiadanych jajek: " << chickens.assets() << endl;
			//cout << "Cena sprzedaży jajek: " << chicken.prod_price() << endl;
			cout << "Ile jajek chcesz sprzedać?" << endl;

			while(quantity > 1000 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 1000 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}	

			}

			if (quantity=1){

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

			break;

			case 2:

			cout << "Liczba posiadanego mleka: " << dogs.size() << endl;
			//cout << "Cena sprzedaży mleka: " << cow.sell() << endl;
			cout << "Ile mleka chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 3:

			cout << "Liczba posiadanego mięsa: " << dogs.size() << endl;
			//cout << "Cena sprzedaży mięsa: " << rabbit.sell() << endl;
			cout << "Ile mięsa chcesz sprzedać?" << endl;

			while(quantity > 200 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 200 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;

			case 4:

			cout << "Liczba posiadanej wełny: " << dogs.size() << endl;
			//cout << "Cena sprzedaży wełny: " << sheep.sell() << endl;
			cout << "Ile wełny chcesz sprzedać?" << endl;

			while(quantity > 50 || quantity <= 0){

				cin >> quantity;

				if (cin.fail() || quantity > 50 || quantity <= 0){

					cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
					cin.clear();
					cin.ignore(1024, '\n');

				}

			}

			break;	
					
		}

		break;

	}

	pause();
	clear();
/*
	cout << "Czy chcesz coś jeszcze dzisiaj zrobić?" << endl << endl;

	cout << "[1] TAK" << endl;
	cout << "[0] NIE" << endl;

	cin >> quit;

		if (cin.fail() || option > 1 || option < 0){

			cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(1024, '\n');

		}
*/
	pause();
}	

void period(int semestr, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	clear();

	if(semestr>1){

		dogs.procreation();
		dogs.obsolescence();

		cows.procreation();
		cows.obsolescence();

		rabbits.procreation();
		rabbits.obsolescence();

		sheeps.procreation();
		sheeps.obsolescence();

		chickens.procreation();
		chickens.obsolescence();

		horses.procreation();
		horses.obsolescence();

		pigs.procreation();
		pigs.obsolescence();

		cout << "Przes ostatnie pół roku:" << endl;
		randomIncidents(dogs, cows, rabbits, sheeps, chickens, horses, pigs);

		pause();

	}

	cout << "Drogi Wieśniaku! Oto stan Twojej farmy na " << semestr << " półrocze" << endl << endl;

	cout << dogs << endl;

	cout << cows << endl;

	cout << rabbits << endl;

	cout << sheeps << endl;

	cout << chickens << endl;

	cout << horses << endl;

	cout << pigs << endl;


	pause();


}
