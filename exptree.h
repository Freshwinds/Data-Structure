#ifndef EXPTREE_H_INCLUDED
#define EXPTREE_H_INCLUDED
#include<iostream>
#include<stack>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=100;
struct ExprTreeNode{
    char dataitem;
    ExprTreeNode *left,*right;
};
void InitExprTreeNode ( ExprTreeNode *&root, char elem,struct ExprTreeNode *leftPtr, struct ExprTreeNode *rightPtr );
void InitExprTree( ExprTreeNode *&root );
void DeExprTree( ExprTreeNode *&root );
void build( ExprTreeNode *&root );
void expression( ExprTreeNode *root );
float evaluate( ExprTreeNode *root );
float calculate(char s,float a,float b);
void clears( ExprTreeNode *&root );
void showStructure( ExprTreeNode *root );
int IsOperator(char s);
int getope(char s);
ExprTreeNode *ExprTreeNodeCode(ExprTreeNode *root);
void commute(ExprTreeNode *&root);//表达树的交换律
//void showSub( ExprTreeNode *root, ExprTreeNode *p, int level );


#endif // EXPTREE_H_INCLUDED
