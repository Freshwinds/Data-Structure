#include "wtgraph.h"
int  getIndex( WtGraph &G, char *v )
{
    for(int i=0;i<G.size;i++)
    {
        if(strcmp(G.verteist[i].label,v)==0)
            return i;
    }
    return -1;
}
int  Getedge( WtGraph G, int row, int col )
{
    return G.adjMatrix[row][col];
}
void setEdge( WtGraph &G, int row, int col, int wt )
{
    G.adjMatrix[row][col]=wt;
}
void InitWtGraph( WtGraph &G, int maxNumber )
{
    G.maxSize=maxNumber;
    G.size=0;
    G.verteist=new Vertex[maxNumber];
    G.adjMatrix=new int*[maxNumber];
    for(int i=0;i<maxNumber;i++)
        G.adjMatrix[i]=new int[maxNumber];
    for(int i=0;i<maxNumber;i++)
    {
        for(int j=0;j<maxNumber;j++)
            G.adjMatrix[i][j]=infiniteEdgeWt;
    }
     G.pathMaxtrix=new int*[maxNumber];
    for(int i=0;i<maxNumber;i++)
        G.pathMaxtrix[i]=new int[maxNumber];
    for(int i=0;i<maxNumber;i++)
    {
        for(int j=0;j<maxNumber;j++)
            G.pathMaxtrix[i][j]=infiniteEdgeWt;
    }

}
void DeWtGraph( WtGraph &G )
{
    if(G.verteist!=NULL)
        delete[]G.verteist;
    for(int i=0;i<G.maxSize;i++)
        delete []G.adjMatrix[i];
    delete[]G.adjMatrix;
    G.size=0;
    G.maxSize=0;
}
void insertVertex( WtGraph &G, Vertex newVertex )
{
    if(G.size==G.maxSize)
        return;
    int a=-1;
    for(int i=0;i<G.size;i++)
    {
        if(strcmp(G.verteist[i].label,newVertex.label)==0)
        {
            a=i;
        }
    }
    if(a!=-1)
    {
        strcpy(G.verteist[a].label,newVertex.label);
    }
    else
    {
        strcpy(G.verteist[G.size].label,newVertex.label);
        G.size++;
    }

}
void insertEdge( WtGraph &G, char *v1, char *v2, int wt )
{
    int a,b;
    a=getIndex(G,v1);
    b=getIndex(G,v2);
    G.adjMatrix[a][b]=G.adjMatrix[b][a]=wt;
    G.pathMaxtrix[a][b]=G.pathMaxtrix[b][a]=wt;

}
bool retrieveVertex( WtGraph G, char *v, Vertex &vData )
{
    for(int i=0;i<G.size;i++)
    {
        if(strcmp(G.verteist[i].label,v)==0)
        {
            strcpy(vData.label,G.verteist[i].label);
            return true;
        }
    }
    return false;
}
bool GetedgeWeight( WtGraph G, char *v1, char *v2, int &wt )
{
    int a,b;
    a=getIndex(G,v1);
    b=getIndex(G,v2);
    if(a==-1||b==-1)  return false;
    if(G.adjMatrix[a][b]!=infiniteEdgeWt)
    {
        wt=G.adjMatrix[a][b];
        return true;
    }
    return false;

}
void removeVertex( WtGraph &G, char *v)
{

    int a=getIndex(G,v);
    strcpy(G.verteist[a].label,"");
    for(int i=0;i<G.size;i++)
    {
        G.adjMatrix[i][a]=infiniteEdgeWt;
        G.adjMatrix[a][i]=infiniteEdgeWt;

    }
}
void removeEdge( WtGraph &G, char *v1, char *v2 )
{
    int a=getIndex(G,v1);
    int b=getIndex(G,v2);
    G.adjMatrix[a][b]=G.adjMatrix[b][a]=infiniteEdgeWt;
    G.pathMaxtrix[a][b]=G.pathMaxtrix[b][a]=infiniteEdgeWt;
}
void clear( WtGraph &G )
{
    for(int i=0;i<G.size;i++)
    {
        for(int j=0;j<G.size;j++)
            G.adjMatrix[i][j]=infiniteEdgeWt;
    }
    G.verteist=NULL;
    G.size=0;
}
bool isEmpty(WtGraph G)
{
    if(G.size==0)
        return true;
    else
        return false;
}
bool isFull( WtGraph G)
{
    if(G.size==G.maxSize)
        return true;
    else
        return false;
}
void showStructure(WtGraph G)
{
    if(isEmpty(G))
    {
        printf("Empty graph\n");
        return ;
    }
    printf("{");
    for(int i=0;i<G.size-1;i++)
        {
            printf("%s,",G.verteist[i].label);
        }
        printf("%s}\n",G.verteist[G.size-1].label);
    for(int i=0;i<G.size;i++)
    {
        for(int j=0;j<G.size;j++)
        {
            if(G.adjMatrix[i][j]==infiniteEdgeWt)
                printf("\t∞");
            else printf("\t%d",G.adjMatrix[i][j]);
        }
        printf("\n");
    }
    cout<<endl;
    for(int i=0;i<G.size;i++)
    {
        for(int j=0;j<G.size;j++)
        {
            if(G.pathMaxtrix[i][j]==infiniteEdgeWt)
                printf("\t∞");
            else printf("\t%d",G.pathMaxtrix[i][j]);
        }
        printf("\n");
    }
    cout<<endl;
    cout<<"color:{";
    for(int i=0;i<G.size-1;i++)
    {
        cout<<G.verteist[i].color<<",";
    }
    cout<<G.verteist[G.size-1].color<<"}"<<endl;
}
void computePaths(WtGraph &G)
{
    for(int i=0;i<G.size;i++)
    {
        for(int j=0;j<G.size;j++)
        {
            for(int k=0;k<G.size;k++)
            {
                if(i==j)
                {
                    G.pathMaxtrix[i][j]=0;
                    continue;
                }
                if(G.adjMatrix[i][j]>(G.adjMatrix[i][k]+G.adjMatrix[k][j]))
                {
                    G.pathMaxtrix[i][j]=G.adjMatrix[i][k]+G.adjMatrix[k][j];
                }
            }
        }
    }

}

bool hasProperColoring(WtGraph G)
{
    for(int i=0;i<G.size;i++)
    {
        for(int j=0;j<G.size;j++)
        {
            if(G.adjMatrix[i][j]!=infiniteEdgeWt&&G.verteist[i].color==G.verteist[j].color)
            {
                return false;
            }
        }
    }
    return true;
}
bool areAllEven(WtGraph G)
{
    for(int i=0;i<G.size;i++)
    {
        int cnt=0;
        for(int j=0;j<G.size;j++)
        {
            if(i!=j&&G.adjMatrix[i][j]!=infiniteEdgeWt)
            {
                cnt++;
            }

        }
         if(cnt%2)
            {
                return false;
            }
    }
    return true;
}
