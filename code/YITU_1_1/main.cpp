#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    //vector<int> upbus;
    //vector<int> downbus;
    cin >> n;
    int upbus[n];
    int downbus[n];
    for(int i=0; i<n; i++){

        cin >> upbus[i];
    }
    int sum = 0;
    for(int i=0; i<n; i++){
        cin >> downbus[i];
        sum+= upbus[i]*(-i) + downbus[i]*i;
    }

    cout << sum << endl;
    return 0;
}
