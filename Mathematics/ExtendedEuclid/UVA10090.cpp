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
ll x,y,a,b,c,d,temp,c1,c2,k,p;
void extendedEuclid(ll a, ll b){
  if(b == 0){ x = 1; y = 0; d = a; return ;}
  extendedEuclid(b,a%b);
  ll x1 = y;
  ll y1 = x - (a / b) * y;
  x = x1;
  y = y1;
}
int main(int argc, char const *argv[]) {
  while(1){
    cin>>c;
    if(!c)break;
    cin>>c1>>a>>c2>>b;
    d = __gcd(a,b);
    extendedEuclid(a,b);
    temp = c/d;
    x *= temp;
    y *= temp;
    if(c2<=c1){
      p = b/d;
      k = -1 * x/p;
      x+= k*p;
      if(x<0){
        x-= k*p;
        x+= (k+1)*p;
      }
      p = a/d;
      y-= k*p;

    }
    else{
      p = a/d;
      k = y/p;
      y -= k*p;
      if(y<0){
        y+= k*p;
        y-= (k-1)*p;
      }
      p = b/d;
      x+= k*p;

    }
    if(c%d !=0 ){
      cout<<"failed"<<endl;
      continue;
    }
    cout << x << " ++ " << y << endl;


  }
  return 0;
}
