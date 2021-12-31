#include<iostream>

using namespace std;

int
main(int argc, char* argv[]) {

	int n =0 , num =0;
	int digit =0;
	int reverse = 0;

	cout << "Enter a number " << endl;
	cin >> n;

	num = n;

	do {
		digit = n % 10;
		reverse = (reverse * 10) + digit;
		n = n/10;
	}while(n !=0);

	if (reverse == num ) {
		cout << "Number : " << num << " Has a palidrome : " << reverse << endl;
	} else {
		cout << "Not a plaindrome" << endl;
	}

	return EXIT_SUCCESS;
}
