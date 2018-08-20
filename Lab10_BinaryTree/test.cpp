#include <stdio.h>
#include "bst.h"
#include "bintree.h"
#include <iostream>

using namespace std;

int main()
{
	string data[] = {"blueberry", "peach", "apricot", "pear", "cherry", "mango", "papaya"};
    int size = 7;
    binary_search_tree<string> bst1;
    for (int i = 0; i < size; ++i) {
        bst1.insert(data[i]);
        cout << bst1 << endl;
    }
	
	print(bst1.get_root(), 4);
	
	
	
	string data2[] = {"now", "even", "think", "back", "its", "over", "want", "also", "come", "give", "most", "other", "then", "us", 
	"well", "after", "any", "because", "day", "first", "how", "look", "new", "only", "our", "than", "these", "two",
	"use", "way", "work"};
    int size2 = 31;
    binary_search_tree<string> bst2;
    for (int i = 0; i < size2; ++i) {
        bst2.insert(data2[i]);
        cout << bst2 << endl;
    }
	
	print(bst2.get_root(), 4);
}
