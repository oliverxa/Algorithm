#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,k;

    cin >> n >> k ;
    int lan[n];
    for(int i=0; i<n; i++){
        cin >> lan[i];
    }
    int tmp=0;
    int minID=0;
    int minsum=1000000;
    for(int i=0; i<n-k; i++){
        int sum=0;
        for(int j=0; j<k; j++){
            sum += lan[i+j];
        }
        if(sum<minsum){
            minsum = sum;
            minID = i;
        }
    }
    cout << minID+1;
    return 0;
}
