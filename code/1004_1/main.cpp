#include <iostream>
#include <stdio.h>
using namespace std;

typedef struct node{
    int child[100];
    int level;
}node_n;

int main()
{
    int n;
    int m;
    cin >> n >>m;
    node_n node[n];

    for(int i=0; i<m; i++){
        int ID, k;
        cin >> ID >> k;
        for(int j=0; j<k; j++){
            cin >> node[ID].child[j];
        }
    }
    int st = 1;

    while()


    cout << "Hello world!" << endl;
    return 0;
}
