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

	ListNode *final_list = new ListNode(0);
	
	while((list_one->next != NULL) && (list_two->next != NULL)) {
	
		if(list_one->val < list_two->val) {
			final_list = list_one;
			list_one = list_one->next;
		} else {
			final_list = list_two;
			list_two = list_two->next;
		}
		final_list = final_list->next;
	}



	return final_list;	

}

int 
main(int argc, char * argv[]) {

	(void)argc;
	(void)argv;

	ListNode *testing =  new ListNode(5);

	cout << testing->val << endl;

	if (testing->next == NULL) {
		cout << "Checking condition " << endl;
	}
	delete(testing);

	return EXIT_SUCCESS;
}
