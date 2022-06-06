#include<iostream>
#include<vector>
#include<algorithm>


void
merge_sort() {

}

void 
bubble_sort(std::vector<int> &test) {
	for (int i = 0; i < test.size(); i++) {
		for (int j = 0; j < ) {
		
		}
	}		
	
}

int
partition(std::vector<int> &test, int p , int r) {

	int x = test[r];
	int i = p-1;

	for (int j = p ; j <= r-1; j++) {
		if (test[j] < x) {
			i = i+1;
			std::swap(test[i], test[j]);
		}
	}	
	std::swap(test[i+1], test[r]);
	return i+1;
}

void
quick_sort(std::vector<int> &test, int p, int r) {
	if (p < r) {
		int q = partition(test,p,r);
		quick_sort(test,p,q-1);
		quick_sort(test,q+1,r);
	}

}

void
pass_as_ref(std::vector<int> &test) {
	// Sample display
	for (std::vector<int>::iterator it = test.begin(); it != test.end(); it++) {
		//*it = *it *3;
		std::cout << *it << " : ";
	}
	std::cout << std::endl;
}

int 
main() {
	
	std::vector<int> test_vec{6,1,9,2,5,0,23};

	// Display as pass by ref
	pass_as_ref(test_vec);
	
	// Way to display elements 
	for (std::vector<int>::iterator it = test_vec.begin(); it != test_vec.end(); it++) {
		std::cout << *it << "--";
	}

	std::cout << std::endl;

	quick_sort(test_vec,0,6);

	pass_as_ref(test_vec);

	return EXIT_SUCCESS;
}
