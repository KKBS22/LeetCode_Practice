#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int
main() {
	string test = "10";
	float val = stof(test);
	cout << "The value of float is :" << val+1 << endl;
	string name = "Testing";
	int arr[10] = {0,1,2,3,4};
	cout << name[6] << endl;
	cout << arr[0] << endl;
	cout << sizeof(name) << endl;
        cout << sizeof(string) << endl;	
	return EXIT_SUCCESS;
}
