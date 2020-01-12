#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAXV = 1001;

//邻接矩阵
int n, G[MAXV][MAXV];
bool inq[MAXV] = {false};

void BFS(int u){
    queue<int> q;
    q.pus(u);
    inq[u] = true;

    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v=0; v<n; v++){
            q.push(v);
            inq[v] = true;
        }
    }
}

void BFStrave(){
    for(int u=0; u<n; u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}

//邻接表
vector<int> Adj[MAXV];
int n;
bool inq[MAXV]= {false};
void BFS(int u){
    queue<int> q;
    q.push(u);
    inq[u] = true;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for(int i=0; i<Adj[u].size(); i++){
            int v = Adj[u][i];
            if(inq[v] == false){
                q.push(v);
                inq[v] = true;
            }
        }
    }
}

void BFStrave(){
    for(int u=0; u<n; u++){
        if(inq[u] == false){
            BFS(u);
        }
    }
}
// p363 !!!
// 邻接表 有层数

struct Node{
    int v;
    int layer;
};

vector<Node> Adj[N];

void BFS(int s){
    queue<int> q;
    Node start;
    start.v = s;
    start.layer = 0;
    q.push(start);
    inq[start.v] = true;
    while(!q.empty()){
        Node topNode = q.front();
        q.pop();
        int u = topNode.v;
        for(int i=0; i<Adj[u].size(); i++){
            Node next = Adj[u][i];
            next.layer = topNode.layer + 1;
            if(inq[next.v] == false){
                q.push(next);
                inq[next.v] = true;
            }
        }
    }
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
