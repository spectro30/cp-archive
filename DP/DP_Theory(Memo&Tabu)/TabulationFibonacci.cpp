#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int main()
{
    int n;
    cin>>n;
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++)dp[i]=dp[i-1]+dp[i-2];
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";
    cout<<endl;
}

