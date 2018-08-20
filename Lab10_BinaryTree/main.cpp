#include "bintree.h"
#include "build_tree.h"
#include <iostream>

using namespace std;

int main()
{

	binary_tree_node<int> *s1 = sample1();
	binary_tree_node<int> *s2 = sample2();
	binary_tree_node<double> *s3 = sample3();
	binary_tree_node<double> *s4 = sample4();


	cout << "Size of s1: " << tree_size(s1) << endl;
	cout << "Depth of s1: " << depth(s1) << endl;
	cout<< "Max of s1: " << max(s1) << endl;


	cout << "Size of s2: " << tree_size(s2) << endl;
	cout << "Depth of s2: " << depth(s2) << endl;
	cout << "Max of s2: " << max(s2) << endl;


	cout << "Size of s3: " << tree_size(s3) << endl;
	cout << "Depth of s3: " << depth(s3) << endl;
	cout << "Max of s3: " << max(s3) << endl;


	cout << "Size of s4: " << tree_size(s4) << endl;
	cout << "Depth of s4: " << depth(s4) << endl;
	cout << "Max of s4: " << max(s4) << endl;


	cout << endl;


	cout << "Sum of s3: " << tree_sum(s3) << endl;
	cout << "Average of s3: " << tree_average(s3) << endl;
	cout << "Size of s3: " << tree_size(s3) << endl;

	
	binary_tree_node<double> *b1 = sample_bal1();
	binary_tree_node<double> *b2 = sample_bal2();

	
	cout << "Sum of b1: " << tree_sum(b1) << endl;
	cout << "Average of b1: " << tree_average(b1) << endl;
	cout << "Size of b1: " << tree_size(b1) << endl;

	
	cout << "Sum of b2: " << tree_sum(b2) << endl;
	cout << "Average of b2: " << tree_average(b2) << endl;
	cout << "Size of b2: " << tree_size(b2) << endl;

	binary_tree_node<string> *s5 = sample5();


	cout << "s1 is balanced? " << tree_is_balanced(s1) << endl;
	cout << "s2 is balanced? " << tree_is_balanced(s2) << endl;
	cout << "s3 is balanced? " << tree_is_balanced(s3) << endl;
	cout << "s4 is balanced? " << tree_is_balanced(s4) << endl;
	cout << "s5 is balanced? " << tree_is_balanced(s5) << endl;
	cout << "b1 is balanced? " << tree_is_balanced(b1) << endl;
	cout << "b2 is balanced? " << tree_is_balanced(b2) << endl;

}// end of main

