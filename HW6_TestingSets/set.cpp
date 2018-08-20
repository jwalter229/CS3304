// FILE: bag5.template
// CLASS implemented: bag (see bag5.h for documentation)
// NOTE:
//   Since bag is a template class, this file is included in node2.h.
// INVARIANT for the bag class:
//   1. The items in the bag are stored on a linked list;
//   2. The head pointer of the list is stored in the member variable head_ptr;
//   3. The total number of items in the list is stored in the member variable
//       many_nodes.

#include <cstdlib>
#include <iostream>
#include "set.h"


// postcondition: empty set has been created
set::set() {
	head = NULL;
	used = 0;
}

// postcondition: set has been deallocated
set::~set() {
	list_clear(head);
	used = 0;
}


// postcondition: a copy of source has been created
set::set(const set& source) {

	if (source.head == NULL) {
		head = NULL;
	}
	else {
		node *tail_ptr; // Needed for argument to list_copy
		list_copy(source.head, head, tail_ptr);
		used = source.used;
	}
}


set& set::operator = (const set& source) {
	if (this != &source)
	{
		if (used != source.used)
		{
			delete head;
			head->set_data(source.head->data());
			used = source.used;

		}
		std::copy(source.head, source.head + source.used, head);
		used = source.used;
	}
}

// postcondition: entry is in the set
void set::set_insert(const value_type& entry) {

	node* p;

	if (head == NULL) {
		list_head_insert(head, entry);
	}
	else if (!set_contains(entry))
	{
		p = new node(entry, head->link());
		head->set_link(p);
		p = p->link();
	}
	++used;
}

// postcondition: entry is not in the set
void set::set_remove(const value_type& entry) {
	
	node *target_ptr;
	target_ptr = list_search(head, entry);
	target_ptr->set_data(head->data());
	list_head_remove(head);
	--used;
}

// postcondition: number of elements in the set has been returned
set::size_type set::size() const {
	return used;
}

// postcondition: difference of s1 - s2 has been returned
set difference(const set& s1, const set& s2) {
	set s3;
	node *c = s1.head;

	while (c != NULL) {
		if (!s2.set_contains(c->data())) {
			s3.set_insert(c->data());
		}
		c = c->link();
	}
	return s3;
}

//postcondition: union of s1 & s2 has been returned
set union_set(const set& s1, const set& s2) {
	set s3;
	node *c = s1.head , *c2 = s2.head;

	while (c != NULL) {
		s3.set_insert(c->data());
		c = c->link();
	}

	while (c2 != NULL) {
		if (s3.set_contains(!c2->data())) {
			s3.set_insert(c2->data());
		}
		c2 = c2->link();
	}
	return s3;
}

// postcondition: intersection of s1 & s2 has been returned
set intersection(const set& s1, const set& s2) {
	set s3;
	node *c = s1.head, *c2 = s2.head;

	while (c != NULL) {
		while (c2 != NULL) {
			if (c->data() == c2->data()) {
				s3.set_insert(c2->data());
			}
			c2 = c2->link();
		}
		c2 = s2.head;
		c = c->link();
	}
	return s3;
}

// postcondition: whether entry is in the set has been returned
bool set::set_contains(const value_type& entry) const {
	node *cursor = head;

	while (cursor != NULL) {
		if (entry == cursor->data())
			return true;
		cursor = cursor->link();
	}
	if (cursor == NULL)
		return false;
}


// postcondition: s has been displayed on output
std::ostream& operator << (std::ostream& output, const set& s) {
	node *c = s.head;
	while(c != NULL){
		output << c->data() << ", ";
		c = c->link();
	}
	return output;
}


// postcondition: returned whether s1 is a subset of s2
bool subset(const set& s1, const set& s2) {
	node *c = s1.head;
	while(c != NULL) {
		if (s2.set_contains(c->data())) {
			c = c->link();
		}
		else
			return false;
	}
	return true;
}

// postcondition: returned whether s1 & s2 are equal
bool operator == (const set& s1, const set& s2) {
	if (s1.head->data() == s2.head->data())
		return true;
	else
		return false;
}



