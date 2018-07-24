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
ll x,y,a,b,c,d,temp;
void extendedEuclid(ll a, ll b){
  if(b == 0){ x = 1; y = 0; d = a; return ;}
  extendedEuclid(b,a%b);
  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}
int main(int argc, char const *argv[]) {
  while(cin>>a>>b){
    d = __gcd(a,b);
    c = d;
    extendedEuclid(a,b);
    temp = c/d;
    x *= temp;
    y *= temp;
    cout << x << " " << y << " "<<c << endl;
  }

  return 0;
}
