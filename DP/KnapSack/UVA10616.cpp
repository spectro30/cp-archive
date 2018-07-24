#include <bits/stdc++.h>
using namespace std;
int dp[205][15][25],a[205];
int n,q,k,d;
int rec(int i,int j,int sum){
  if(i==n+1){
    if(j==k && sum%d==0)return 1;
    else return 0;
  }
  if(dp[i][j][sum]!=-1)return dp[i][j][sum];
  int res1=0,res2;
  if(j+1<=k)res1=rec(i+1,j+1,((sum+a[i])%d+d)%d);
  res2=rec(i+1,j,sum);
  return dp[i][j][sum]=res1+res2;
}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int cnt=0;
  while(cin>>n>>q){
    cnt++;
    if(!n&&!q)return 0;
    cout<<"SET "<<cnt<<":"<<endl;
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=q;i++){
      memset(dp,-1,sizeof(dp));
      cin>>d>>k;
      cout<<"QUERY "<<i<<": ";
      cout<<rec(1,0,0)<<endl;
    }
  }
  return 0;
}
