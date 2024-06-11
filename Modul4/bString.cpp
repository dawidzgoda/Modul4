#include "bString.h"



bool bString::findOne(vector<WordCount> tab, string word ) {

	for(WordCount wc : tab) {
		if (wc.word == word) return true;
	}
	return false;

}

bString::bString(const char* in) {
	memo = in ;
}
bString::bString(const string* in) {
	memo = *in;
}
void bString::print() {
	cout << memo ;
}
void bString::println() {
	cout << memo << endl;
}
void bString::reverse() {
	string temp = memo;
	for (int i = 0; i < memo.length(); i++) {
		memo[i] = temp[memo.length() - i - 1];
	}
}
void bString::reverseSize() {
	string temp = memo;
	int diff = 'a' - 'A';

	for (int i = 0; i < memo.length(); i++) {
		if(temp[i] >= 'a' && temp[i] <= 'z') {
			memo[i] = temp[i] - diff;
		}
		if(temp[i] >= 'A' && temp[i] <= 'Z') {
			memo[i] = temp[i] + diff ;
		}
	}
}
bool bString::equals(string sourse, bool ignoreSize = false)
{
	
	string temp = memo;
	if (ignoreSize) {
		for (int i = 0; i < memo.length(); i++) {
			if (temp[i] >= 'A' && temp[i] <= 'Z') {
				temp[i] += 32;
			}
		}
	}
	return sourse == temp;
}
void bString::append(string in) {
	if (memo.back() == '\n')
	{
		memo += in;
		return;
	}
	memo += in + " ";
}
void bString::newline() {
	memo += "\n";
}
void bString::searchandreplace(string search, string replace) {
	size_t pos = memo.find(search);								//szukanie pierwszego wyst¹pienia
	while (pos != string::npos) {								//sprawdzanie czy jest jeszcze jakieœ takie s³owo
		memo.replace(pos, search.length(), replace);			//zamiana search <- replace
		pos = memo.find(search);								//szukanie kolejnego
	}
}
vector<bString> bString::split() {
	vector<bString> words;
	string temp;
	stringstream ss(memo);
	while (ss >> temp) {
		words.push_back(bString(temp.c_str()));
	}
	return words;
}
int bString::count() {
	int a = 0;
	for(char c : memo) a++;
	return a;
}
int bString::countWhiteChars() {
	int a = 0;
	for (char c : memo) if (isspace(c)) a++;
	return a;
}
int bString::countLines() {
	int a = 0;
	for (char c : memo) if (c == '\n') a++;
	return a;
}
int bString::countbylettertype(Letters type) {
	int a = 0;
	for (char c : memo) {
		if (type == VOWELS) {
			if (isVowel(c)) a++;
		}
		else {
			if (!isVowel(c)) a++;
		}
	}
	return a;
}
vector<WordCount> bString::countWords() {
	vector<bString> temp = this->split();
	vector<WordCount> words;
	for (bString t : temp) {
		if(findOne(words,t.toString())) {
			for (WordCount &wc : words) {
				if (wc.word == t.toString()) wc.count++;
			}
		}
		else {
			WordCount wc;
			wc.word = t.toString();
			wc.count = 1;
			words.push_back(wc);
		}
	}
	return words;
}
int bString::countWords(string world) {
	int a = 0;
	vector<bString> temp = this->split();
	for(bString t : temp) {
		if (t.equals(world)) a++;
	}
	return a;
}
bool bString::palindrome() {
	bString* b_temp = this;
	b_temp->reverse();
	b_temp->equals(memo);
	return true;
}
string bString::clearWhiteChars() {
	string clean = "";
	for (char c : memo) if (!isspace(c)) clean = clean + c ;
	return clean;
}