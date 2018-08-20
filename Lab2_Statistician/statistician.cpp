/* Jason Walters
 * Data Structures 
 * Tues Thurs 10am
 */


#include "statistician.h"
#include <iostream>
#include <cmath>
#include "assert.h"

statistician::statistician() 
{
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

void statistician:: next(double r)
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
        if(r<tinyest)
            tinyest =r;
        if(r>largest)
            largest =r;
    }
}
void statistician::reset()
{
    count = 0;
    total = 0;
    tinyest = 0;
    largest = 0;
}

int statistician::length() const
{
  return count;  
}

double statistician::sum() const
{
    return total;
}

double statistician::mean() const
{
    assert(length() > 0);
    return sum() / count;
}

double statistician::minimum() const
{
    assert(length() > 0);
    return tinyest;
}

double statistician::maximum() const
{
    assert(length() > 0);
    return largest;
}


