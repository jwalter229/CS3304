#include "stats2.h"
#include <iostream>
#include <cmath>
#include "assert.h"

statistician :: statistician() // creating the constructers  
{
    //setting private variables
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

void statistician :: next(double r)
{
    if(count == 0){
        //update the value of total, count,
        //tinyest, and largest
        total =r;
        count ++;
        tinyest =r;
        largest =r;
    }
    else{
        //update the value of total, count,
        //tinyest, and largest 
        total +=r;
        count +=1;
        //use if to update the tinyest and largest values
        if(r < tinyest)
            tinyest =r;
        if(r > largest)
            largest =r;
    }
}
void statistician :: reset()
{
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

//start of lenght method
int statistician :: length() const
{
  return count;  
}//end of length method

//start of sum method
double statistician :: sum() const
{
    return total;
}//end of sum method

//start of mean method
double statistician :: mean() const
{
    assert(length() > 0);
    return sum() / count;
}//end of mean method

//start of minimum method
double statistician :: minimum() const
{
    assert(length() > 0);
    return tinyest;
}// end of minimum method

//start of maximum method
double statistician :: maximum() const
{
    assert(length() > 0);
    return largest;
}//end of maximum method

//New code for lab3
//friend function
statistician operator + (const statistician& s1, const statistician& s2)
{   
    statistician result;

    if (s1.length() == 0) 
        return s2;
    
    if (s2.length() == 0) 
        return s1;
    
    result.count = s1.length() + s2.length();
    result.total = s1.length() * s1.mean() + s2.length() * s2.mean();
    if (s1.minimum() < s2.minimum()) 
    {   
        result.tinyest = s1.minimum();
    }
    else {
        result.tinyest = s2.minimum();
    }
    if (s1.maximum() > s2.maximum())
    {
        result.largest = s1.maximum();
    }
    else {
        result.largest = s2.maximum();
    }
    return result;
}
     
//     Postcondition: The statistician that is returned contains all the
//     numbers of the sequences of s1 and s2.
statistician operator *(double scale, const statistician& s)
{
    statistician result;

//  if (s.length() == 0)
//      return s;
//    
//  result.count = s.length();
//  result.total = scale * s.mean() * s.length();
//  result.tinyest = scale * s.minimum();
//  result.largest = scale * s.maximum();
    
    result.count = s.count;
    result.total = scale * s.total;
    
    if (scale >= 0)
    {
        result.tinyest = scale * s.tinyest;
        result.largest = scale * s.largest;
    }
    else {
        result.tinyest = scale * s.largest;
        result.largest = scale * s.tinyest;
    }
    
    return result;
    
}
//     Postcondition: The statistician that is returned contains the same
//     numbers that s does, but each number has been multiplied by the
//     scale number.
bool operator ==(const statistician& s1, const statistician& s2)
{
    if (s1.length() != s2.length())
        return false;
        
    if (s1.length() == 0)
        return true;
        
    return ((s1.mean() == s2.mean()) &&
            (s1.sum() == s2.sum())   &&
            (s1.minimum() == s2.minimum()) &&
            (s1.maximum() == s2.maximum())    );
}

