#include <iostream>
#include <vector>
using namespace std;

typedef struct node {
    int node_father;
    vector<int> node_son;
}*treenode;

int main()
{
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> sp;
    for(int i=0; i<m; i++){
        int tmp
        cin >> tmp;
        sp.push_back(tmp);
    }

    treenode node[n];
    for(int j=0; j< n-1; j++){
        int tmp2;
        cin >> tmp2;
        node[j+1].node_father = tmp2;
        node[tmp2].node_son.push_back(j+1);
    }

    while(m--){
        search_node(sp.pop_back());
    }


    return 0;
}
