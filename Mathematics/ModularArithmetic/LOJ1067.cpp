#define pb push_back
#define mkp make_pair
#define ll long long
#define mod 1000003
#define ff first
#define ss second
#include<bits/stdc++.h>
using namespace std;

//--- mod inverse(iterative extended euclid)---

ll modInverse(ll a, ll m){
  ll m0 = m;
  ll y = 0, x = 1;
  if (m == 1) return 0;
  while (a > 1){
    ll q, t;
    q = a / m;
    t = m;
    m = a % m, a = t;
    t = y;
    y = x - q * y;
    x = t;
  }
  if (x < 0) x += m0;
  return x;
}

//----- mod inverse end----
ll a[1000006];
int main(){
  a[0] = 1;
  for(int i=1;i<=1000000;i++)a[i] = (a[i-1]%mod) * (i%mod) %mod;
  int TC;
  scanf("%d", &TC);
  for(int ii=1;ii<=TC;ii++){
    ll n,r,ans;
    scanf("%lld%lld",&n,&r);
    ans = a[n];
    ans = (ans%mod) * ((modInverse(a[r],mod)%mod))%mod;
    ans = (ans%mod) * ((modInverse(a[n-r],mod)%mod))%mod;
    printf("Case %d: %lld\n",ii,ans);

  }
  return 0;
}
