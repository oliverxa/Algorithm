#include <iostream>
#include <vector>
using namespace std;

// 使用vector 实现邻接表

struct Node{
    int v, w;
    Node(int _v ,int _w) :v(_v) , w(_w){}
};
int n = 3;


int main()
{
    vector<Node> Adj[n];
    Adj[0].push_back(Node(1, 4));
    Adj[1].push_back(Node(2, 2));
    Adj[2].push_back(Node(0, 3));

    for(vector<Node>::iterator it = Adj[0].begin(); it!=Adj[0].end(); it++){
        //temp = Adj[0].pop_back();
        //cout << temp;
        Node temp = *it;
        cout << temp.v << temp.w ;


    }

    return 0;
}
