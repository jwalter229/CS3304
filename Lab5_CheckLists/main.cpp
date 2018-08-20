#include <iostream>
#include "node1.h";
#include "check_lists.h";
using namespace std;
using namespace main_savitch_5;

//Print the linked list
void list_print(node * head_ptr)
{
	//Start at the head pointer and loop through the linked list
	for (node* i = head_ptr; i != NULL; i = i -> link())
    {
		//Print out current element
    cout << i -> data() << " ";
	}
	//Creating New line
	cout << "" << endl;
}

int main()
{	
	//Creating list1
	node* one = new node(23.5);
	node* two = new node(45.6, one);
	node* three = new node(67.7, two);
	node* four = new node(89.8, three);
	node* five = new node(12.9, four);
	
	//Creating list2
	node* a = new node(12.9);
	node* b = new node(89.9, a);
	node* c = new node(-123.5, b);  
	node* d = new node(67.7, c);
	node* e = new node(45.6, d);
	node* f = new node(23.5, e);
	
	list_print(five);
	check_list1(five);
    
	list_print(f);
	check_list2(f);
	
	node* pos_4 = list_locate(f, 4);
    cout << "at location 4 in list2: " << pos_4 -> data() << endl;
    
	node* head_ptr;
	node* tail_ptr;
	
	list_copy(five, head_ptr, tail_ptr);
	list_print(head_ptr);
	check_list1(head_ptr);
	cout << "at tail3: " << tail_ptr -> data() << endl;
    //list_print(tail_ptr);
	
	list_head_remove(f);
	list_print(e);
	check_list2B(e);
	
	list_remove(d);
	list_print(e);
	check_list2C(e);

}//end of main()