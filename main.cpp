#include "exptree.cpp"
int main()
{
    cout<<"welcome!"<<endl;

    cout<<"************MENU**************"<<endl;
    cout<<"***  C:create an ExprTree  ***"<<endl;
    cout<<"***  D:copy the ExprTree   ***"<<endl;
    cout<<"***  M:mid-expression      ***"<<endl;
    cout<<"***  E:exchange subtree    ***"<<endl;
    cout<<"***  S:show the struct     ***"<<endl;
    cout<<"***  F:free memory         ***"<<endl;
    cout<<"***  R:clear data          ***"<<endl;
    cout<<"******************************"<<endl;
    struct ExprTreeNode *root=new ExprTreeNode();
    InitExprTree(root);
    while(1)
    {
        cout<<"please input order:";
        char s;
        cin>>s;
        getchar();
        if(s=='C'){
            cout<<"expression:";
            build(root);
        }
        else if(s=='D'){
            ExprTreeNode *p=new ExprTreeNode();
            p=ExprTreeNodeCode(root);
            cout<<"p has been created"<<endl;
        }
        else if(s=='M'){
            expression(root);
            cout<<endl;
        }
        else if(s=='E'){
            commute(root);
        }
        else if(s=='S'){
            showStructure(root);
        }
        else if(s=='F'){
            DeExprTree(root);
        }
        else if(s=='R'){
            clears(root);
        }
        else{
            cout<<"please give me a right order"<<endl;
                break;
        }

    }
    return 0;
}
