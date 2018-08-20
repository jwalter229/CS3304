
/*		Jason Walters
		Data Structures
		Tuesday - Thursday
		10 - 1215
*/

// FILE: poly0.cpp
#include "poly0.h"
#include <iostream>

namespace main_savitch_3
{
//	PRECONDITION: exponent <= MAX_EX.
//	POSTCONDITION: This polynomial has been create with all zero
// 	coefficients, except for coefficient c for the specified exponent.
//	When used as a default constructor (using default values for
//	both arguments), the result is a polynomial with all zero
//	coefficients.
polynomial::polynomial(double c, unsigned int exponent)
{
	capacity = exponent + 1;
	max_expo = exponent;
	//coef = coefficient;
	coef = NULL;
        
	if(capacity > 0)
	{
	coef = new double[capacity];
	//for loop to populate the array
	for(int idx = 0; idx < capacity; ++idx)
	{
		coef[idx] = 0.0;
	}
		coef[max_expo] = c;
	}
		compute_degree();
    }//end of constructor
	
//setting constructor
polynomial::polynomial(const polynomial& source)
{
	current_degree = source.current_degree;
	capacity = source.capacity;
	max_expo = source.max_expo;
	coef = NULL;
	//if capacity is greater than 0
	if(capacity > 0)
	{
		coef = new double[capacity];
		//if idx less than capacity
		for(int idx = 0; idx < capacity; ++idx)
		{
			coef[idx] = source.coef[idx];
		}
	}
}//end of construtor
	
	
//deconstructor to clear coef varialbe
polynomial::~polynomial()
{	//clearning coef using delete[] 
	delete[ ] coef;
}
    
//start of compute_degree function  
void  polynomial::compute_degree()
{
	current_degree = previous_term(capacity);
    if(current_degree == UINT_MAX)
	current_degree = 0;
}//end of compute_degree function
    
//start of add_to_coef function
//PRECONDITION: exponent <= MAX_EX.
//POSTCONDITION: Adds the given amount to the coefficient of the specified exponent.
void polynomial::add_to_coef(double amount, unsigned int exponent)
{   
	if(exponent > max_expo)
	{
		return;
	}
        coef[exponent] += amount;
        compute_degree();
	}

//start of assign_coef function
//POSTCONDITION: Sets the coefficient for the specified exponent
void polynomial::assign_coef(double coefficient, unsigned int exponent)
{
	if(exponent > max_expo)
	{
		//needing a larger array
		double *co = new double [exponent + 1];
		//initialized the new coeff array 
		for(int idx = 0; idx < exponent; ++idx)
		{
			co[idx] = 0.0;
		}   //copying current coef array 
            //filling the data into the new one
			for(int jdx = 0; jdx < capacity; ++jdx)
			{
				co[jdx] = coef[jdx];
			}
		//adding the last coefficient from the parameter variable
		co[exponent] = coefficient;
		
        delete[] coef;
        coef = co;
		
        max_expo = exponent;
		capacity = max_expo + 1;
	}
        else
		{
			coef[exponent] = coefficient;
        }
        compute_degree();
}//end of assign_coef function

//start of clear function
//POSTCONDITON: All coefficients are set to zero
void polynomial::clear( )
{
	for(unsigned int idx = 0; idx < capacity; ++idx)
		{
            coef[idx] = 0;
        }
        current_degree = 0;
}//end of clearning function


//start of coefficient function
//POSTCONDITION: Returns coefficient at specified exponent of this polynomial.
//*****IMPORTANT: for exponents > MAX_EX, the return value is always zero.
double polynomial::coefficient(unsigned int exponent) const
{
	if(exponent > max_expo)
	{
		return 0.0;
	}
		return coef[exponent];
}//end of coefficient function


//start of next_term fuinciton
//POSTCONDITION: The return value is the next exponent n which is LARGER
//than e such that coefficient(n) != 0.
//If there is no such term, then the return value is zero.
unsigned int polynomial::next_term(unsigned int e) const
{
//  if( e > max_expo)
//  {
//      return 0.0;
//  }
//  unsigned int next_exop, i;
//  idx = e + 1;
//  next_exop = 0;
    if(e >= max_expo)
	{
		return 0.0;
	}
	for(unsigned int idx = e + 1; idx < capacity; ++idx)
	{   
		if(coef[idx] != 0)  //coef[idx] not equal to 0 
			return idx;     //return idx 
	}
		return 0;
}//end of next_term


//start of eval function
//POSTCONDITION: The return value is the value of this polynomial with the
//given value for the variable x.
double polynomial::eval(double x) const
{
	double answ = 0;
	
	for(int idx = max_expo; idx >= 0; --idx)
	{
		answ += (pow(x,idx) * coef[idx]);
	}
		return answ;
}//end of eval function

//start of pervious_term function
//POSTCONDITION: The return value is the next exponent n which is SMALLER
//than e such that coefficient(n) != 0.
//If there is no such term, then the return value is UINT_MAX
//from <climits>.
unsigned int polynomial::previous_term(unsigned int e) const
{
//    COME BACK TO THIS SECTION OF CODE
//    THINK ABOUT IT AND COME BACK TO IT
//    unsigned int idx, prev_exop:
//    prev_exop = UINT_MAX;
//    if(e == 0)
//    {
//        return prev_exop;
//    }
//    if (e > capacity)
//        e = capacity;
//    idx = 0;
//    
//    while (idx < e)
//    {
//        if(coef[idx] !0)
//        {
//            prev_exop = idx;
//        }
//        ++i;
//    }
//    return prev_exop;
    if(e == 0 || max_expo == 0) //if e or max_expo equal to 0
	{
		return UINT_MAX; //return UINT_MAX
	}
		if(e > max_expo) //e > max_expo
        {
            e = max_expo + 1;
        }
        if(e == 1)
        {
		if(coef[0] == 0)
		{
			return UINT_MAX;
		}
		else
			{
                return 0;
			}
        }
        for(unsigned int idx = e - 1; idx > 0; --idx)
        {
                if(coef[idx] != 0)
                    return idx;
        }
        return UINT_MAX;
}//end of pervious_term function

//start of size function
unsigned int polynomial::size() const
{
	return capacity;
}//end of size function

//start of operator -
//POSTCONDITION: return-value is a polynomial with each coefficient
//equal to the difference of the coefficients of p1 & p2 for any given
//exponent.
polynomial operator -(const polynomial& p1, const polynomial& p2)
{
	int poly_size = 0;
	if(p1.size() >= p2.size())
	{
		poly_size = p1.size();
	}
	else
		{
			poly_size = p2.size();
		}
        polynomial poly_nom(0,poly_size - 1);
        
        for(int idx = poly_size - 1; idx >= 0; --idx)
		{
            poly_nom.assign_coef(p1.coefficient(idx) - p2.coefficient(idx),idx);
        }
			return poly_nom;
}//end of operator -

//start of operator + 
//POSTCONDITION: return-value is a polynomial with each coefficient
//equal to the sum of the coefficients of p1 & p2 for any given
//exponent.
polynomial operator +(const polynomial& p1, const polynomial& p2)
{
	int poly_size = 0;
	if(p1.size() >= p2.size())
	{
		poly_size = p1.size();
	}
	else
		{
            poly_size = p2.size();
        }
        polynomial poly_nom(0, poly_size - 1);
        
        for(int idx = poly_size - 1; idx >= 0; --idx)
		{
            poly_nom.assign_coef(p1.coefficient(idx),idx);
            poly_nom.add_to_coef(p2.coefficient(idx),idx);
        }
			return poly_nom;
}//end of operator +

//start of operator *
//PRECONDITION: p1.degree( ) + p2.degree( ) <= polynomial::MAX_EX.
//POSTCONDITION: Each term of p1 has been multiplied by each term of p2,
//and the answer is the sum of all these term-by-term products.
//For example, if p1 is 2x^2 + 3x + 4 and p2 is 5x^2 - 1x + 7, then the
//return value is 10x^4 + 13x^3 + 31x^2 + 17x + 28.
polynomial operator *(const polynomial& p1, const polynomial& p2)
{
	polynomial poly_nom(0,p1.size() + p2.size() - 2);
	for(int idx = p2.size(); idx >= 0; --idx)
	{
    //int exp = i;
    //double product = 0.0;
		for(int jdx = p1.size(); jdx >= 0; --jdx)
		{
			if(jdx == 0)
			{
				poly_nom.add_to_coef(p1.coefficient(jdx) * p2.coefficient(idx),idx);
			}   
			else
			{
				poly_nom.add_to_coef(p1.coefficient(jdx) * p2.coefficient(idx), idx + jdx);
			}
		}
	}
		return poly_nom;
}//end of operator *

//start of operator <<
//POSTCONDITION: The polynomial has been printed to ostream out, which,
//in turn, has been returned to the calling function.
std::ostream& operator <<(std::ostream& out, const polynomial& poly_nom)
{
	for(int idx = poly_nom.size() - 1; idx > 0; --idx)
	{
		out <<  poly_nom.coefficient(idx) << "x^" << idx << " + ";
	}
		return out << poly_nom.coefficient(0) << "\n";
}//end of operator <<
	
	
	
}//end namespace