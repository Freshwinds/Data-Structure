#ifndef LOGITREE_H_INCLUDED
#define LOGITREE_H_INCLUDED
#ifndef EXPTREE_H_INCLUDED
#define EXPTREE_H_INCLUDED
#include<iostream>
#include<stack>
#include<stdio.h>
#include<cstring>
using namespace std;
const int maxn=100;
struct LogiTreeNode{
    char dataitem;
    LogiTreeNode *left,*right;
};
void InitLogiTreeNode ( LogiTreeNode *&root, char elem,struct LogiTreeNode *leftPtr, struct LogiTreeNode *rightPtr );
void InitLogiTree( LogiTreeNode *&root );
void DeLogiTree( LogiTreeNode *&root );
void build( LogiTreeNode *&root );
void expression( LogiTreeNode *root );
int evaluate( LogiTreeNode *root );
int calculate1(char s,int a);
int calculate2(char s,int x,int y);
void clears( LogiTreeNode *&root );
void showStructure( LogiTreeNode *root );
int IsOperator(char s);
int getope(char s);
//void showSub( LogiTreeNode *root, LogiTreeNode *p, int level );


#endif // EXPTREE_H_INCLUDED



#endif // LOGITREE_H_INCLUDED
