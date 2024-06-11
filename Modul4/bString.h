#pragma once
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

enum Letters {
	VOWELS,
	CONSONANTS
};
struct WordCount {
	string word;
	int count;
};

class bString {

public:
	/* 
		Tworzenie
	*/
	bString(const char* in); // dodaje zawsze spacje na koniec ciągu 
	bString(const string* in); // dodaje zawsze spacje na koniec ciągu
	void print();
	void println();
	void reverse();
	void reverseSize();
	bool equals(string sourse, bool ignoreSize);
	void append(string in); //ważne , dodaje spacje między stringami
	void newline(); //dodaje \n do stringa zapweniając nową linie
	void searchandreplace(string search, string replace);
	vector<bString> split(); // dzieli na wyrazy
	string toString() { return memo; }
	/*
	
		FUNKCJE LICZĄCE

		ℹ️ Funkcje liczące znaki oraz znaki białe będą zwracać:
			- przy każdym dodaniu nowego stringa n+1 ponieważ dodajemy spacje między stringami (na początku)
			- przy każdym dodaniu nowej linii n+1 ponieważ dodajemy znak \n
	*/
	int count(); // zawsze znaków będzie n+1 bo dodajemy spacje za każdym razem kiedy inicjujemy 
	int countWhiteChars();
	int countbylettertype(Letters type = VOWELS);
	int countLines(); // zlicza ilość linii w stringu (czyli ilość znaków \n)
	vector<WordCount> countWords();
	int countWords(string word);
	
	



	
	bool palindrome();
	
	
private:
	string memo;
	vector<char> vowel = {'a','e','i','o','u','y'};
	bool isVowel(char c) {
		for(char v : vowel) if (v == c) return true;
		return false;
	};
	string clearWhiteChars();
	bool findOne(vector<WordCount> tab, string word);
	
};