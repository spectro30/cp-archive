//Coin Change (one item can repeat)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[501][501][501],a[505],bug[505],n,m,b,mod;
ll rec(ll i,ll koto,ll moyla){
  if(i==n+1){
    if(!koto && moyla>=0)return 1;
    else return 0;
  }
  ll res1=0,res2=0;
  if(dp[i][koto][moyla]!=-1)return dp[i][koto][moyla];
  if(koto-1>=0 && moyla-bug[i]>=0)res1=(rec(i,koto-1,moyla-bug[i]))%mod;
  else res1=0;
  res2=(rec(i+1,koto,moyla))%mod;
  return dp[i][koto][moyla]=(res1+res2)%mod;

}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  cin>>n>>m>>b>>mod;
  for(int i=1;i<=n;i++)cin>>bug[i];
  cout<<rec(1,m,b);
  return 0;
}
