#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int MAXV = 1000;
const int INF = 0x3fffffff;

int n, G[MAXV][MAXV];
int d[MAXV];
int pre[MAXV]; //��¼��ǰ�ڵ�
bool vis[MAXV] = {false};

void Dijkstra(int s){
    fill(d, d+MAXV, INF);

    for(int i=0; i<n; i++) pre[i] = i; //��ʼ����ǰ�ڵ�

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

                pre[v] = u; //���ǰ���ڵ�
            }
        }
        /* ����һ��cost ��������
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

        /* ����һ��weight �����ܶ�
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

        /*�������·��������
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

//��ӡÿ��Ľڵ�
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
