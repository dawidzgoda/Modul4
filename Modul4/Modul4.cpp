// Modul4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "main.h"


int main()
{
    bString header = "Dawid Zgoda II CZI - Modul 4";
    bString str = "Hello World";
    str.append("czyli Witaj Świecie");
    header.println();
    str.println();

    bString str_size = str;
    //Zadanie 1
    cout << "Zadanie 1" << endl;
    str_size.reverseSize();
    str_size.println();
    //ZADANIE 2
    cout << "Zadanie 2" << endl;
    bString ciag = "Kajak";
    string palindrome = ciag.palindrome() ? "tak" : "nie";
    cout << "Palindrom (" << ciag.toString() << "): " << palindrome << endl;

    cout << "Zadanie 3" << endl;
    cout << "Samogłoski: " << str.countbylettertype() << endl;

    cout << "Zadanie 4" << endl;
    str.searchandreplace("Hello", "Witaj");
    str.println();

    str = "Zadanie 6";
    str.println();
    cout << "Znaki Białe: " << str.countWhiteChars() << endl; // licz
    cout << "Znaki: " << str.count() << endl;
    cout << "Samogłoski: " << str.countbylettertype() << endl;
    str.reverse();
    cout << "Odwrócony: " << str.toString() << endl;

   

}

