#include<iostream>

using namespace std;

// Use KMP matching algorithm

int
naive_algo(string haystack, string needle) {

	int size_h = haystack.size();
	int size_n = needle.size();

	for (int j =0 ; j < size_h - size_n ; j++) {
		for (int i = 0; i < size_n ; i++) {
			if (needle[i] == haystack[i+j]) {
				if (i >= size_n) {
					return j;
				}
			
			}
		}
	}

}


int
kmp_match(string haystack, string needle) {

	bool is_match = false;
	int size_h = haystack.size();
	int size_n = needle.size();

	int i = 0;
	int j = 0;
	int k = 0;
	while ( (i < size_n) && ( j < size_h)) {
		if (needle[i] == haystack[j]) {
			i += 1;
			j += 1;
		} else {
			j += 1;
		}

		if (i == 1) {
			k = j;
		}

	}

	//cout << "Needle : " << i << endl;
	//cout << "Haystack : " << j << endl;

	if (i == size_n) {
		is_match = true;
		return k-1;
	} else {
		return -1;	
	}

}



int
main(int argc, char* argv[]) {

	string hay = "testing";
	string needle = "ing";

	//cout << sizeof(string) << endl;
	//string *p = &hay;
	//cout << p << endl;
	//cout << p+1 << endl;

	cout << "Is needle in haystack : " << kmp_match(hay, needle) << endl; 	

	int pos = naive_algo(hay, needle);

	cout << "Matching by naive : " << pos << endl;
	
	return EXIT_SUCCESS;
}
