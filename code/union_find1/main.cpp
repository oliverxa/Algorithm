#include <iostream>
#define MAXN 5000
using namespace std;


int node[MAXN];
int node_rank[MAXN];

void Init(int n){
    for(int i=0; i<n; i++){
        node[i]=i;
        node_rank[i]=0;
    }
}

int root_find(int x){
    if(x == node[x])
        return x;
    return node[x] = root_find(node[x]);
}

void unite(int x, int y){
    x = root_find(x);
    y = root_find(y);

    if(x == y)
        return;

    if(node_rank[x] < node_rank[y])
        node[x] = y;
    else{
        node[y] = x;
        if(node_rank[x] == node_rank[y])
            node_rank[x]++;
    }

}

int same(int x, int y){
    return root_find(x) == root_find(y);
}

int main()
{
    while(true){
        int N,M;
        cin >> N >> M;
        Init(N+1);
        for(int i=0; i<M; i++){
            int x,y;
            cin >> x >> y;
            unite(x,y);
        }
        int road=0;
        for(int i=1; i<N; i++){
            if(!same(i,i+1)){
                road++;
                unite(i,i+1);
                //·ÀÖ¹ÖØ¸´ÅÐ¶Ï
            }

        }
        cout << road << '\n';
    }

    return 0;
}
