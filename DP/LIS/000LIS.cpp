#include <bits/stdc++.h>
using namespace std;
int a[100],n,dp[100];
int longest(int u){
  if(dp[u]!=-1)return dp[u];
  int mx=0;
  for(int v=u+1;v<=n;v++){
    if(a[v]>=a[u]){
      if(longest(v)>mx){
        mx=longest(v);
      }
    }
  }
  dp[u]=mx+1;
  return dp[u];
}
int main(int argc, char const *argv[]) {
  memset(dp,-1,sizeof(dp));
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  int lis=0,start;
  for(int i=1;i<=n;i++){
    if(longest(i)>lis){
      lis=longest(i);
      start=i;
    }
  }
  cout<<lis<<" "<<start<<endl;
  return 0;
}
