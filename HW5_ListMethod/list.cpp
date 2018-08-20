#include "list.h"
#include <assert.h>
#include <iostream>

// Jason Walters

using namespace std;

// return the first element of the
// list pointed to by head_ptr.
value_type head(list head_ptr)
{
	assert(head_ptr != NULL);
	//Return the first element in the linked list
	return head_ptr->data();
}// end of head


// return true if list is empty.
bool list_is_empty(list head_ptr)
{
	return head_ptr == NULL; // checking to see if list is empty
}// end of bool list_is_empty

// return a list that contains the list
// pointed by head_pointer without the fist element
list tail(list head_ptr)
{
	assert(head_ptr != NULL);
	
	// create a new NULL list
	list temp = NULL;
	
	// create an array of head_ptr length
	value_type tempArray [list_length(head_ptr)];
	
	// create a new index variable
	int jdx = 0;
	
	// loop through linked list
	// copy vales to array
	for (list idx = head_ptr->link(); idx != NULL; idx = idx->link())
	{
		
		tempArray[jdx] = idx->data();
		jdx++;
	}
	
	// copy array vales to a new
	// lined list going backwards
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		
		list_head_insert(temp, tempArray[jdx]);
	}
	return temp;
}// end of list tail


// return a list that consists of 'val'
// followed by the list point to by head_prt
list cons(value_type val, const list head_ptr)
{
	// creating new NULL list
	list temp = NULL;
	
	// array of head_ptr length
	value_type tempArray[list_length(head_ptr)];
	
	// creating an index variable
	int jdx = 0;
	
	// loop through linked list and 
	// make a copy of all values to array
	for (list idx = head_ptr; idx != NULL; idx = idx->link())
	{
		tempArray[jdx] = idx->data();
		jdx++;
	}
	
	// Copying all values of array 
	// into new linked list going backwards
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		list_head_insert(temp, tempArray[jdx]);
	}
	// adding a value at the front of the array
	list_head_insert(temp, val);
	
	return temp;
}


// a new list that starts with the elements in the 
// list pointed to by head_ptr and ends with 'val'.
list append(const list head_ptr, value_type val)
{	
	// creating new NULL list
	list temp = NULL;
	
	// add value at the start of the array, 
	// it will be the last value of the array later
	list_head_insert(temp, val);
	
	// creating an array of length head_ptr
	value_type tempArray[list_length(head_ptr)];
	
	// creating index integer value
	int jdx = 0;
	
	// looping through linked list
	// copying all values to array
	for (list idx = head_ptr; idx != NULL; idx = idx->link())
	{
		tempArray[jdx] = idx->data();
		jdx++;
	}
	
	// coping all values in the array 
	// into new linked list backwards
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		list_head_insert(temp, tempArray[jdx]);
	}
	return temp;
}// end of append


// return a new list that list one and list two
// combined into one list
list append(const list one, const list two)
{
	// creating a new NULL list
	list temp = NULL;
	
	// create an array of size list
	// that equals one and two
	value_type tempArray[list_length(one) + list_length(two)];
	
	// creating index variable
	int jdx = 0;
	
	// looping through linked list one 
	// and copying all values to array
	for (list idx = one; idx != NULL; idx = idx->link())
	{
		tempArray[jdx] = idx->data();
		jdx++;
	}
	
	// looping through linked list two 
	// and copying all values to array
	for (list kdx = two; kdx != NULL; kdx = kdx->link())
	{
		tempArray[jdx] = kdx->data();
		jdx++;
	}
	
	// placing all array elments into
	// the new linked list in reverse order
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		list_head_insert(temp, tempArray[jdx]);
	}
	
	return temp;
}// end of append


// creat a new list with the same values
// as the list pointed to by the head_prt
// but not the last element
list remove_last(const list head_ptr)
{
	assert(head_ptr != NULL);
	
	// making a new NULL list called temp
	list temp = NULL;
	
	//Create new array of size head_ptr
	value_type tempArray[list_length(head_ptr)];
	
	//Create index variable named jdx
	int jdx = 0;
	
	// looping through linked list and making 
	// a copy of all values to array except for the last value
	for (list idx = head_ptr; idx->link() != NULL; idx = idx->link())
	{
		tempArray[jdx] = idx->data();
		jdx++;
	}
	
	// copying all array values into
	// a new linked list
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		list_head_insert(temp, tempArray[jdx]);
	}
	return temp;
}// end of remove last

// Create and return a new list that contains 
// the elements of head_ptr that are not equal to val.
list remove_all_of(const list head_ptr, value_type val)
{
	// ceate new NULL list
	list temp = NULL;
	
	// create new array of size head_ptr
	value_type tempArray[list_length(head_ptr)];
	int jdx = 0;
	
	// Copying all elements of linked list to array 
	// except for numbers that are equal to value
	for (list idx = head_ptr; idx != NULL; idx = idx->link())
	{
		if (idx->data() != val)
		{
			tempArray[jdx] = idx->data();
			jdx++;
		}
	}
	
	// copy all array values into a new linked list
	for (jdx = jdx - 1; jdx >= 0; jdx--)
	{
		list_head_insert(temp, tempArray[jdx]);
	}
	
	return temp;
}// end of remove all of

// will return the last value 
// in the list pointed to by head_ptr.
value_type last(const list head_ptr)
{
	assert(head_ptr != NULL); // asserting the head_prt is not equal to NULL
	
	// returning the last value of the  head_prt
	for (list idx = head_ptr; idx != NULL; idx = idx->link())
	{
		if (idx->link() == NULL)
		{
			return idx->data();
		}
	}
}// end of last


// checking to see
// if the lists are equal
bool equals(const list list1, const list list2)
{
	if(list_is_empty(list1)) 
	{
		return list_is_empty(list2);
	} 
	 
	else if(list_is_empty(list2))
		return false;
		
	 else if(head(list1) != head(list2))
	{
		return false;
	} 
	else{
		return equals(tail(list1), tail(list2));
	 }
}// end of equals


