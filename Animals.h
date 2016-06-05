#pragma once
//nagłówki wszytskich zwierzakow

enum animals {
	chicken = 0, cow = 1, pig = 2, sheep = 3, horse = 4, rabbit = 5, dog = 6
};

class Animal{
	private:
		animals _type; //typ zwierzaka: kura, krowa, itd.
		int _procreate; //współczynnik rozmnazania: nowych osobnikow z jednej matki/rok lub sezon
		int _dying; //wiek umierania w latach
		int _productiveness; //produktywnosc konkretnego osobnika (moze byc zmienna z wiekiem lub stała), np. liczba jajek na sezon dla kur
		int _age; //wiek konkretnego zwierzecia
		bool _sex; //plec konkretnego zwierzecia 0 - male, 1 - female
		void setProductiveness(int x, int y, int i = 0); //ustawia produktywnosc na losowa wartosc z zadanego przedzialu (x,y)
		double _buy_price;
		double _sell_price; //cena sprzedazy
		double _costs; //koszt utrzymania roczny
		double _prod_price; //cena za jedną produktywność (np. jedno jajko)
		

		
	public:
		Animal(animals type, int i=0); // konstruktor - losuje plec, ustawia wiek na zero
		Animal(int proc, int die, int prod_x, int prod_y, double buy, double sell, double cost, double prodp, int i = 0); //konstruktor dla psa
		
		static double _buy_chicken, _buy_cow, _buy_pig, _buy_sheep, _buy_horse, _buy_rabbit, _buy_dog; //ceny kupna
		static double costs_chicken, costs_cow, costs_pig, costs_sheep, costs_horse, costs_rabbit, costs_dog; //ceny utrzymania

		//gettery:
		int age() {return _age;};
		bool sex() {return _sex;};
		animals type() {return _type;};
		int productiveness() {return _productiveness;};
		int procreate(){return _procreate;};
		int dying(){return _dying;};
		double prod_price(){return _prod_price;};
		double costs(){return _costs;};
		//double buy_price(animals t = chicken);
		double sell(){return _sell_price;};  
		
		virtual bool ageing(); //starzenie zwierzaka, zwieksza wiek zwierzaka o 1, zwraca true jesli jest ok i false jesli ma umrzec
		virtual bool protect(int n = 1);
		

		
};

class Dog: public Animal{
	private:
		int _attacks_protected; //zerowana z poczatkiem kazdego roku?
	public:
		Dog(int i = 0, int proc = 1, int die = 15, int prod_x = 2, int prod_y = 10, double buy = 800, double sell = 500, double cost = 400, double prodp = 0);// konstruktor domyslny - losuje plec i produktywnosc, ustawia wiek na zero

		bool protect(int n = 1); //jesli moze obronic, to zwraca true i zwieksza liczbe obronionych o 1
		bool ageing();
};
