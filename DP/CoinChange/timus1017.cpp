#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll sum,n,dp[505][505];
ll rec(ll i,ll sum)
{
  //cout<<i<<" "<<sum<<endl;
  if(sum<=0){
    if(!sum)return 1;
    else return 0;
  }
  if(dp[i][sum]!=-1)return dp[i][sum];
  ll res=0;
  for(ll j=1;j<i;j++){
    res+=rec(j,sum-j);
  }
  return dp[i][sum]=res;
}
int main()
{
    memset(dp,-1,sizeof(dp));
    cin>>n;
    cout<<rec(n,n)<<endl;
    return 0;
}
