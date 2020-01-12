#include <iostream>
#include <string.h>
#define maxn 1000000;
using namespace std;

int main()
{
    int n,m,s,d;
    cin >>n >>m >>s >>d;
    int cake[n];
    int road[n][n];
    bool visit[n][n];
    memset(visit, false, sizeof(visit));
    for(int i=0; i<n; i++){
        cin >> cake[i];
        for(int j=0; j<n; j++){
            road[i][j] = maxn;
        }
    }
    int a, b, cost;
    for(int i=0; i<m; i++){
        cin >> a >> b >> cost;
        if(road[a][b]> cost)
            road[a][b] = cost;
    }
    int tmp, k;
    for(int i=0 ; i< n; i++){
        for(int j=0; j<n; j++){


        }
    }
    cout << "Hello world!" << endl;
    return 0;
}
