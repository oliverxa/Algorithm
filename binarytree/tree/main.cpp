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
//������漰���ݣ�ֻҪ���Ľṹ���Լ�Ϊ��
vector<int> child[maxn];
//�ڴ˶����£�child[0], child[1] ����һ��vector����˸����������ӽڵ���±�

int index = 0;

int newNode(int v){
    Node[index].data = v;
    Node[index].child.clear();
    return index++;
}

//������� �����ö���ʵ��

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
