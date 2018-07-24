#include <bits/stdc++.h>
#define mod 100000007
using namespace std;
int n,k,a[55],cnt[55],ans,dp[55][25][1000];
int rec(int i,int taken,int koto){
  if(i==n+1){
    if(!koto)return 1;
    else return 0;
  }
  int res1=0,res2=0;
  if(dp[i][taken][koto]!=-1)return dp[i][taken][koto];
  if(koto-a[i]>=0 && taken<cnt[i])res1=(rec(i,taken+1,koto-a[i]))%mod;
  else res1=0;
  res2=(rec(i+1,0,koto))%mod;
  return dp[i][taken][koto]=(res1+res2)%mod;
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
    ans=(rec(1,0,k))%mod;
    printf("Case %d: %d\n",ii,ans);
  }
  return 0;
}
