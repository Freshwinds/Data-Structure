#include "exptree.h"
void InitExprTreeNode (ExprTreeNode *&root, char elem,struct ExprTreeNode *leftPtr, struct ExprTreeNode *rightPtr )
{
    root->dataitem=elem;
    root->left=leftPtr;
    root->right=rightPtr;
}
void InitExprTree( ExprTreeNode *&root )//create an empty tree
{
    root->left=NULL;
    root->right=NULL;
}
void DeExprTree( ExprTreeNode *&root )//free
{
    if(root->left!=NULL){
        DeExprTree(root->left);
    }
    if(root->right!=NULL){
        DeExprTree(root->right);
    }
    delete(root);

}
float calculate(char s,float a,float b)
{
    float x=a;
    float y=b;
    switch(s)
    {
        case '+':return x+y;break;
        case '-':return x-y;break;
        case '*':return x*y;break;
        case '/':return x/y;break;
        default:break;
    }
}
int IsOperator(char s){
    if(s=='-'||s=='+'||s=='*'||s=='/') return 1;
    else return 0;
}
void build( ExprTreeNode *&root )//build a tree
{
    stack<ExprTreeNode*>nodeStack;
    char str[maxn];
    cin>>str;
    int i=strlen(str)-1;
    while(i>=0){
        if(IsOperator(str[i])){
            ExprTreeNode *p = new ExprTreeNode();
            InitExprTreeNode(p,str[i],NULL,NULL);
            p->left=nodeStack.top();
            nodeStack.pop();
            p->right=nodeStack.top();
            nodeStack.pop();
            nodeStack.push(p);
        }
        else{
             ExprTreeNode *child=new ExprTreeNode();
             InitExprTreeNode(child ,str[i],NULL,NULL);
             nodeStack.push(child);
            }
      i--;

    }
    root=nodeStack.top();

}
 int getope(char s){
    switch(s){
        case '(':return 0;break;
        case '+':return 1;break;
        case '-':return 1;break;
        case '*':return 2;break;
        case '/':return 2;break;
        default:return -1;break;
    }

}
void expression( ExprTreeNode *root )//output the tree in LNR order
{
    if(root)
    {
        if(root->left)
        {
            if(root->left->left&&root->left->right)
            {
                if(getope(root->dataitem)>getope(root->left->dataitem))
                    cout<<"(";
            }
        }
        expression(root->left);
        if(root->left)
        {
            if(root->left->left&&root->left->right)
            {
                if(getope(root->dataitem)>getope(root->left->dataitem))
                    cout<<")";
            }
        }

            cout<<root->dataitem;

        if(root->right)
        {
            if(root->right->left&&root->right->right)
            {
                if(getope(root->dataitem)>getope(root->right->dataitem))
                    cout<<"(";
            }
        }
        expression(root->right);
        if(root->right)
        {
            if(root->right->left&&root->right->right)
            {
                if(getope(root->dataitem)>getope(root->right->dataitem))
                    cout<<")";
            }
        }
    }

}
float evaluate( ExprTreeNode *root )//output the value of this expression
{
    if(!root->left&&!root->right) return (float)(root->dataitem-'0');
    return calculate(root->dataitem,evaluate(root->left),evaluate(root->right));
}
void clears( ExprTreeNode *&root )//delete the data
{
    while(root){
        clears(root->left);
        root->dataitem='0';
        clears(root->right);
    }
}
void showStructure( ExprTreeNode *root )//output from left to right
{
    if(root){
       showStructure(root->left);
       cout<<root->dataitem;
       showStructure(root->right);
    }
}
ExprTreeNode *ExprTreeNodeCode(ExprTreeNode *root){
    ExprTreeNode x;

    ExprTreeNode *p=&x;
    *p=*root;
    return p;
}

void commute(ExprTreeNode *&root)
{
    if(root){
        if(root->left&&root->right){
            ExprTreeNode *x,*y;
            x=root->left;
            y=root->right;
            root->right=x;
            root->left=y;
            commute(root->left);
            commute(root->right);
        }
    }
}
