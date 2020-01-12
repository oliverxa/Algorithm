#include <iostream>
#include <algorithm>
// Leetcode Maximum Subarray 最大子序列和
//由 N 个整数元素组成的一维数组 (A[0], A[1],…,A[n-1], A[n])，这个数组有很多连续子数组，那么其中数组之和的最大值是什么呢？
using namespace std;

int main()
{
    int n;
    cin >> n;
    int dp[n+1];
    int a[n+1];
    dp[0]=0;
    int max_sum = 0;
    for(int i=1; i<=n; i++){
        cin >> a[i];
        dp[i]= (dp[i-1]+a[i])>0 ? dp[i-1]+a[i] :0;
        max_sum = max(max_sum,dp[i]);
    }
    cout << max_sum;
    return 0;
}
