/*
	jason walters
	datastrutures 
	tues - thrus 10 -1215
*/

#include "sequence.h"
#include <cassert>

namespace main_savitch_3
{
    sequence::sequence()
    {
        used = 0;
        current_index = 0;
    }
    
    bool sequence::is_item() const
    {
        if (current_index < used)
        {
            return true;
        }
        return false;
    }
    
    sequence::size_type sequence::size() const
    {
        return used;
    }
    
    void sequence::start()
    {
        current_index = 0;
    }
    
    void sequence::advance()
    {
        assert(is_item());
        current_index += 1;
    }
    
    void sequence::remove_current()
    {
        assert(is_item());
        sequence::size_type i;
        i = current_index;
        while (i < size())
        {
            data[i] = data[i+1];
            ++i;
        }
        used -= 1;
    }
    
    sequence::value_type sequence::current() const
    {
        assert(is_item());
        return data[current_index];
    }
    
    void sequence::insert(const value_type& entry)
    {
        assert(size() < CAPACITY);
        if (!is_item())
        {
            start();
        }
        if (size() > 0)
        {
            sequence::size_type i, j;
            i = size();
            j = ( (is_item())? current_index : 0 );
            
            while (i > j)
            {
                data[i] = data[i-1];
                --i;
            }
        }
        
        data[current_index] = entry;
        ++used;
    }
    
    void sequence::attach(const value_type& entry)
    {
         assert(size() < CAPACITY);
         if ( (size() <= 1) || (!is_item()) || (current_index == used - 1) )
         {
             current_index = size();
         }
         else
         {
             sequence::size_type i, j;
             i = size();
             j = current_index + 1;
             while (i > j)
             {
                 data[i] = data[i-1];
                 --i;
             }
             ++current_index;
         }
         
         data[current_index] = entry;
         ++used;
    }
    
}