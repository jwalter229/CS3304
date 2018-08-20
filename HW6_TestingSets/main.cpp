#include "set.h"
#include <cassert>
#include <iostream>

int main()
{
	set s;
	assert(!s.set_contains(7));
	s.set_insert(7);
	assert(s.set_contains(7));
	s.set_remove(7);
	assert(!s.set_contains(7));

	set s1;
	s1.set_insert(4);
	s1.set_insert(5);
	s1.set_insert(-24);
	s1.set_insert(89);
	s1.set_insert(34);
	s1.set_insert(11);
	s1.set_insert(0);
	s1.set_insert(3);
	s1.set_insert(14);
	s1.set_insert(28);
	std::cout << "Displaying set 1: " << s1 << std::endl;

	set s2;
	s2.set_insert(6);
	s2.set_insert(-5);
	s2.set_insert(-24);
	s2.set_insert(-89);
	s2.set_insert(34);
	s2.set_insert(-11);
	s2.set_insert(0);
	s2.set_insert(3);
	std::cout << "Displaying set 2: " << s2 << std::endl;

	set s3 = union_set(s1, s2);
	assert(s3.set_contains(4));
	assert(s3.set_contains(0));
	assert(s3.set_contains(-5));
	std::cout << "Displaying the Union of set 1 and set 2: " << s3 << std::endl;

	set s4 = intersection(s1, s2);
	assert(s4.set_contains(34));
	assert(!s4.set_contains(4));
	assert(!s4.set_contains(-5));
	std::cout << "Displaying the intersection of set 1 and set 2: " << s4 << std::endl;

	set s5 = difference(s1, s2);
	assert(s5.set_contains(4));
	assert(!s5.set_contains(0));
	assert(!s5.set_contains(-5));
	std::cout << "Displaying the complement of set 1 to set 2: " << s5 << std::endl;

	set s7 = difference(s2, s1);
	assert(s5.set_contains(4));
	assert(!s5.set_contains(0));
	assert(!s5.set_contains(-5));
	std::cout << "Displaying the complement of set 2 to set 1: " << s5 << std::endl;

	assert(subset(s5, s1));

	set s6(s2);
	assert(s6 == s2);
	std::cout << "all tests passed" << std::endl;
	
	std::cout << "Testing remove function, by removing 34 from set 1: " << std::endl;
	s1.set_remove(34);
	std:: cout << s1 << std::endl;
	
	std::cout << "Testing contains function, by checking to s see if set 1 contains 89: " << std::endl;
	if(s1.set_contains(89))
	{
		std::cout << "Test Passed" << std::endl;
	}
	
	std::cout << "Set 1 size is: " << s1.size() << std::endl;
	
	set s8(s2);
	std::cout << "Testing copy constructor, by set 2: " << "set 2 contains " << s2 << "now the new set contains " << s8 <<std::endl;
	
	set set_assigned = s2;
	std::cout << "Testing operator = :" << set_assigned << "equal to " << s2 << std::endl;
	 
	return 0;
}
