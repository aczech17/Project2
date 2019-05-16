#include "text.h"
#include <iostream>
using namespace std;
int main()
{
	std::string ss("Imie: *imie*\nNazwisko: *nazwisko*\nNumer telefonu: *numer telefonu*\n");
	stringPairs rpl{ {"numer telefonu","602 224 233"}, {"imie","Jan Maria"}, {"nazwisko","Nowak-Kowalski"} };
	Text txt(rpl, ss, '*');
	txt.replaceAllWords();
	
	std::cout << txt.text();
	cin.ignore(2);
}