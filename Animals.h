#pragma once
//nagłówki wszytskich zwierzakow

enum animals {
	chicken = 0, cow = 1, pig = 2, sheep = 3, horse = 4, rabbit = 5
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
		
	public:
		Animal(animals type, int i=0); // konstruktor - losuje plec, ustawia wiek na zero
		Animal(int proc, int die, int prod_x, int prod_y, int i = 0); //konstruktor dla psa
		
		//gettery:
		int age() {return _age;};
		bool sex() {return _sex;};
		animals type() {return _type;};
		int productiveness() {return _productiveness;};
		int procreate(){return _procreate;};
		int dying(){return _dying;};
		
		bool ageing(); //starzenie zwierzaka, zwieksza wiek zwierzaka o 1, zwraca true jesli jest ok i false jesli ma umrzec
		//w aging mozna potem dodac zmiane produktywnosci wraz ze starzeniem
		

		
};

class Dog: public Animal{
	private:
		int _attacks_protected; //zerowana z poczatkiem kazdego roku
	public:
		Dog(int proc = 1, int die = 15, int prod_x = 2, int prod_y = 10);// konstruktor domyslny - losuje plec i produktywnosc, ustawia wiek na zero
};
