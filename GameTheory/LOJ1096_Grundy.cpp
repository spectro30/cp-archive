#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll grundy(ll n)
{
  if(n==1)return 0;
  if(n&1)return grundy(n/2);
  return n/2;
}
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    int n;
    scanf("%d",&n);
    ll x,ans=0;
    for(int i=1;i<=n;i++){
      scanf("%lld",&x);
      ans^=grundy(x);
    }
    if(ans)printf("Case %d: Alice\n",ii);
    else printf("Case %d: Bob\n",ii);
  }
  return 0;
}
