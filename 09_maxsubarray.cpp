#include<iostream>
#include<algorithm>
#include<vector>
#include <bits/stdc++.h>

using namespace std;

int
max_subbarray(vector<int> &nums) {
	int min_sum = INT_MIN;
	for (int i =0; i < nums.size(); i++) {
		int curr_sum =0;
		for (int j = i ; j < nums.size(); j++) {
			curr_sum += nums[j];
			min_sum = max(min_sum, curr_sum);	
		}
	}
	return min_sum;
}


int
kadane(vector<int> &nums) {
	int max_curr = nums[0], max_global = nums[0];
	for (int i = 1 ; i < nums.size() ; i++) {
		max_curr = max(nums[i], max_curr + nums[i]);
		if (max_curr > max_global) {
			max_global = max_curr;
		}
	}
	return max_global;

}

int
main(int argc, char* argv[]) {
	
	(void)argc;
	(void)argv;

	vector<int> test_vec{1,2,3,-2,-4,8,-1,0};

	int ans = max_subbarray(test_vec);
	cout << "Max subarray : " << ans << endl;

	cout << "Max subarray Kadane : " << kadane(test_vec) << endl;

	int test = max(90,100);

	cout << "Max value : " << test << endl;

	return EXIT_SUCCESS;
}
