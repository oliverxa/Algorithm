#include <iostream>

using namespace std;

const int maxv = 1001;
const int INF = 1000000000;
//ÁÚ½Ó¾ØÕó
int n, G[maxv][maxv];
bool vis[maxv]={false};

void DFS(int u, int depth){
    vis[u] = true;
    for(int i=0; i<n; i++){
        if(vis[i] == false && G[u][i] != INF){
            DFS( i, depth+1);
        }
    }

}

void DFStrave(){
    for(int u=0; u<n; u++){
        if(vis[u] == false){
            DFS(u, 1);
        }
    }
}

//ÁÚ½Ó±í

vector<int> Adj[MAXV];
int n;
bool vis[MAXV] = {false};

void DFS(int u, int depth){
    vis[u] = true;
    for(int i=0; i<Adj[u].size(); i++){
        int v = Adj[u][i];
        if(vis[v] == false){
            DFS(v, depth+1);
        }
    }
}

void DFStrave(){
    for(int u=0; u<n; u++){
        if(vis[u] == false){
            DFS(u, 1);
        }
    }
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
