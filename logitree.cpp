#include "logitree.h"
void InitLogiTreeNode(LogiTreeNode *&root, char elem,struct LogiTreeNode *leftPtr, struct LogiTreeNode *rightPtr )
{
    root->dataitem=elem;
    root->left=leftPtr;
    root->right=rightPtr;
}
void InitLogiTree( LogiTreeNode *&root )//create an empty tree
{
    root->left=NULL;
    root->right=NULL;
}
void DeLogiTree( LogiTreeNode *&root )//free
{
    if(root->left!=NULL){
        DeLogiTree(root->left);
    }
    if(root->right!=NULL){
        DeLogiTree(root->right);
    }
    delete(root);

}
int calculate1(char s,int a){
    return (1-a);
}

int calculate2(char s,int x,int y)
{
    switch(s)
    {
        case '+':
            if(x==0&&y==0)
                return 0;
            else
                return 1;
            break;
        case '*':
            if(x==1&&y==1)
                return 1;
            else
                return 0;
            break;

        default:break;
    }
}
int IsOperator(char s){
    if(s=='-'||s=='+'||s=='*'||s=='/') return 1;
    else return 0;
}
void build( LogiTreeNode *&root )//build a tree
{
    stack<LogiTreeNode*>nodeStack;
    char str[maxn];
    cin>>str;
    int i=strlen(str)-1;
    while(i>=0){
        if(IsOperator(str[i])){
            LogiTreeNode *p = new LogiTreeNode();
            InitLogiTreeNode(p,str[i],NULL,NULL);
            if(str[i]=='-')
            {
                p->right=nodeStack.top();
                nodeStack.pop();
                nodeStack.push(p);
            }
            else
            {
            p->left=nodeStack.top();
            nodeStack.pop();
            p->right=nodeStack.top();
            nodeStack.pop();
            nodeStack.push(p);
            }
        }
        else{
             LogiTreeNode *child=new LogiTreeNode();
             InitLogiTreeNode(child ,str[i],NULL,NULL);
             nodeStack.push(child);
            }
      i--;

    }
    root=nodeStack.top();

}
 int getope(char s){
    switch(s){
        case '*':return 1;break;
        case '+':return 0;break;
        case '-':return 2;break;
        default:return -1;break;
    }

}
void expression( LogiTreeNode *root )//output the tree in LNR order
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
                if(getope(root->dataitem)>getope(root->right->dataitem)||root->dataitem=='-')
                    cout<<")";
            }
        }
    }

}
int evaluate( LogiTreeNode *root )//output the value of this expression
{
    if(!root->left&&!root->right) return (float)(root->dataitem-'0');
    if(root->dataitem=='-') return calculate1(root->dataitem,evaluate(root->right));
    return calculate2(root->dataitem,evaluate(root->left),evaluate(root->right));
}
void clears( LogiTreeNode *&root )//delete the data
{
    while(root){
        clears(root->left);
        root->dataitem='0';
        clears(root->right);
    }
}
void showStructure( LogiTreeNode *root )//output from left to right
{
    if(root){
       showStructure(root->left);
       cout<<root->dataitem;
       showStructure(root->right);
    }
}

/*void showSub( LogiTreeNode *root, LogiTreeNode *p, int level )//
{

}*/
