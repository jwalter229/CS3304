/*		Jason Walters
		Data Structures
		Tuesday - Thursday
		10 - 1215
*/

#include <cassert>
#include <algorithm>
#include "set.h"

//setting constructor 
set::set(size_type start_capacity)
{	
    capacity = start_capacity;
    used = 0;
    data = new value_type[start_capacity];
}

set::set(const set& source)
{
    data = new value_type[source.capacity];
    capacity = source.capacity;
    used = source.used;
    std::copy(source.data, source.data + used, data);
}

//set deconstructor 
set::~set()
{	//clearing data memory
    delete [] data;
}

//creating body of the functions named in the .h file

//start of includes functions
bool set::includes(const value_type& target)
{
    for (size_type i = 0; i < used; ++i)
    {
        if (data[i] == target)
        {
            return true;
        }
    }
    return false;
}//end of includes function

//start of reserve function
void set::reserve(size_type new_capacity)
{
    value_type *new_data;
    
    if (new_capacity == capacity)
        return;
    if (new_capacity < used)
        new_capacity = used;
    
    new_data = new value_type[new_capacity];
    std::copy(data, data + used, new_data);
    delete [] data;
    data = new_data;
    capacity = new_capacity;
}//end of reserve

//start of get_index function
set::size_type set::get_index(const value_type& target)
{
    size_type index = 0;
    if (includes(target))
    {
        while (index < used)
        {
            if (data[index] == target)
                return index;
            ++index;
        }
        
    }
//    else
//        return -1;
}//end of get_index function

//start of clear function
bool set::clear(const value_type& target)
 {
    if (includes(target))
    {
        data[get_index(target)] = data[used];
        --used;
    }
//	else
//		return false;
}//end of clear function


//start of set function 
void set::insert(const value_type& entry)
{
    if (!includes(entry))
    {
        if (used == capacity)
            reserve(used + 1);
        data[used] = entry;
        ++used;
    }
}//end of set function

//start of +=  operator function
void set::operator +=(const set& addend)
{
    if (used + addend.used > capacity)
        reserve(used + addend.used);
    
    std::copy(addend.data, addend.data + addend.used, data + used);
    used += addend.used;
}//end of += operator function

//start of = function
void set::operator =(const set& source)
{
    value_type *new_data;
    if (this == &source)
        return;
        
    if (capacity != source.capacity)
    {
        new_data = new value_type[source.capacity];
        delete [] data;
        data = new_data;
        capacity = source.capacity;
    }
    
    used = source.used;
    std::copy(source.data, source.data + used, data);
}// end of = function

set::size_type set::size() const
{
    return used;
}