#ifndef STACK_PAIR_H
#define STACK_PAIR_H

#include <cstdlib>   // Provides NULL and size_t and NULL


template <class T>
class stack_pair
{
public:
    // TYPEDEFS
	typedef std::size_t size_type;
	typedef T value_type;
	static const size_type CAPACITY = 30;
	
        // CONSTRUCTORS
        stack_pair( );
	
        // MODIFICATION MEMBER FUNCTIONS
		T pop_a();
		T pop_b();

		void push_a(T item);
		void push_b(T item);

        bool is_empty_a(){ return top_a == 0; }
		bool is_empty_b(){ return top_b == 29; }
		
		bool is_full_a(){ return used == 30; }
		bool is_full_b(){ return used == 30; }
        // CONST MEMBER FUNCTIONS
        
        size_t size_a() const { return many_elements_a; }
		size_t size_b() const { return many_elements_b; }
		
private:
        T data[CAPACITY];
		size_type top_a;
		size_type top_b;
		
		size_type many_elements_a;
		size_type many_elements_b;
		
		size_type used;
};

// NONMEMBER functions for the bag

// The implementation of a template class must be included in its header file:
#include "stack_pair.template"


#endif 
