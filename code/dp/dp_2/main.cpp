#include <iostream>
//Leetcode Decode Ways/解码方法
//现在有如下的字母与数字的对应关系：1-A, 2-B, …26-Z。给定一个由数字组成的字符串，判断按照上面的映射可以转换成多少种不同的字符串。
//dp[i]=dp[i-1]+dp[1-2]
using namespace std;

int main()
{
    while(true){
        int n;
        cin >> n;
        int a[n+1];
        int dp[n+1];
        a[0]=0;
        cin >> a[1];
        dp[0]=dp[1]=1;
        if(a[1]==0){
            cout << 0;
            continue ;
        }
        for(int i=2; i<=n; i++){
            cin >> a[i];
            int tmp = a[i]+a[i-1]*10;
            dp[i]=0;
            if(tmp>=10&&tmp<=26)
                dp[i]+=dp[i-2];
            if(a[i]!=0)
                dp[i]+=dp[i-1];
        }
        cout << dp[n];
    }
    return 0;
}
