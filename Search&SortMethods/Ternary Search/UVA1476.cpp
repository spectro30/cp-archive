#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[5][10005],n;
double cal(double x)
{
  double mx=-10000.0,ans;
  for(int i=1;i<=n;i++){
    mx=max(mx,(x*x*a[1][i] + x*a[2][i] + a[3][i]));
  }
  return mx;
}
int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  int TC;
  scanf("%d",&TC);
  while(TC--){
    scanf("%d",&n);
    ll x;
    for(int i=1;i<=n;i++){
      scanf("%d%d%d",&a[1][i],&a[2][i],&a[3][i]);
    }
    double l=0,r=1000,tl,tr;
    while(fabs(l-r)>1e-10){
      tl= (l*2+r)/3;
      tr=(l+r*2)/3;
      if(cal(tr)>cal(tl))r=tr;
      else l=tl;
    }
    printf("%.4lf\n",cal(l));

  }
  return 0;
}
