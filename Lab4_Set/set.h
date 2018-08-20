/*		Jason Walters
		Data Structures
		Tuesday - Thursday
		10 - 1215
*/

#ifndef SET_H
#define SET_H
#include <cstdlib>

class set
{
public:
	
    typedef int value_type;
	typedef std::size_t size_type;
	
    //setting default size
	static const size_type DEFAULT_CAPACITY = 30;
    
	
    set(size_type start_capacity = DEFAULT_CAPACITY);
    set(const set& source);
    ~set();
    
	//setting declarations for the functions
	
	//declaring fucntion contains
    bool includes(const value_type& target);
    //declaring funciton reserve
	void reserve(size_type new_capacity);
	//declaring clear funcion
    bool clear(const value_type& target);
	//declaring insert function
    void insert(const value_type& entry);
    size_type size() const;
    
    void operator =(const set& source);
    void operator +=(const set& addend);
	
private:
    value_type *data;
    size_type used;
    size_type capacity;
    
    size_type get_index(const value_type& target);
};

#endif // SET_H