#include <iostream>
#include <string>

using namespace std;

void* operator new(size_t size){
    	cout <<"Allocated " << size << " bytes" << endl;
    	return malloc(size);
}

void foo()
{
	#define MY_NAME "Alex"
}


int main() {
	string smallString = "teststringone";
	int test = smallString[1];
    	cout << smallString << endl;
	cout << "The val is : " << test << endl;

	int choice;
	cin >> choice;

	cout << "Enter the name : " << endl;
	string nstr{};
	getline(cin >> ws, nstr);
	cout << "Hello " << nstr << " welcome to " << choice << endl;

	float ftest = 4.1;

	cout << "The float value is : " << ftest << endl;

	int testing = 4.5;
	//int gtest {4.5};

	cout << "The intger value is : " << testing << endl;

	cout << "My name is: " << MY_NAME << endl;

	return EXIT_SUCCESS;
}
