#include <iostream>
#include <string.h>
#define maxn 1010
#define ki 900000000
using namespace std;
int n,m;
bool visit[maxn];
int road[maxn][maxn], dis[maxn], dcake[maxn];
int cake[maxn][maxn];

void Dijkstra(int src)
{
    int temp,k;
    memset(visit,false,sizeof(visit));
    for(int i=1;i<=n;i++)
    {
        dis[i]=road[src][i];
        dcake[i]=cake[src][i];
    }
    visit[src]=true;
    for(int i=1;i<=n;i++)
    {
        temp=ki;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j] && temp>dis[j])
                temp=dis[k=j];
        }
        if(temp==ki)
            break;
        visit[k]=true;
        for(int j=1;j<=n;j++)
        {
            if(!visit[j]&&dis[j]>dis[k]+road[k][j])
            {
                dis[j]=dis[k]+road[k][j];
                dcake[j]=dcake[k]+cake[k][j];
            }
            else if(!visit[j]&&dis[j]==dis[k]+road[k][j])
            {
                if(dcake[j]<dcake[k]+cake[k][j])
                {
                    dcake[j]=dcake[k]+cake[k][j];
                }
            }
        }
    }

}

int main()
{
    //int n,m,s,d;
    int s,d;
    cin >> n >> m >> s >> d;
    //int cake[n];
    //int road[n][n];
    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                road[i][j]= ki;
            }
            //cake[i] = 0;

    }
    int cakes[n];

    for(int i=0; i<n; i++){
        cin >> cakes[i];
    }
    int a, b, cost;
    for(int i=0; i<m; i++){
        cin >> a >> b >> cost;
        if(cost < road[a][b]){
            road[a][b] = cost;
            cake[a][b] = cake[b][a] = cakes[b];
        }
    }
    Dijkstra(s);


    cout << dis[d] << dcake[d];
    return 0;
}
