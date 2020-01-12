#include <iostream>
#include <algorithm>
// Leetcode Maximum Subarray ��������к�
//�� N ������Ԫ����ɵ�һά���� (A[0], A[1],��,A[n-1], A[n])����������кܶ����������飬��ô��������֮�͵����ֵ��ʲô�أ�
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
