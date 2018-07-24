#include <bits/stdc++.h>
using namespace std;
int a[205][205],dp[205][205],n;
int rec(int i, int j){
  if(i<=0 || j<=0 || !a[i][j])return 0;
  if(dp[i][j]!=-1)return dp[i][j];
  int res=0;
  res=max(res,rec(i+1,j)+a[i][j]);
  if(i>=n)res=max(res,rec(i+1,j-1)+a[i][j]);
  else res=max(res,rec(i+1,j+1)+a[i][j]);
  return dp[i][j]=res;
}
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(a,0,sizeof(a));
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=i;j++){
        scanf("%d",&a[i][j] );
      }
    }
    for(int i=1;i<n;i++){
      for(int j=1;j<=n-i;j++){
        scanf("%d",&a[i+n][j]);
      }
    }
    printf("Case %d: %d\n",ii,rec(1,1));

  }
  return 0;
}
