#pragma once

void randomIncidents(Herd& dogs, Herd& cows, Herd& rabbits, Herd& sheeps, Herd& chickens, Herd& horses, Herd& pigs)
{
	cout << "RANDOM INCIDENTS RUNNING ############" << endl;
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

		rabbits.attack(kills);

		cout << "Atak kuny! Z Twojego stadka pozostało " << kills << " królików." << endl ;
		
		if(dogs.size()>0 && !dogs[0]->protect())
		{
			cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " królików." << endl ;
			dogs.sell(1);
		}
	}

	if(random == bat && cows.size()>0)
	{
		kills = (rand()%5)+1;
		cows.attack(kills);

		cout << "Przyleciały krwiożercze nietoperze. Wyssały krew z " << kills << " Twoich krów." << endl ;
	}

	if(random == wolf && pigs.size()>0)
	{
		a = (rand()%5)+1;
		if (dogs.size()>0)
			dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
		else kills = a;
		pigs.attack(kills);

		cout << "W nocy przybiegły wilki, pożerając " << kills << " Twoich świń." << endl ;
	
		if(dogs.size()>0 && !dogs[0]->protect())
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
			if (dogs.size()>0) 
				dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			else kills = a;
			sheeps.attack(kills); // przepraszam jeszcze raz xD

			cout << "W nocy przybiegł lis chytrusek i zagryzł " << kills << " Twoich owiec." << endl ;
	
		if(dogs.size()>0 && !dogs[0]->protect())
			{
				cout << "Twój pies poległ w walce broniąc stada. Udało mu się obronić " << dogs[0]->productiveness() << " owiec." << endl ;
				dogs.sell(1);
			}
		}

		if(n == 1 && chickens.size()>0) // Lis je kury
		{
			a = (rand()%7)+1;
			if (dogs.size()>0) 
				dogs[0]->productiveness() > a ? kills=0 : kills = a - dogs[0]->productiveness() ;
			else kills = a;
			chickens.attack(kills);

			cout << "W nocy przybiegł lis chytrusek i zjadł " << kills << " Twoich kur." << endl ;
	
		if(dogs.size()>0 && !dogs[0]->protect())
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
	cout << "RANDOM INCIDENTS EXIT ############" << endl;

}