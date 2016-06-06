#pragma once

int min(int a, int b)
{
	return a<b?a:b;
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
		if (dogs.size()>0)
			dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		else kills = a;

		if (kills > 0)
			cout << "Atak kuny! Zagryzła " << min(kills,rabbits.size()) << " królików." << endl ;

		rabbits.attack(kills);
		
		if(dogs.size()>0 && !dogs[0]->protect())
		{
			cout << "Twój pies poległ w walce, broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " królików." << endl ;
			dogs.sell(1);
		}
	}

	if(random == bat && cows.size()>0)
	{
		kills = (rand()%5)+1;
		
		if (kills > 0)
			cout << "Przyleciały krwiożercze nietoperze. Wyssały krew z " << min(kills,cows.size()) << " Twoich krów." << endl ;

		cows.attack(kills);
	}

	if(random == wolf && pigs.size()>0)
	{
		a = (rand()%5)+1;
		if (dogs.size()>0)
			dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		else kills = a;
		

		if (kills > 0)
			cout << "W nocy przybiegły wilki, pożerając " << min(kills,pigs.size()) << " Twoich świń." << endl ;
		pigs.attack(kills);
	
		if(dogs.size()>0 && !dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce, broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " świń." << endl ;
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
			if (dogs.size()>0) 
				dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			else kills = a;
			

			if (kills > 0)
				cout << "W nocy przybiegł lis chytrusek i zagryzł " << min(kills,sheeps.size()) << " Twoich owiec." << endl ;
			sheeps.attack(kills); // przepraszam jeszcze raz xD
	
		if(dogs.size()>0 && !dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce, broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " owiec." << endl ;
				dogs.sell(1);
			}
		}

		if(n == 1 && chickens.size()>0) // Lis je kury
		{
			a = (rand()%7)+1;
			if (dogs.size()>0) 
				dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			else kills = a;
			

			if (kills > 0)
				cout << "W nocy przybiegł lis chytrusek i zjadł " << min(kills,chickens.size()) << " Twoich kur." << endl ;
			chickens.attack(kills);
	
		if(dogs.size()>0 && !dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce, broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " kur." << endl ;
				dogs.sell(1);
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
			

			if (kills > 0)
				cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << min(kills,rabbits.size()) << " królików." << endl ;
			rabbits.attack(kills);
		}

		if(n==2 && cows.size()>0)
		{
			kills = (rand()%5)+1;
			

			if (kills > 0)
				cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << min(kills,cows.size()) << " krów." << endl ;
			cows.attack(kills);
		}

		if(n==3 && pigs.size()>0)
		{	
			kills = (rand()%5)+1;
		
			if (kills > 0)
				cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << min(kills,pigs.size()) << " świń." << endl ;
			pigs.attack(kills);
		}

		if(n==4 && sheeps.size()>0)
		{
			kills = (rand()%7)+1;
			

			if (kills > 0)
				cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << min(kills,sheeps.size()) << " owiec." << endl ;
			sheeps.attack(kills);
		}

		if(n==5 && chickens.size()>0)
		{
			kills = (rand()%7)+1;
			

			if (kills > 0)
				cout << "Pod osłoną nocy gospodarstwo okradł wioskowy złodziejaszek, zabierając " << min(kills,chickens.size()) << " kur." << endl ;
			chickens.attack(kills);
		}

		if(n==6 && horses.size()>0)
		{
			horses.attack(1);

			cout << "Pod osłoną nocy przybył przebiegły złodziejaszek i odjechał na Twoim koniu." << endl ;
		}
	}

}


