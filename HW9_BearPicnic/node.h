#ifndef NODE_H
#define NODE_H
#include <iostream>

// C++ program to evaluate an expression tree
#include <bits/stdc++.h>
using namespace std;

// Class to represent the nodes of syntax tree
class node
{
public:
    
    node(string x);
    string info;
    node *left = NULL, *right = NULL;
};

int eval(node* root);
int toInt(string s);

#endif // NODE_H