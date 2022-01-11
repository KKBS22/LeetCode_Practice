#include<iostream>
#include<string>
#include<stack>
using namespace std;

int
last_word_length(string s) {
	
	stack<int> inter_val;
	int i = 0;
	int j = 0;
	// cout << "String length is : " << s.length() << endl;
	while(i < s.length()) {
		if (s[i] == ' ') {
			i++;
			if (j !=0) {
				inter_val.push(j);
			}
			j =0;
		} else {
			i++;
			++j;
			if ( i == s.length()) {
				inter_val.push(j);
			}
		}
	
	}

	// cout << "The size of the stack is : " << inter_val.size() << endl;	
	// while(!inter_val.empty()) {
	//	cout << inter_val.top() << endl;		
	//	inter_val.pop();
	// }
	return inter_val.top();	
}


int
main(int argc, char* argv[]) {
	(void)argc;
	(void)argv;

	string atest = "  testing the last word";

	int a_space = atest[0];

	cout << "ASCII val of space : " << a_space << endl;
	cout << atest.length() << endl;


	cout << "Size of the last word in line : " << last_word_length(atest) << endl;
	return EXIT_SUCCESS;

}
