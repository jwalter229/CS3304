#ifndef _SET_H
#define _SET_H

#include <cstdlib>
#include <iostream>
#include "node1.h"

using namespace main_savitch_5;

class set
{
public:
	typedef node::value_type value_type;
	typedef std::size_t size_type;

	set();
	// postcondition: empty set has been created

	~set();
	// postcondition: set has been deallocated

	set& operator = (const set& source);
	// postcondition: 

	set(const set& source);
	// postcondition: a copy of source has been created
	
	bool set_contains(const value_type& entry) const;
	// postcondition: whether entry is in the set has been returned
	
	void set_insert(const value_type& entry);
	// postcondition: entry is in the set

	void set_remove(const value_type& entry);
	// postcondition: entry is not in the set

	size_type size() const;
	// postcondition: number of elements in the set has been returned

	friend bool operator == (const set& s1, const set& s2);
	// postcondition: returned whether s1 & s2 are equal

	friend std::ostream& operator << (std::ostream& output, const set& s);
	// postcondition: s has been displayed on output
	
	friend set union_set(const set& s1, const set& s2);
	//postcondition: union of s1 & s2 has been returned

	friend set intersection(const set& s1, const set& s2);
	// postcondition: intersection of s1 & s2 has been returned

	friend set difference(const set& s1, const set& s2);
	// postcondition: difference of s1 - s2 has been returned

	friend bool subset(const set& s1, const set& s2);
	// postcondition: returned whether s1 is a subset of s2


private:
	node* head;
	size_type used;

};


#endif
