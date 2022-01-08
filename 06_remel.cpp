#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool
my_func(int i, int j) {
	return i>j;
}


int 
rem_element(vector<int> &nums, int val) {

	for(int i=0 ; i< nums.size(); i++) {
		if (nums[i] == val) {
			nums[i] = -1;
		}	
	}

	sort(nums.begin(), nums.end(), my_func);
	

	int final_size =0;
	for (int i =0; i< nums.size(); i++) {
		if (nums[i] != -1) {
			final_size += 1;
		}
	}
	return final_size;
}


int
main(int argc, char *argv[]) {

	vector<int> test{1,2,4,3,6,4,6,6,7};

	cout << "Before removal :" << test.size() << endl;

	cout << "Final vector size : " << rem_element(test, 6) << endl;
	
	for (int i=0 ; i< test.size(); i++) {
		cout << test[i] << " " ;
	}
	
	return EXIT_SUCCESS;
}
