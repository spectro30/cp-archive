#include <bits/stdc++.h>
using namespace std;
int n,w[1005],c[1005],a[1005],q,dp[1005][32];
int rec(int pos, int cost){
  int max1,max2;
  //cout<<pos<<"==="<<cost<<"==="<<w[pos]<<endl;
  if(pos==n+1 ){
    dp[pos][cost]=0;
    return 0;
  }
  if(dp[pos][cost]!=-1)return dp[pos][cost];
  if(cost-w[pos]>=0)max1=c[pos]+rec(pos+1, cost-w[pos]);
  else max1=0;
  max2=rec(pos+1,cost);
  dp[pos][cost]=max(max1,max2);
  return dp[pos][cost];

}
int main(int argc, char const *argv[]) {
  freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  while(TC--){
    scanf("%d",&n);
    memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    memset(a,0,sizeof(a));
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++)scanf("%d%d",&c[i],&w[i]);
    scanf("%d",&q);
    int sum=0;
    for(int i=1;i<=q;i++)scanf("%d",&a[i] );
    for(int i=1;i<=q;i++){
      //cout<<rec(1,a[i])<<endl;
      sum+=rec(1,a[i]);
    }

    printf("%d\n",sum);
  }
  return 0;
}
