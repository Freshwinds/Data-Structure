#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=1000;
int root[maxn];
struct Edge
{
    int v,u;
    int weights;
}edge[maxn];
bool compare(struct Edge a,struct Edge b)
{
    return a.weights<b.weights;
}
void Union(int x,int y,int n)
{
    int a=root[x];
    int b=root[y];
    if(a!=b)
    {
        root[b]=a;
        for(int i=1;i<=n;i++)
        {
            if(root[i]==b)
            {
                root[i]=a;
            }
        }
    }
}
void Kruskal(int n,int m)
{
    for(int i=1;i<=n;i++)
    {
        root[i]=i;
    }
    sort(edge,edge+m,compare);
    for(int i=0;i<m;i++)
    {
        if(root[edge[i].v]!=root[edge[i].u])
        {
            printf("%d->%d\n",edge[i].v,edge[i].u);
            Union(edge[i].v,edge[i].u,n);
        }
    }
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        scanf("%d %d %d",&edge[i].v,&edge[i].u,&edge[i].weights);

    }
    Kruskal(n,m);
    return 0;
}
