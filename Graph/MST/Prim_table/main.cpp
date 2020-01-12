#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int MAXV = 1000;
const int INF = 0x3f3f3f3f;

struct Node{
    int v, dis;
};
vector<Node> Adj[MAXV];
int n;
int d[MAXV];
bool vis[MAXV] = {false};

int prim(){
    fill(d, d+MAXV, INF);
    d[0] = 0;
    int ans = 0;
    for(int i=0; i<n; i++){
        int u=-1, MIN=INF;
        for(int j=0; j<n; j++){
            if(vis[j] == false && d[j]<MIN){
                u = j;
                MIN = d[j];
            }
        }

        if(u == -1) return -1;
        vis[u] = true;
        ans += d[u];

        for(int j=0; j< Adj[u].size(); j++){
            int v = Adj[u][j].v;
            int dis = Adj[u][j].dis;
            if(vis[v] == false && dis < d[v]){
                d[v] = dis; //算法笔记这里有错
            }
        }
    }
    return ans;

}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
