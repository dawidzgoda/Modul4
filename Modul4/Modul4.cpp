// Modul4.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "main.h"


int main()
{
    bString naw = "Hello World";

    naw.println();
    cout << "Znaki Białe: " << naw.countWhiteChars() << endl; // licz
    cout << "Znaki: " << naw.count() << endl;
    cout << "Samogłoski: " << naw.countbylettertype() << endl;
    cout << "Lini: " << naw.countLines() << endl;
    naw.reverse();
    cout << "Wyrazy: " << naw.toString() << endl;
    bString ciag = "kajak";
    string palindrome = ciag.palindrome() ? "tak" : "nie";
    cout << "Palindrom: " << palindrome << endl;
    //naw.println();
    //naw.append("Hello");
   // naw.searchandreplace("Hello", "World");
    //naw.println();
}

