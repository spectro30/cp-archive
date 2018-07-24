#include <bits/stdc++.h>
using namespace std;
int n,w[105],c[105],q,dp[105][105],prob,x;
double d;
int rec(int pos, int cost){
  int max1,max2;
  //cout<<pos<<"==="<<cost<<"==="<<w[pos]<<endl;
  if(pos==n+1 ){
    dp[pos][cost]=0;
    return 0;
  }
  if(dp[pos][cost]!=-1)return dp[pos][cost];
  if(cost-w[pos]>=0)max1=c[pos]+rec(pos+1, cost);
  else max1=0;
  max2=rec(pos+1,cost);
  dp[pos][cost]=max(max1,max2);
  return dp[pos][cost];

}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    scanf("%lf%d",&d,&n);
    d*=100;
    prob=d;
    memset(c,0,sizeof(c));
    memset(w,0,sizeof(w));
    memset(dp,-1,sizeof(dp));
    for(int i=1;i<=n;i++){
      scanf("%d%lf",&c[i],&d);
      d=d*100.0;
      w[i]=d;
    }
    printf("Case %d: %d\n",ii,rec(0,prob));
  }
  return 0;
}
