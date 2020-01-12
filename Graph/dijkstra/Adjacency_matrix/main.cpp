#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

int n, G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV]; //记录先前节点
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d, d+MAXV, INF);

    for(int i=0; i<n; i++) pre[i] = i; //初始化先前节点

    d[s] = 0;
    for(int i=0; i<n; i++){
        int u=-1, MIN = INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j] < MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return;

        vis[u] = true;
        for(int v=0; v<n; v++){
            if(vis[v] == false && G[u][v] != INF && d[u]+G[u][v] < d[v]){
                d[v] = d[u] + G[u][v];

                pre[v] = u; //标记前驱节点
            }
        }
        /* 增加一个cost 尽可能少
        for(int v=0; v<n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    c[v] = c[u] + cost[u][v];
                }else if(d[u] + G[u][v] == d[v] && c[u] + cost[u][v] < c[v]){
                    c[v] = c[u] + cost[u][v];
                }

            }
        }
        */

        /* 增加一个weight 尽可能多
        for(int v=0; v<n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    w[v] = w[u] + weight[u][v];
                }else if(d[u] + G[u][v] == d[v] && w[u] + weight[v] > w[v]){
                    w[v] = w[u] + weight[v];
                }

            }
        }
        */

        /*计算最短路径的条数
        memset(num, 0, sizeof(num));
        num[s] = 1;

        for(int v=0; v<n; v++){
            if(vis[v] == false && G[u][v] != INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = d[u] + G[u][v];
                    num[v] = num[u];
                }else if(d[u] + G[u][v] == d[v]){
                    num[v] += num[u];
                }
            }
        }
        */
    }
}

//打印每层的节点
void DFS(int s, int v){
    if(v == s){
        printf("%d\n",s);
        return;
    }

    DFS(s, pre[v]);
    printf("%d\n",v);
}


int main()
{


    return 0;
}
