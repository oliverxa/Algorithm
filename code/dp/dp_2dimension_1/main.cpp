#include <iostream>
#include <cstring>
/*
Leetcode Longest Palindromic Substring/������Ӵ�
����һ���ַ���S���ҵ�һ������������Ĵ���
��� dp[i][j]�ǻ����Ӵ� ��a[i-1]=a[j+1] �� dp[i-1][j+1]�ǻ����Ӵ�

��ʼ�� dp[i][i]=1;
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
