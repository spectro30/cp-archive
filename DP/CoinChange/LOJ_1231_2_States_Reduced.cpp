#include <bits/stdc++.h>
#define mod 100000007
using namespace std;
int n,k,a[55],cnt[55],ans,dp[55][1010];
int rec(int i,int koto){
  if(i==n+1){
    if(!koto)return 1;
    else return 0;
  }
  int res1=0;
  if(dp[i][koto]!=-1)return dp[i][koto];
  for(int ii=1;ii<=cnt[i];ii++){
    if( (koto- (a[i]*ii) )>=0 )res1+=(rec(i+1,koto-(a[i]*ii)) )%mod;
  }
  res1+=(rec(i+1,koto))%mod;
  return dp[i][koto]=res1%mod;
}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(dp,-1,sizeof(dp));
    memset(a,0,sizeof(a));
    memset(cnt,0,sizeof(cnt));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    for(int i=1;i<=n;i++)scanf("%d",&cnt[i]);
    ans=(rec(1,k))%mod;
    printf("Case %d: %d\n",ii,ans);
  }
  return 0;
}
