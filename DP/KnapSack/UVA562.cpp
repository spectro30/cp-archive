#include <bits/stdc++.h>
using namespace std;
int dp[105][50005],a[105];
int n;
int rec(int i,int sum,int dum){
  //cout<<i<<" "<<sum<<" "<<dum<<endl;
  if(i==n+1){
    return abs(sum-dum);
  }
  if(dp[i][sum]!=-1)return dp[i][sum];
  int res1,res2;
  res1=rec(i+1,sum+a[i],dum);
  res2=rec(i+1,sum,dum+a[i]);
  return dp[i][sum]=min(res1,res2);
}
int main(int argc, char const *argv[]) {
  int TC;
  cin>>TC;
  while(TC--){
    memset(dp,-1,sizeof(dp));
    memset(a,0,sizeof(a));
    cin>>n;
    for(int i=1;i<=n;i++){
      cin>>a[i];
    }
    cout<<rec(1,0,0)<<endl;
  }


  return 0;
}
