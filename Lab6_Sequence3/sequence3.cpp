#include <iostream>
#include <stdlib.h>
#include <cassert>
#include "sequence3.h"

using namespace std;
namespace main_savitch_5
{
	
sequence::sequence()
{
	head_ptr = NULL;
	tail_ptr = NULL;
	cursor = NULL;
	precursor = NULL;
	many_nodes = 0;
}

sequence::sequence(const sequence& source)
{
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;
	
	if(many_nodes != 0)
	{
		tail_ptr = list_locate(head_ptr,many_nodes);
		int CursorSource = 1;
		node* goSource = source.head_ptr;

		while(goSource != source.cursor && goSource != NULL)
		{
			CursorSource++;
			goSource = goSource -> link();
		}
		cursor = list_locate(head_ptr,CursorSource);
		
		if(CursorSource != 1)
		{
			precursor = list_locate(head_ptr,CursorSource - 1);
		}
	} 
	else {
			
			cursor = NULL;
			precursor = NULL;
			tail_ptr = NULL;
		}
}// end of sequence construtor


// start of sequence deconstructor	
sequence::~sequence()
{
	list_clear(head_ptr);
	many_nodes = 0;
}// end of deconstructor


// start of start
void sequence::start()
{
	cursor = head_ptr;
	precursor = NULL;
}// end of start


// start of advance
void sequence::advance()
{
		assert(is_item());
		precursor = cursor;
		cursor = cursor -> link();
}// end of advance


// start of insert
void sequence::insert(const value_type& entry)
{
	//insert at head when there's 0 or 1 node
	//else insert before cursor
	if(cursor == NULL || cursor == head_ptr)
	{
		list_head_insert(head_ptr,entry);
		cursor=head_ptr;
		precursor=NULL;
	
	} else {
		
			node* temp = new node(entry,cursor);
			temp -> set_link(precursor -> link());
            cursor = temp;
            precursor -> set_link(cursor);
            precursor = precursor -> link();
		}
		++many_nodes;
        tail_ptr = list_locate(head_ptr, many_nodes);
}// end of insert
	

// start of attach
void sequence::attach(const value_type &entry)
{
	// insert at head when manynode = 0 
	// else insert it after cursor 
	// if at end(cursor:null), insert aftr precursor
	if(head_ptr == NULL)
	{
		list_head_insert(head_ptr,entry);
		cursor=head_ptr;
	} 
	
	else if(cursor == NULL)
	
	{
		list_insert(precursor,entry);
		cursor=precursor -> link();
			
	} else {
		
			node* temp = new node(entry,cursor -> link());
			cursor -> set_link(temp);
			precursor = cursor;
			cursor = temp;
	}
		many_nodes++;

        tail_ptr = list_locate(head_ptr, many_nodes);
}// end of attach


// start of operator =	
void sequence::operator =(const sequence &source)
{
	if (this == &source)
	{
		return;
	}

	list_clear(head_ptr);
	many_nodes = 0;
	list_copy(source.head_ptr, head_ptr, tail_ptr);
	many_nodes = source.many_nodes;

	if(many_nodes != 0)
	{
		tail_ptr = list_locate(head_ptr,many_nodes);
		int CursorSource = 1;
			node* goSource = source.head_ptr;
			
			while(goSource != source.cursor && goSource != NULL)
			{
				CursorSource++;
				goSource = goSource -> link();
			}
			
			cursor=list_locate(head_ptr,CursorSource);
			if(CursorSource != 1)
			{
				precursor = list_locate(head_ptr,CursorSource - 1);
			}
	
	} else {
		
            tail_ptr = NULL;
            cursor = NULL;
            precursor = NULL;
			
			}
}// end of operator =


//start of remove current
void sequence::remove_current()
{
	// assert
	assert(is_item());
        
	if(cursor == head_ptr)
	{
		cursor = head_ptr -> link();
		list_head_remove(head_ptr);
	
	} else {
		
            list_remove(precursor);
            cursor = precursor -> link();
			
			}

        tail_ptr=list_locate(head_ptr,many_nodes);
        --many_nodes;
}//end of remove current


// CONSTANT MEMBER FUNCTIONS
sequence::value_type sequence::current() const
{
	assert(is_item());
        return cursor->data();
}// end of CONSTANT MEMBER FUNCITONS

}// end of namespace
