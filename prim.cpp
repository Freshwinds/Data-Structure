#include<stdio.h>
const int maxn=10000;
const int INF=0x3f3f3f3f3f;
bool use[maxn];//定义有没有使用
int adjcent[maxn];//最邻近的点
int lowcost[maxn];//到起始点的最短距离
int edge[maxn][maxn];//邻接矩阵
int n,m;
void init()
{
    for(int i=0;i<n;i++)
    {
        use[i]=false;
        lowcost[i]=INF;
        for(int j=0;j<n;j++)
        {
            edge[i][j]=INF;
        }
    }
    use[0]=true;

}
void prim()
{
    for(int i=0;i<n-1;i++)
    {
        int dis=INF;
        int dot=-1;
        for(int j=0;j<n;j++)
        {
            if(use[j]==false&&dis>lowcost[j])
            {
                dis=lowcost[j];
                dot=j;
            }

        }
        if(dot!=-1)
        {
            printf("%d->%d\n",adjcent[dot],dot);
            use[dot]=true;
            for(int j=0;j<n;j++)
            {
                if(use[j]==false&&edge[dot][j]<lowcost[j])
                {
                    lowcost[j]=edge[dot][j];
                    adjcent[j]=dot;
                }
            }
        }
    }
}
int main()
{

    scanf("%d %d",&n,&m);
    init();
    for(int i=0;i<m;i++)
    {
        int a,b,d;
        scanf("%d %d %d",&a,&b,&d);
        edge[a][b]=edge[b][a]=d;
    }
    for(int i=1;i<n;i++)
    {
        lowcost[i]=edge[i][0];
    }
    lowcost[0]=0;
    adjcent[0]=0;
    prim();
    return 0;
}