int isCorrect(int range){

	int number = -1;

	while(number > range || number < 0){

		cin >> number;

		if (cin.fail() || number > range || number <= 0){

			cout << "Podałeś niepoprawną liczbę, spróbuj ponownie." << endl;
			cin.clear();
			cin.ignore(1024, '\n');

		}	

	}

	return number;

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

void menu(double& money, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs, int& newCows, int& newRabbits, int& newPigs, int& newHorses, int& newSheeps, int& newDogs, int& newChickens){

	int quit=1;

	int option=0;

	int quantity=1000;

	int number=0;

	Animal * tab[quantity];


	while(quit==1 && money>=0){

	clear();

	cout << "Cóż chcesz dziś uczynić, Wieśniaku?" << endl << endl;

	cout << "[1] Kupić zwierzynę." << endl << endl;

	cout << "[2] Sprzedać zwierzynę." << endl << endl;

	cout << "[3] Odpoczywać na drewnianej werandzie." << endl << endl;

	option=isCorrect(3);

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

		cout << "[0] Zrezygnuj" << endl;


		number = isCorrect(7);

		if (number==0)
			break;

		switch(number){

			case 1:

			clear();
			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			cout << "Cena psa: " << Animal::_buy_dog << endl;
			cout << "Koszt utrzymania: " << Animal::costs_dog << endl;
			cout << "Ile psów chcesz kupić? Stać Cię na: " << floor(money/Animal::_buy_dog) << endl;

			quantity=isCorrect(1000);

			if (quantity==0)
				break;

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

				newDogs=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newCows=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newRabbits=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newSheeps=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newChickens=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newHorses=quantity;

			}

			else{
				cin.get();
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

			if (quantity==0)
				break;

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

				newPigs=quantity;

			}

			else{
				cin.get();
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

		cout << "[0] Zrezygnuj" << endl;

		number=isCorrect(7);

		if (number==0)
				break;

		switch(number){

			case 1:

			clear();
			cin.clear();
			cout << "Liczba Twoich psów: " << dogs.size() << endl;
			if (dogs.size()>0) cout << "Cena sprzedaży najstarszego z Twoich psów (młodsze są tańsze): " << dogs[0]->sell() << endl;
			cout << "Ile psów chcesz sprzedać?" << endl;
			
			quantity=isCorrect(dogs.size());

			if (quantity==0)
				break;

			money+=dogs.sell(quantity);

			break;

			case 2:

			clear();
			cout << "Liczba Twoich krów: " << cows.size() << endl;
			if (cows.size()>0) cout << "Cena sprzedaży najstarszej z Twoich krów (młodsze są tańsze): " << cows[0]->sell()  << endl;
			cout << "Ile krów chcesz sprzedać?" << endl;

			quantity=isCorrect(cows.size());

			if (quantity==0)
				break;

			money+=cows.sell(quantity);
			pause();

			break;

			case 3:

			clear();
			cout << "Liczba Twoich królików: " << rabbits.size() << endl;
			if (rabbits.size()>0) cout << "Cena sprzedaży najstarszego z Twoich królików (młodsze są tańsze): " << rabbits[0]->sell()  << endl;
			cout << "Ile królików chcesz sprzedać?" << endl;

			quantity=isCorrect(rabbits.size());

			if (quantity==0)
				break;

			money+=rabbits.sell(quantity);
			pause();

			break;

			case 4:

			clear();
			cout << "Liczba Twoich owiec: " << sheeps.size() << endl;
			if (sheeps.size()>0) cout << "Cena sprzedaży najstarszej z Twoich owiec (młodsze są tańsze): " << sheeps[0]->sell()  << endl;
			cout << "Ile owiec chcesz sprzedać?" << endl;

			quantity=isCorrect(sheeps.size());

			if (quantity==0)
				break;

			money+=sheeps.sell(quantity);
			pause();

			break;
			
			case 5:

			clear();
			cout << "Liczba Twoich kurczaków: " << chickens.size() << endl;
			if (chickens.size()>0)  cout << "Cena sprzedaży najstarszego z Twoich kurczaków (młodsze są tańsze): " << chickens[0]->sell() << endl;
			cout << "Ile kurczaków chcesz sprzedać?" << endl;

			quantity=isCorrect(chickens.size());

			if (quantity==0)
				break;

			money+=chickens.sell(quantity);
			pause();

			break;
		
			case 6:

			clear();
			cout << "Liczba Twoich koni: " << horses.size() << endl;
			if (horses.size()>0) cout << "Cena sprzedaży najstarszego z Twoich koni (młodsze są tańsze): " << horses[0]->sell() << endl;
			cout << "Ile koni chcesz sprzedać?" << endl;

			quantity=isCorrect(horses.size());

			if (quantity==0)
				break;

			money+=horses.sell(quantity);
			pause();

			break;
			
			case 7:

			clear();
			cout << "Liczba Twoich świń: " << pigs.size() << endl;
			if (pigs.size()>0) cout << "Cena sprzedaży najstarszej z Twoich świń (cena zależy od wagi świni): " << horses[0]->sell() << endl;
			cout << "Ile świń chcesz sprzedać?" << endl;

			quantity=isCorrect(pigs.size());

			if (quantity==0)
				break;

			money+=pigs.sell(quantity);

			pause();

			break;
			
		}

		break;

		case 3:

			int m; 
			m = rand()%30;
			if(m==1)
			{
				cout << "Siedząc na werandzie zauważyłeś, że po polu biega bezpańska krowa. Postanowiłeś więc ją przygarnąć. Po dwóch godzinach biegania, wykrzykiwania i odgrażania się, udało Ci się złapać niesforne zwierzę." << endl ;

				Animal * pAnimal = new Animal(cow,1);

				cows.add(pAnimal);

				cout << "Twoje stado krów powiększa się o 1." << endl << endl ;
				cin.clear();
				cin.get();
					
			}
	
			else if(m==2)
			{
				cout << "Przeciągając się leniwie na świeżym powietrzu słyszysz dziwny szelest w niepozamiatanych na podwórku liściach (przy okazji mógłbyś się zająć trochę sprzątaniem). Po chwili Twoim oczom ukazuje się mały jeżyk Tuptuś, który spokojnie spogląda na Ciebie i idzie tuptać dalej." << endl ;
				cin.clear();
				cin.get();
			}

			else if(m==3)
			{
				cout << "Wyjście na dwór późnym wieczorem nie było dobrym pomysłem. Z krzaków wylatuje rój wygłodniałych, krwiożerczych komarów, które nie oszczędzają Ciebie i Twoich zwierząt. Uciekasz szybko do domu i zamawiasz przez internet specyfiki do walki z tymi ohydnymi owadzimi potworkami." << endl ;
				cin.clear();
				cin.get();
			}

			else if(m==4)
			{
				cout << "Przy okazji sprawdzasz skrzynkę pocztową. Znajdujesz list, w którym zostajesz poinformowany o śmierci dalekiego wujka z Ameryki. Nie kojarzyłeś nawet jego imienia, ale okazuje się, że dostajesz w spadku okrągłą sumkę." << endl ;

				money+=1000; 
		 
				cout << "Do Twojego majątku wpływa 1000 miedziaków." << endl ;
				cin.clear();
				cin.get();
			}

			else if(m==5)
			{
				cout << "W to leniwe popołudnie zasypiasz na werandzie... Jednak coś nie daje Ci spokoju, ocierając się ciągle o Twoją nogę. Patrzysz w dół i spostrzegasz wesołego kundelka. Jego oczy mówią: 'Przygarnij mnie', nie masz więc serca zostawić go na pastwę losu." << endl ;


				Animal * pAnimal = new Dog(dog,1);

				dogs.add(pAnimal);

				cout << "Stado Twoich psów powiększa się o 1." << endl ;
				cin.clear();
				cin.get();
			}

			else if(m==6 && pigs.size()>0)
			{
				cout << "Tym razem słodką drzemkę na werandzie przerywa Ci przeraźliwe chrumkanie. Zanim otworzysz oczy i zdążysz zareagować, jedna z Twoich świń z nieukrywaną satysfakcją tratuje ogrodzenie i ucieka." << endl ;

				pigs.attack(1);

				cout << "Stado Twoich świń zmniejsza się o 1." << endl ;
				cin.clear();
				cin.get();
			}

			else
			{
				cout << "Nic nadzwyczajnego nie stało się w tym dniu. Spędziłeś kolejne leniwe popołudnie smacznie drzemiąc." << endl;
				cin.clear();
				cin.get();
			}

			pause();
			
		break;

	}
	clear();

	cout << "Czy chcesz coś jeszcze dzisiaj zrobić?" << endl << endl;

	cout << "[1] Tak" << endl;
	cout << "[2] Nie" << endl << endl;

	quit=isCorrect(2);

	if (quantity==0)
		break;

	pause();

	}

}	

void period(double& money, int semestr, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs, int& newCows, int& newRabbits, int& newPigs, int& newHorses, int& newSheeps, int& newDogs, int& newChickens){

	clear();

	if(semestr>1){

		double income=0;

		
		income+=dogs.money();
		dogs.procreation();

		if(dogs.size(0))
			cout << "Urodziło się: " << dogs.size(0)-newDogs << " psów" << endl;

		dogs.obsolescence();


		income+=cows.money();
		cows.procreation();

		if(cows.size(0))
			cout << "Urodziło się: " << cows.size(0)-newCows << " krów" << endl;

		cows.obsolescence();


		income+=rabbits.money();
		rabbits.procreation();

		if(rabbits.size(0))
			cout << "Urodziło się: " << rabbits.size(0)-newRabbits << " królików" << endl;

		rabbits.obsolescence();


		income+=sheeps.money();
		sheeps.procreation();

		if(sheeps.size(0))
			cout << "Urodziło się: " << sheeps.size(0)-newSheeps << " owiec" << endl;

		sheeps.obsolescence();


		income+=chickens.money();
		chickens.procreation();

		if(chickens.size(0))
			cout << "Urodziło się: " << chickens.size(0)-newChickens << " kurczaków" << endl;

		chickens.obsolescence();


		income+=horses.money();
		horses.procreation();

		if(horses.size(0))
			cout << "Urodziło się: " << horses.size(0)-newHorses << " koni" << endl;

		horses.obsolescence();


		income+=pigs.money();
		pigs.procreation();

		if(pigs.size(0))
			cout << "Urodziło się: " << pigs.size(0)-newPigs << " świń" << endl;

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

void summary(double& money, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	clear();

	cout << "Gratulacje, udało Ci się ukończyć rozgrywkę! W nagrodę otrzymujesz tytuł Sołtysa!" << endl;

	cout << "Po ostatnim połroczu Twoja farma wyglądała następująco:" << endl << endl;

	cout << dogs << endl;

	cout << cows << endl;

	cout << rabbits << endl;

	cout << sheeps << endl;

	cout << chickens << endl;

	cout << horses << endl;

	cout << pigs << endl;

}

void bankruptcy(double& money, Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs){

	clear();

	cout << "Co się martwisz, co się smucisz, ze wsi jesteś, na wieś wrócisz." << endl << endl;

	cout << "Niestety zadanie okazało się dla Ciebie zbyt trudne, spróbuj jeszcze raz." << endl << endl;

	cout << "Pod koniec rozgrywki na Twojej farmie głodowały:" << endl << endl;

	cout << dogs << endl;

	cout << cows << endl;

	cout << rabbits << endl;

	cout << sheeps << endl;

	cout << chickens << endl;

	cout << horses << endl;

	cout << pigs << endl;


}