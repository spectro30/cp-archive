#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[102][102],a[102][102];
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  // ios_base::sync_with_stdio(false);
  // cin.tie(NULL);
  ll TC;
  scanf("%lld",&TC);
  for(ll ii=1;ii<=TC;ii++){
    memset(dp,0,sizeof(dp));
    ll n,m,k,ans=1e18,area=0,temp;
    bool abool=false;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++){
      scanf("%lld",&dp[i][j]);
      a[i][j]=dp[i][j];
    }
    for(ll i=1;i<=n;i++)for(ll j=1;j<=m;j++)dp[i][j]+=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];

    for(ll x1=1;x1<=n;x1++){
      for(ll y1=1;y1<=m;y1++){
        if(a[x1][y1]<=k){
          for(ll x2=x1;x2<=n;x2++){
            for(ll y2=y1;y2<=m;y2++){
              if(x2>=x1 && y2>=y1){
                temp=dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
                if(temp<=k){
                  abool=true;
                  if(((x2-x1+1)*(y2-y1+1))>area){
                      area=((x2-x1+1)*(y2-y1+1));
                      ans=temp;
                  }
                  else if(((x2-x1+1)*(y2-y1+1))==area){
                    area=((x2-x1+1)*(y2-y1+1));
                    ans=min(ans,temp);
                  }
                }
              }
            }
          }
        }
      }
    }
    if(!abool){
      ans=0;
      area=0;
    }
    printf("Case #%lld: %lld %lld\n",ii,area,ans);
  }
  return 0;
}
