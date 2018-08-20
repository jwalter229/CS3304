#include "node.h"
node::node(string x)
{
	info = x;
}
// function to return the integer value
// of a given string
int toInt(string s)
{
    int num = 0;
    for (int i=0; i<s.length();  i++)
        num = num*10 + (int(s[i])-48);
    return num;
}

// This function receives a node of the syntax tree
// and recursively evaluates it
// start of eval
int eval(node* root)
{
    // empty tree
    if (!root)
        return 0;
 
    // leaf node i.e, an integer
    if (!root->left && !root->right)
        return toInt(root->info);
 
    // evaluating left subtree
    int left_val = eval(root->left);
 
    // evaluating right subtree
    int right_val = eval(root->right);
 
    // checking which operator to apply
	
	// + operator
    if (root->info == "+")
        return left_val + right_val;
	
	// - operator
    if (root->info == "-")
        return left_val - right_val;
	
	// * operator
    if (root->info == "*")
        return left_val * right_val;
	
	// dividing left_val by right_val
    return left_val / right_val;
	
}// end of eval
