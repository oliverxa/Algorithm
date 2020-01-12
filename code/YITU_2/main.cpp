#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <string.h>
#include <map>
#include <cmath>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define LL long long
using namespace std;

const int INF=0x3f3f3f3f;
const int MX=1000+10;


int n,m,Map[MX][MX],price[MX][MX],dis[MX],pre[MX];
void init(){
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++){
            Map[i][j]=INF;
            price[i][j]=0;
        }
}
void dijkstra(int v0){
    bool vis[MX];
    for (int i=1;i<=n;i++){
        dis[i]=Map[v0][i];
        pre[i]=price[v0][i];
        vis[i]=false;
    }
    dis[v0]=0;
    vis[v0]=true;
    for (int i=1;i<=n;i++){
        int tmp=INF,P=INF,u;
        for (int j=1;j<=n;j++)
            if (!vis[j]&&dis[j]<tmp){
                u=j;
                tmp=dis[j];
            }
        vis[u]=true;
        for (int j=1;j<=n;j++)
            if (!vis[j]){
                if (dis[u]+Map[u][j]<dis[j]){
                    dis[j]=dis[u]+Map[u][j];
                    pre[j]=pre[u]+price[u][j];
                }else if (dis[u]+Map[u][j]==dis[j]&&pre[u]+price[u][j]>pre[j])
                    pre[j]=pre[u]+price[u][j];
            }

    }
}
int main(){
    while (~scanf ("%d %d",&n,&m)){
        if (n==0&&m==0) break;
        init();
        int a[n];
        int s,t;
        cin >> s >> t;
        for(int i=1; i<=n; i++){
            cin >> a[i];
        }
        //memset(price, 0, sizeof(price));
        while (m--){
            int u,v,w;
            cin >> u >> v >> w;
            //scanf ("%d %d %d %d",&u,&v,&w);
            if (Map[u][v]>w){
                Map[u][v]=w;
                Map[v][u]=w;
                price[u][v]=a[v];
                price[v][u]=a[v];
            }else if (Map[u][v]==w&&price[u][v]<a[v]){
                price[u][v]=a[v];
                price[v][u]=a[v];
            }
        }

        dijkstra(s);
        printf ("%d %d\n",dis[t],pre[t]+a[s]);
    }
    return 0;
}
