#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;


struct {
	void operator()(int x) {
		cout << x << endl;
	}
}something;


int
main(int argc, char* argv[]) {
	
	// [Capture Clause](parameter){function definition}

	
	vector<int> test_vec{2,3,7,8,9};

	for_each(test_vec.begin(), test_vec.end(), [](int x){cout << x*2 << endl; });

	return EXIT_SUCCESS;
}
