#include "toolkit.h"
#include "bintree.h"
#include "bst.h"
#include <iostream>
#include "build_tree.h"

using namespace std;

void makeLinkedList(binary_tree_node<int>* root_ptr, node* list);

void sortedListToBST(node* head_ptr, int n);

int main()
{
	cout << "First we are creating a binary search tree. Our tree will contain 1, 2, 3, 4, 5, 6, 7 as its in order traversal." << endl;
	binary_tree_node<int> *s1 = sample1();

	node *list;
	
	cout << "Converting that binary search tree into a linked list " << endl;
	cout << endl;
	cout << "The linked list contains these numbers (smallest to largest): " << endl; 
	makeLinkedList(s1, list);
	
	cout << endl;
	cout << endl;
	

}// end of main


// star of makeLinkedList
void makeLinkedList(binary_tree_node<int>* root_ptr, node* list){
	
	if (root_ptr == NULL)
	{

	}
	
	else{
		
		makeLinkedList(root_ptr->left(), list); 
		list_head_insert(list, root_ptr->data());
		cout << list->data() << " ";
		makeLinkedList(root_ptr->right(), list); 
	}
}// end of mainLinkedList

