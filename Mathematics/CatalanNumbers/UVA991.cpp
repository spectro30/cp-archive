#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mod 100000007
#include <bits/stdc++.h>
using namespace std;
ll n,sum,x,y,k;
ll fact[20006],a[1006];


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


//------nCr----------
ll nCr(ll n, ll k){
  if(k>n)return 0;
  if(k==n)return 1;
  ll ret;
  ret = ( (fact[n])%mod * (modInverse(fact[n-k],mod))%mod )%mod;
  ret = ( ret%mod * (modInverse(fact[k],mod)) %mod) % mod;
  return ret;
}

//----------nCr end--------



//----------Factorial----------
void factorials(){
  fact[0] = 1;
  for(int i=1;i<=20001;i++){
    fact[i] = (((fact[i-1])%mod)*((i)%mod))%mod;
  }
}
//-------Factorial End----------

//-----------Catalan Number----------
ll catalan(ll n){
  ll res;
  res = nCr(n+n,n);
  res = (res * modInverse(n+1,mod)%mod)%mod;
  return res;
}

//-----------Catalan Number Ends---------

int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  factorials();
  ll n;
  bool ok = false;
  while(cin>>n){
    if(ok)cout<<endl;
    ok = true;
    cout<<catalan(n)<<endl;
  }

  return 0;
}
