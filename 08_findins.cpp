#include<iostream>
#include<vector>

using namespace std;


void 
swap (int *one, int *two) {
	int temp = *one;
	*one = *two;
	*two = temp;
}

/**
 * Arranges the array in place
 * p :
 * r : 
 * */

int
partition(vector<int> &nums, int p, int r){
	int x = nums[r];
	int i = p-1;
	for (int j = p ; j < r; j++) {
		if (nums[j] < x) {
			i = i +1;
			swap(nums[i], nums[j]);
		}
	}
	swap(nums[i+1], nums[r]);
	return i+1;
}


void
quick_sort(vector<int> &nums, int p, int r) {
	if (p < r) {
		int q = partition(nums, p, r);
		quick_sort(nums, p, q-1);
		quick_sort(nums, q+1, r);
	}	
}




int
bin_search(vector<int> &nums, int find, int low, int high) {
	if (high >= low) {
		int mid = (low + high)/2;
		cout << mid << endl;
		if (low == high) {
			if (nums[mid] < find) {
				return mid+1;
			} else {
				return mid == 0 ? mid : mid-1; 
			}
		}
		if (nums[mid] == find) {
			return mid;
		} else if (find < nums[mid]) {
			return bin_search(nums,find,low,mid-1);
		} else {
			return bin_search(nums,find,mid+1,high);
		}
	} 
	return -1;
}


int
main(int argc, char* argv[]) {

	(void)argc;
	(void)argv;

	vector<int> test{1,3,4,5,6,9,10};

	int to_find = 7;


	cout << "Before Sorting " << endl;
	swap(test[1],test[2]);
	for (int j =0 ; j < test.size(); j++) {
		cout << "j : " << j << " : " << test[j] << endl;	
	}

	cout << "After Sorting" << endl;
	quick_sort(test,0,test.size()-1);
	for (int k =0; k< test.size(); k++) {
		cout << "k : " << k << " : " << test[k] << endl;
	}

	int val = bin_search(test,to_find,0,test.size()-1);
	if (val == -1) {
		cout << "Integer : " << to_find << " not found " << val << endl;
	} else {
		cout << "Found integer : " << to_find << " at " << val << endl;
	}	
		
	return EXIT_SUCCESS;
}

