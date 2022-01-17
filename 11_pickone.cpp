#include<iostream>
#include<vector>
#include<cmath>

#define UNIT 10
using namespace std;


int
plus_one (vector<int> &num) {
	int num_test = 0;
	for(int i = 0; i < num.size(); i++) {
		num_test =  num_test + (num[i] * pow(UNIT, (num.size()-1)-i));	
	}
	return (num_test+1);
}


vector<int>
plus_one_vec (vector<int> &num) {
	int num_test = 0;
	for(int i = 0; i < num.size(); i++) {
		num_test =  num_test + (num[i] * pow(UNIT, (num.size()-1)-i));	
	}
	num_test += 1;
	vector<int> plus_one_ret;
	if (num_test != 0) {
		while (num_test > 0) {
			int n = num_test % 10;
			num_test = num_test / 10;
			plus_one_ret.insert(plus_one_ret.begin(), n);
			
		}	
	}
	return plus_one_ret;
}

int
main(int argc, char* argv[]) {

	vector<int> test{9, 9, 9};
		
	cout << "The number is : " << plus_one(test) << endl;
	
	auto test2 = plus_one_vec(test);
	cout << "Size after plus one : " << test2.size() << endl;
	
	for (vector<int>::iterator it = test2.begin(); it != test2.end() ; it++) {
		cout << *it << endl;
	}

	// Some common Math functions:
	// double testing = 5.1 % 3.0;
	cout << "Calculating the remainder : " << remainder(5.1,3.0) << endl;
	cout << "Calculating the hypotinuse : " << hypot(3.0, 6.0) << endl;

	cout << "Indicate overflow value of : Float " << HUGE_VAL << endl;
	
	return EXIT_SUCCESS;
}
