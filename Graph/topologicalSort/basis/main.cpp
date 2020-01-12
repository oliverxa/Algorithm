#include <iostream>
#include <bits/stdc++.h>

using namespace std;
const int MAXV = 200;

//拓扑排序的对象是有向无环图（DAG）
//将其排成线性序列，
//使得任意两个点u、v， 如果存在u->v，那么u一定在v前面。

//拓扑排序的很重要的应用就是判断一个给定的图是否是有向无环图。
//可以用priority_queue 来代替使得每次按照编号最小的排序

vector<int> G[MAXV];
int  inDegree[MAXV];
int n,m;

bool topologicalSort(){
    int num = 0;
    queue<int> q;
    for(int i=0; i<n; i++){
        if(inDegree[i] == 0)
            q.push(i);
    }
    while(!q.empty()){
        int u=q.front();
        //printf("%d",u); //打印排序结果
        q.pop();
        for(int i=0; i< G[u].size(); i++){
            int v = G[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                q.push(v);
            }
        }
        //G[u].clear(); //清空顶点u的所有出边
        num++;
    }

    if(num == n) return true; //说明拓扑排序成功
    else return false;
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
