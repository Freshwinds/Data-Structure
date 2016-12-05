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
    cout<<"PM:input paths"<<endl;
    cout<<"C:clear the graph"<<endl;
    cout<<"R:color the vertex"<<endl;
    cout<<"H:judge whether the color of vertex is proper"<<endl;
    cout<<"D:judge whether the answer is always yes"<<endl;
    cout<<"S:show structure"<<endl;
    cout<<"Q:quit "<<endl;
    cout<<"***************************************************"<<endl;

}
int main()
{
    WtGraph G;
    //cout<<2<<endl;
    InitWtGraph(G,defMaxGraphSize);
    menu();
    //cout<<1<<endl;
    char *order=new char[defMaxGraphSize];
    while(1)
    {
        cout<<"please input order:";
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
        else if(order[0]=='S')
        {
            showStructure(G);

        }
        else if(order[0]=='P')
        {
            computePaths(G);
        }
        else if(order[0]=='R')
        {
            for(int i=0;i<G.size;i++)
            {
                cout<<"please input "<<i<<"th vertex point color:";
                cin>>G.verteist[i].color;
            }
            getchar();
        }
        else if(order[0]=='H')
        {
            if(hasProperColoring(G))
            {
                cout<<"the color is proper"<<endl;
            }
            else
            {
                cout<<"the color is not proper"<<endl;
            }
        }
        else if(order[0]=='D')
        {
            if(areAllEven(G))
            {
                cout<<"all degree is even number"<<endl;
            }
            else
            {
                cout<<"some degree is odd number"<<endl;
            }
        }
        else
        {
            printf("please input the right order\n");
        }
    }
    return 0;
}
