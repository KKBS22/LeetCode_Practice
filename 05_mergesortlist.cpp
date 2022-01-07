#include<iostream>

using namespace std;

struct ListNode {

	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x) , next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode*
merge_lists(ListNode* list_one, ListNode* list_two) {

	ListNode final_list(0);
	ListNode *test = &final_list;

	return test;	

}

int 
main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	ListNode *testing =  new ListNode(5);

	cout << testing->val << endl;

	delete(testing);

	return EXIT_SUCCESS;
}
