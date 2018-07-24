#include<bits/stdc++.h>
using namespace std;
int dp[1000];
int cnt=0;
int fib(int n)
{
    if(dp[n]){
        return dp[n];
    }
    cnt++;
    if(n<=1){
        dp[n]=n;
        return dp[n];
    }

    dp[n]=fib(n-1)+fib(n-2);
    return dp[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<fib(n)<<endl;//creating the dp array till N;
    cout<<cnt<<endl;//how many time that function has been called;
    for(int i=1;i<=n;i++)cout<<dp[i]<<" ";//dp array;

}

