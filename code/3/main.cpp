#include <iostream>
#include <queue>
#include <utility>
#define pii pair<int,int>

using namespace std;


struct cmp{
    bool operator() (const pii p1,const pii p2){
        return p1.first > p2.first;         /// first 小的先弹出
    }
};


int main()
{
    int n,m;

    priority_queue<pii,vector<pii>,cmp> q;

    cin >>n >>m;
    pair<int, int> food[n];
    for(int i=0; i<n; i++){
        cin >> food[i].first;

    }
    for(int i=0; i<n; i++){
        cin >> food[i].second;
        q.push(food[i]);
    }

    while(m){
        pair<int, int> tmp;
        tmp = q.top();
        //cout << tmp.first << tmp.second;
        if(m>= tmp.second){
            m -= tmp.second;
            q.pop();
            tmp.first++;
            q.push(tmp);
        }
        else
            break;
    }
    pair<int, int> ans;
    ans = q.top();
    cout << ans.first;
    return 0;
}
