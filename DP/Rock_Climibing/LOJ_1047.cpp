#include <bits/stdc++.h>
using namespace std;
#define inf 1e18
int a[25][5],dp[25][5],n,ans=inf;
int rec(int i, int j){
  if(i==n)return dp[i][j]=a[i][j];
  if(dp[i][j]!=-1)return dp[i][j];
  int res=inf,x=a[i][j];

  if(j==1)res=x+min(rec(i+1,2),rec(i+1,3));
  else if(j==2)res=x+min(rec(i+1,1),rec(i+1,3));
  else if(j==3)res=x+min(rec(i+1,1),rec(i+1,2));
  return dp[i][j]=res;
}
int main(int argc, char const *argv[]) {
  freopen("0uput.txt","w",stdout);
  int TC;
  string blank;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(a,0,sizeof(a));
    memset(dp,-1,sizeof(dp));
    getline(cin, blank);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
      for(int j=1;j<=3;j++){
        scanf("%d",&a[i][j] );
      }
    }
    ans= min( rec(1,1),min( rec(1,2), rec(1,3) ) );
    printf("Case %d: %d\n",ii,ans);
  }
  return 0;
}
