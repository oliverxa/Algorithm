#include <iostream>
#define MAXN 5000
using namespace std;

int node[MAXN];
int node_rank[MAXN];

void Init(int t){
    for(int i=1; i<=t; i++){
        node[i]=i;
        node_rank[i]=0;
    }

}

int root_find(int x){
    if(x==node[x])
        return x;
    return node[x] = root_find(node[x]);
}

void unite(int x, int y){
    x=root_find(x);
    y=root_find(y);

    if(x == y)
        return;
    //�������ȾͲ��úϲ�
    if(node_rank[x]<node_rank[y])
        node[x]=y;
    else{
        node[y]=x;
        if(node_rank[x]==node_rank[y])
            node_rank[x]++;
    }

}

bool same(int x, int y){
    return root_find(x) == root_find(y);
}

int main()
{
    int T;
    cin >> T;
    while(T){
        int N,M;
        cin >> N>> M;
        Init(N+1);
        //��Ҫ���ǳ�ʼ��
        for(int i=0; i<M; i++){
            int x,y;
            cin >> x>> y;
            unite(x,y);
        }
        int desk=1;
        for(int i=1; i<N; i++){
            if(!same(i,i+1)){
                desk++;
                unite(i,i+1);
                //��ֹ�ظ��ж�
            }
        }
        cout << desk << '\n';

    }
    return 0;
}
