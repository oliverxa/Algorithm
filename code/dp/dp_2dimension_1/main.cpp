#include <iostream>
#include <cstring>
/*
Leetcode Longest Palindromic Substring/最长回文子串
给出一个字符串S，找到一个最长的连续回文串。
如果 dp[i][j]是回文子串 且a[i-1]=a[j+1] 则 dp[i-1][j+1]是回文子串

初始化 dp[i][i]=1;
if (a[i]=a[i+1])
    dp[i][i+1]=1;
    st=i;
    ed=i+1;
    max_len =2;
*/
using namespace std;

int main()
{
    string str;
    cin >> str;
    int len = str.length();
    int dp[len+1][len+1];
    for(int i=1; i<=len; i++)
        dp[i][i]=1;
    cout << len;
    return 0;
}
