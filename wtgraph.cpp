#include "testgraph.cpp"
void menu()
{
    cout<<"**********************MENU***********************"<<endl;
    cout<<"+v  :add vertex"<<endl;
    cout<<"=v w wt :add an edge value wt between w and w"<<endl;
    cout<<"?v : look up vertex v"<<endl;
    cout<<"#v w :look up the edge between v and w,input weight"<<endl;
    cout<<"-v :delete vertex v"<<endl;
    cout<<"!v w:delete the edge between v and w"<<endl;
    cout<<"E:judge whether the graph is empty"<<endl;
    cout<<"F:judge whether the graph is full"<<endl;
    cout<<"C:clear the graph"<<endl;
    cout<<"Q:quit "<<endl;
    cout<<"***************************************************"<<endl;

}
int main()
{
    WtGraph G;
    InitWtGraph(G,defMaxGraphSize);
    menu();
    char *order=new char[defMaxGraphSize];
    while(1)
    {
        cout<<"please input order:"
        gets(order);

        char *v=new char[defMaxGraphSize];
        char *w=new char[defMaxGraphSize];
        if(order[0]=='+')
        {

            //strncpy(v,order+1);
            sscanf(order,"+%s",v);
            Vertex a;
            strcpy(a.label,v);

            insertVertex(G,a);
            printf("success!\n");

        }
        else if(order[0]=='=')
        {
            int wwt;
            sscanf(order,"=%s %s %d",v,w,&wwt);
            insertEdge(G,v,w,wwt);
            printf("success!\n");
        }
        else if(order[0]=='?')
        {

            sscanf(order,"?%s",v);
            printf("%d\n",getIndex(G,v));
        }
        else if(order[0]=='#')
        {

            int wt;
            sscanf(order,"#%s %s",v,w);
            if(GetedgeWeight(G,v,w,wt))
            {
                printf("%d\n",wt);
            }

        }
        else if(order[0]=='-')
        {

            sscanf(order,"-%s",v);

            removeVertex(G,v);
            printf("success\n");
        }
        else if(order[0]=='!')
        {

            sscanf(order,"!%s %s",v,w);
            removeEdge(G,v,w);
            printf("success\n");
        }
        else if(order[0]=='E')
        {
            if(isEmpty(G))
                printf("the graph is empty\n");
            else
                printf("the graph is not empty\n");
        }
        else if(order[0]=='F')
        {
            if(isFull(G))
                printf("the graph is full\n");
            else
                printf("the graph is not full\n");
        }
        else if(order[0]=='C')
        {
            clear(G);
            printf("success\n");
        }
        else if(order[0]=='Q')
        {
            printf("Thank you for using\n");
            break;
        }
        else
        {
            printf("please input the right order\n");
        }
    }
    return 0;
}
