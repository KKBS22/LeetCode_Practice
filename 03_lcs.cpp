#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

string 
lcs(vector<string>& string_vec) {
	
	cout << "In function" << endl;

	string rep_string = "";
	if (string_vec.size() == 0) { 
		return rep_string; 
	} else {

		cout << "The size fo vector is : " << string_vec.size() << endl;
		//return rep_string;

		rep_string = string_vec[0];

		for (int i = 1 ; i < string_vec.size(); i++) {
			for (int j = 0; j < rep_string.length() ; j++) {
				if (rep_string.substr(0,j) != string_vec[i].substr(0,j)) {
					rep_string = string_vec[i].substr(0,j);
				}
			}
		
		}

		return rep_string;
	}

	//return rep_string;
}


int
main(int argc, char* argv[]) {

	vector<string> test_vec{"Leet","Leetcode","Lee"};

	sort(test_vec.begin(), test_vec.end());

	string test = lcs(test_vec);

	cout << "Test output : " << test << endl;
	
	// Finding the length of the string
	cout << test_vec[0].length() << endl;

	// Iterating through a vector	
	for (vector<string>::iterator it = test_vec.begin(); it != test_vec.end(); it++) {
		cout << *it << endl;
	}

	// String concatenation
	string a = "b";
	string b = "c";
	string testZQ = a +b;

	cout << "Does this concat : " << testZQ << endl; 

	return EXIT_SUCCESS;
}
