#include <iostream>

using namespace std;
int maxn = 5000;
int node[maxn];
int tree_rank[maxn];

void Init(int n){
    for(int i=0; i<n; i++){
        node[i] = i;
        tree_rank[i] = 0;
    }

}

int find_root(int x){
    if(x==node[x])
        return x;
    return node[x] = find_root(node[x]);
    //����������ֱ���ڸ�������
}

void Unite(int x, int y){
    x=find_root(x);
    y=find_root(y);
    if(x == y)
        return;
    //��x�ĸ��ڵ���y�ĸ��ڵ�����
    if(tree_rank[x]<tree_rank[y])
        node[x] = y;
    else{
        node[y] = x;
        if(tree_rank[x]==tree_rank[y])
            tree_rank[x]++;
    }


    }
}

bool same(int x, int y){
    return find_root(x) == find_root(y);
}
int main()
{

    return 0;
}
