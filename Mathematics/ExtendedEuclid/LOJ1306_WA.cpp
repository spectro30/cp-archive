#define pb push_back
#define MX 1e18
#define mod 1000000009
#define ff first
#define ss second
#define for1(i,n) for(int i=1;i<=n;i++)
#define for0(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;

ll x,y,a,b,c,d,temp,x1,x2,y2,y11;

void extendedEuclid(ll a, ll b){
  if(b == 0){ x = 1; y = 0; d = a; return ;}
  extendedEuclid(b,a%b);
  ll xk = y;
  ll yk = x - (a / b) * y;
  x = xk;
  y = yk;
}
int main(int argc, char const *argv[]) {
  int TC;
  scanf("%d", &TC);
  for(int ii=1;ii<=TC;ii++){
    scanf("%lld%lld%lld%lld%lld%lld%lld",&a,&b,&c,&x1,&x2,&y11,&y2);
    c = c*(-1);
    d = __gcd(a,b);
    if(c%d !=0){
      cout<<-1<<endl;
      return 0;
    }
    extendedEuclid(a,b);
    temp = c/d;
    x *= temp;
    y *= temp;
    ll xl,xr,xly,xry,yl,yr,p1,p2,l,r,k,fl,fr;
    p1 = b/d; p2 = a/d;
    k = (x1-x)/p1;
    xl = x+ k*p1; xly = y- k*p2;
    k = (x2-x)/p1;
    xr = x + k*p1;
    xry = y - k*p2;

    k = (y-y11)/p2;
    yl = y - k*p2;
    k = (y-y2)/p2;
    yr = y- k*p2;
    r = min(xly,yr);
    l = max(xry,yl);

    k = (l-x)/p1;
    fl = x + k*p1;
    k = (r-x)/p1;
    fr = x + k*p1;
    cout<<(r-l)/p2<<endl;
    cout<<l<<" "<<r<<endl;
    // cout<<p1<<" "<<p2<<endl;
     cout << xl << " " << xr << endl;
     cout << xly << " " << xry << endl;
     cout << yl << " " << yr << endl;
  }

  return 0;
}
