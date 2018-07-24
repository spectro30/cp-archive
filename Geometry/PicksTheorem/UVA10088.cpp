////PICKS THEOREM
// FORMULA A= i+(b/2)-1; where(A=area of Polygon; i=strictly inside polygon points;b=onLinePoints)
#include <bits/stdc++.h>
using namespace std;
#define MP(x, y) make_pair(x, y)
#define PB(x) push_back(x)
#define SZ(c) (int)c.size()
#define ff first
#define ss second
#define ll long long
#define ld long double
#define pii pair<ll,ll>
int main()
{
  while(1){
    ll n,x,y,t1,t2,onLinePoints=0,sum=0;
    vector<pii>v;
    scanf("%lld",&n);
    if(!n)break;
    for(int i=0;i<n;i++){
      scanf("%lld%lld",&x,&y);
      if(!i){
        t1=x;t2=y;
      }
      v.PB(MP(x,y));
    }
    v.PB(MP(t1,t2));
    for(int i=0;i<SZ(v)-1;i++){
      sum+=v[i].ff*v[i+1].ss - v[i+1].ff*v[i].ss;
    }
    if(sum<0)sum*=-1.0;
    for(int i=0;i<SZ(v)-1;i++){
      onLinePoints+=__gcd( abs(v[i].ff-v[i+1].ff),abs(v[i].ss-v[i+1].ss) );
    }
    printf("%lld\n",(sum+2-onLinePoints)/2);
  }
  return 0;
}
