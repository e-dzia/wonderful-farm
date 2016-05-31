#pragma once
#include <vector>
#include <iostream>

#include "Animals.h"

using namespace std;

class Herd{
	private:
		vector <Animal *> _vecAnimals; //wektor z jednym (!) typem zwierzat
	public:
		Herd(); //konstruktor domyslny - tylko zajmuje miejsce na wektor i tyle
		Herd(Animal * tab[], int n); //konstruktor kopiuje wszystkie elementy z wektora z maina i usuwa tamte
		//inne konstruktory tez mozna zrobic, jak beda potrzebne ofc
		
		int size(int years = -1) const;//liczba osobnikow (w zadanym wieku)
		int males(int years = -1) const;//liczba samic/samcow (w zadanym wieku)
		int females(int years = -1) const;
		
		void obsolescence();//czyli starzenie, usun stare
		void attack(int n);//usun zadana liczbe losowych (zdarzenia losowe)
		void add(Animal * new_one);//dodaj nowy zakup
		void add(Animal * new_ones[], int n); //dodaj DUŻO nowych
		
		int assets(); //zwraca laczna liczbe produkowanych rzeczy przez stado
		double money(); //zwraca liczbe pieniedzy, którą się zaorbiło na całym stadzie przez rok minus koszt utrzymania

		double sell(int n=1); //sprzedaje n zwierzat (losowych)
		double sell_all(); // sprzedaje wszystko
		
		void procreation();//rozmnazanie - dodaje nowe obiekty do wektora
		
		Animal* operator[](int n);
		friend ostream & operator<<(ostream &os, Herd & h); //wyswietlanie info o stadzie

};