#include<iostream>
#include<map>

using namespace std;

map<char, int> roman_map = { 
				{'I',1},
				{'V',5},
				{'X',10},
				{'L',50},
				{'C',100},
				{'D',500},
				{'M',1000}};


void
roman_converter(string roman_numeral) {
	int length = roman_numeral.length();
	cout << "The length is " << length << endl ;
	long numeral = roman_map[roman_numeral[length-1]];
	
	for (int i = length-2 ; i >=0 ; i--) {
			if (roman_map[roman_numeral[i]] < roman_map[roman_numeral[i+1]]) {
				if (roman_map[roman_numeral[i-1]] == 5) {
					cerr << "Invalid roman numeral " << endl;
					exit(1);
				} else {
					numeral -= roman_map[roman_numeral[i]];
				}

			} else {
				numeral += roman_map[roman_numeral[i]];
			}
	}

	cout << "Roman numeral : " << roman_numeral << " is actually : " << numeral << endl; 
}


int 
main(int argc, char* argv[]) {
	string roman_n;
	cout << "Enter a roman numeral : " << endl;
	getline(cin, roman_n);

	cout << " -- Converting to numeric representation -- " << endl;
	if (roman_n != "") {
		roman_converter(roman_n);
	} else {
		cerr << "Entered a null roman numeral" << endl;
		exit(1);
	}
	return EXIT_SUCCESS;
}
