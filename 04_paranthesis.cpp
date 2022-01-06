#include<iostream>
#include<stack>

using namespace std;


bool
check_paren(string s) {

	stack<char> brackets;

	for (char &c : s) {
		switch(c) {
			case '(' :
				brackets.push(c);
				break;
			case '{' :
				brackets.push(c);
				break;
			case '[' :
				brackets.push(c);
				break;
			case ')' :
				if (brackets.top() == '(') {
					brackets.pop();
				} else { 
					return false;
				}
				break;
			case '}' :
				if (brackets.top() == '{') {
					brackets.pop();
				} else {
					return false;
				}
				break;
			case ']' :
				if (brackets.top() ==  '[') {
					brackets.pop();
				} else {
					return false;
				}
				break;
			default :
				break;		
		}
	}
	return brackets.empty();

}


int
main() {

	string s = "((()))";
	string s_new = "{{{}}}";

	for (char &c : s) {
		cout << c << endl;
		int i = c;
		cout << i << endl;
	}

	cout << check_paren(s_new) << endl;

	stack<char> test;
	stack<char> test2;

	for (char &t : s) {
		test.emplace(t);
		//test2.push(t);
	}

	for (char &t : s_new) {
		test2.push(t);
	}

	test.swap(test2);

	// Size of the stack
	
	cout << "The size of the stack is : " << test.size();

	// using emplace 	

	cout << "Using emplace to populate the stack " << endl;

	while(!test.empty()) {
		cout << test.top() << endl;
		test.pop();
	}

	// using push
	cout << "Using push to populate the stack " << endl;

	while(!test2.empty()) {
		cout << test2.top() << endl;
		test2.pop();
	}

	return EXIT_SUCCESS;
}
