#include <bits/stdc++.h>
#define mod 100000007
using namespace std;
int n,k,a[10005],dp[10005];
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(dp,0,sizeof(dp));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    dp[0]=1;
    for(int i=1;i<=n;i++){
      for(int j=1;j<=k;j++){
        if(j>=a[i])dp[j]=dp[j]%mod + dp[j-a[i]]%mod;
      }
    }
    printf("Case %d: %d\n",ii,dp[k]%mod);
  }
  return 0;
}
