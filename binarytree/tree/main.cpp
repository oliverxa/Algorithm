#include <iostream>
#include <vector>
#include <queue>
typedef maxn = 1001;
//9.3.4
using namespace std;

//static tree
struct node{
    int data;
    //int child[maxn];
    vector child;
}Node[maxn];
//如果不涉及数据，只要树的结构可以简化为：
vector<int> child[maxn];
//在此定义下，child[0], child[1] 都是一个vector存放了各结点的所有子节点的下标

int index = 0;

int newNode(int v){
    Node[index].data = v;
    Node[index].child.clear();
    return index++;
}

//层序遍历 依旧用队列实现

void layerorder(int root){
    queue<int> q;
    q.push(root);
    //Node[root].layer = 0;
    while(!q.empty()){
        int fro = q.front();
        print("%d", Node[fro].data);
        q.pop();
        for(int i=0; i<Node[fro].child.size(); i++){
            int child =  Node[fro].child[i];
            //Node[child].layer = Node[fro].layer +1;
            q.push(child);
        }
    }
}



int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
