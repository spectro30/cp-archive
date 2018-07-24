#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[105][1005],a[105],n,k,ans;
ll rec(ll i,ll koto){
  if(i==n+1){
    if(!koto)return 1;
    else return 0;
  }
  ll res1=0,res2=0;
  if(dp[i][koto]!=-1)return dp[i][koto];
  if(koto-a[i]>=0)res1=(rec(i,koto-a[i]));
  else res1=0;
  res2=(rec(i+1,koto));
  return dp[i][koto]=(res1+res2)%100000007;
}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(dp,-1,sizeof(dp));
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    printf("Case %d: %lld\n",ii,(rec(1,k))%100000007 );
    cout<<rec(1,k)<<endl;
  }
  return 0;
}
