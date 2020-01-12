#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3f3f3f3f;

int n, G[MAXV][MAXV];
int d[MAXV]; //顶点与集合S的最短距离
bool vis[MAXV] = {false};

int prim(){
    fill(d, d+MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int u = -1, MIN = INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }
        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];
        for(int v=0; v<n; v++){
            if(vis[v] == false && G[u][v]!=INF && G[u][v] < d[v]){
                d[v] = G[u][v];
            }
        }
    }
    return ans;
}

int main()
{
    int u, v, w;
    scanf("%d%d", &n, &m);// n 是顶点 m 是边数
    fill(G[0], G[0] + MAXV*MAXV, INF);
    for(int i=0; i<m; i++){
        scanf("%d%d%d", &u, &v, &w);
        G[u][v] = G[v][u] = w;
    }
    int ans = prim();
    prim("%d\n", ans);
    return 0;
}
