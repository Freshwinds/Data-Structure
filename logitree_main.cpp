#include "logitree.cpp"

int main()
{
    while(1)
    {
    struct LogiTreeNode *root =new LogiTreeNode();
    InitLogiTree(root);
    cout<<"expression:";
    build(root);
    cout<<"expression(mid):";
    expression(root);
    cout<<endl;
    cout<<"result:";
    cout<<evaluate(root)<<endl;
    DeLogiTree(root);
    }
    return 0;
}
