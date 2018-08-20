#include <iostream>
#include "table1.h"
#include <cassert>

using namespace std;
using namespace main_savitch_12A;

struct record_type
{
    int key;
    string value;
};

int main() {
    table<record_type> t1;
//same hash worst case
    for(int i=0; i<1024; i++) {
        record_type r1;
        r1.key=i*1024;
        r1.value="This is value for key " + to_string(i);
        t1.insert(r1);
    }
    assert(t1.size()==1024);

    for(int i=0; i<1024; i++) {

        t1.remove(i*1024);
        record_type myR;
        bool found;
        t1.find(i,found,myR);
        assert(!found);
    }

    assert(t1.size()==0);

    //double duplicates of each
    for(int i=0; i<2048; i+=2) {
        record_type r1;
        r1.key=i;
        r1.value="This is value for key " + to_string(r1.key);
        t1.insert(r1);

        record_type myR;
        bool found;
        t1.find(i,found,myR);
        assert(found);

    }
    assert(t1.size()==1024);

    for(int i=0; i<2048; i+=2) {
        t1.remove(i);

        record_type myR;
        bool found;
        t1.find(i,found,myR);
        assert(!found);
    }
    assert(t1.size()==0);

    //best case
    for(int i=0; i<1024; i++) {
        record_type r1;
        r1.key=i;//200 unique numbers
        r1.value="This is value for key " + to_string(r1.key);
        t1.insert(r1);

        record_type myR;
        bool found;
        t1.find(i,found,myR);
        assert(found);

    }
    assert(t1.size()==1024);

    for(int i=0; i<1024; i++) {
        t1.remove(i);

        record_type myR;
        bool found;
        t1.find(i,found,myR);
        assert(!found);
    }
    assert(t1.size()==0);

    cout<<"All Test passed";

    return 0;
}
