#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace std;
using namespace main_savitch_5;

void list_without_duplicate(node*& head_ptr)
{
    node* new_head = new node(head_ptr -> data());
    node* new_tail = new_head;
    
    for (node *idx = head_ptr; idx != NULL; idx = idx -> link())
    {
        if (list_search(new_head, idx -> data()) == NULL)
        {
            list_insert(new_tail, idx -> data());
            new_tail = new_tail -> link();
        }
    }
    
    list_clear(head_ptr);
    head_ptr = new_head;
}// end of list_without_diplicate


// start of list_split
// will return the pointer to the head of a new linked list
// will include all elements less than the split value set later in program
// elements passed contain elements >= the split value
node* list_split(node *&head_ptr, const node::value_type &split_value)
{
	// Creating two different head and tail pointers
	// this will allow the program to group the data
	// lower than split value and hgher or == the split value
    node *lowest_head = new node;
    node *lowest_tail = lowest_head;
    node *highest_head = new node;
    node *highest_tail = highest_head;
	
	// Use while loop used to loop through the nodes and 
	// sort them into two different list
    while (head_ptr != NULL)
    {
         if (head_ptr -> data() < split_value)
        {
            list_insert(lowest_tail, head_ptr -> data());
            lowest_tail = lowest_tail -> link();
        }
        else
        {
            list_insert(highest_tail, head_ptr -> data());
            highest_tail = highest_tail -> link();
        }
        list_head_remove(head_ptr);
    }//end of while head_ptr != NULL
    
	// used the head nodes as holders
    list_head_remove(highest_head); // removing the highest_head
    list_head_remove(lowest_head); // removing the lowest_head

	// setting head_ptr to highest_head
	// this list will become list larger than split value
    head_ptr = highest_head;
    
    return lowest_head;
}// end of list_split

// start of find_maximum
node::value_type find_maximum(node *&head_ptr)
{
    node::value_type maximum = head_ptr -> data();
    for (node *idx = head_ptr -> link(); idx != NULL; idx = idx -> link())
    {
        if (maximum < idx -> data())
        {
            maximum = idx -> data();
        }
    }
    return maximum;
}//end of find_maximum

//start of sort_list
void sort_list(node *&head_ptr)
{
	// < 2 nodes DO NOT need to sort
    if (head_ptr -> link() == NULL)
        return;
        
    node *sorted = NULL;
    
    while (head_ptr != NULL)
    {
        // finding the current maximum
        node::value_type current_maximum = find_maximum(head_ptr);
        
        if (head_ptr -> data() == current_maximum)
        {
            list_head_insert(sorted, head_ptr -> data());
            list_head_remove(head_ptr);
        }
		// if previous condtions are not met
		// excute next statements
        else
        {
			// looping the list for maximum
			node *previous = head_ptr;
            node *idx = head_ptr -> link();
            
			// using a while loop to find
			// more instances of the current_maximum
			while (idx != NULL)
            {
				// checking to see if current node
				// is equal to current_maximum
				if (idx -> data() == current_maximum)
                {
					// if what is at idx is equal to
					// current_maximum placing it in sorted list
					list_head_insert(sorted, idx -> data());
					// if idx is is equal to current_maximum
					// removing it from the ussorted list
					list_remove(previous);
                    
                    idx = previous -> link();
                }
                else // increment both idx and previous on the next loop
                {
                    previous = idx;
                    idx = idx -> link();
                }
            }//end of while loop
        }
    }//end of while loop
    
    head_ptr = sorted;
}//end of sort_list


//start of list_print
void list_print(node *head_ptr)
{
    for (node *idx = head_ptr; idx != NULL; idx = idx -> link())
    {
        cout << idx -> data();
        if (idx -> link() != NULL)
            cout << ", ";
    }
    cout << endl;
}//end of list_print


int main()
{
	node* head = new node(4);
	list_head_insert(head, 2);
	list_head_insert(head, 8);
	list_head_insert(head, 3);
	list_head_insert(head, 5);
	list_head_insert(head, 7);
	list_head_insert(head, 3);
	list_head_insert(head, 1);
	list_head_insert(head, 6);
	list_head_insert(head, 9);
	list_head_insert(head, 4);
	list_head_insert(head, 1);
	list_head_insert(head, 9);
    
    node *list_one, *list_one_tail;    
    list_copy(head, list_one, list_one_tail);
    
    cout << "Test: " << endl;
	list_print(list_one); //printing list_one
    cout << endl << "Result of list_without_duplicate: " << endl;
    list_without_duplicate(list_one);
    list_print(list_one);// printing list_one without duplicates
    
    node *list_two, *list_two_tail;
    list_copy(head, list_two, list_two_tail);
    cout << endl << "Result of list_split (with split value of 4):" << endl;
    node *list_two_low;
    list_two_low = list_split(list_two, 4); // setting where to split list
    
	// displaying < split value
	cout << "Less than split value (Low List): ";
    list_print(list_two_low);
    
	// displaying >= split value
	cout << "Greater than or equal to split value (High List): ";
    list_print(list_two);
    
	// displayiong result of sort_list
    cout << endl << "Result of sort_list (arranged in order lowest to hightest with duplicates): " << endl;
    sort_list(head);
    list_print(head);
}// end of main()

/*	Jason Walters
	Tues - Thurs  */
