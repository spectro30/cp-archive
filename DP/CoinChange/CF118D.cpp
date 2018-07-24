#include <bits/stdc++.h>
#define mod 100000000
using namespace std;
typedef long long ll;
ll n1,n2,k1,k2,dp[105][105][12][12];
ll rec(ll i,ll j,ll x, ll y){
  if(x>k1 || y>k2)return 0;
  if(i==n1 && j==n2)return 1;
  if(dp[i][j][x][y]!=-1)return dp[i][j][x][y];
  ll res=0;
  if(i+1<=n1)res+=rec(i+1,j,x+1,0)%mod;
  if(j+1<=n2)res+=rec(i,j+1,0,y+1)%mod;
  return dp[i][j][x][y]=res;
}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  cin>>n1>>n2>>k1>>k2;
  cout<<rec(0,0,0,0)%mod;
  return 0;
}
