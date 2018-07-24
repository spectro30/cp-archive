#define pb push_back
#define mkp make_pair
#define ll long long
#define mod 1000000007
#define ff first
#define ss second
#include<bits/stdc++.h>
using namespace std;

//---prime---
bool marked[66006];
vector<ll>prime;
void sieve(ll n){
  for(int i=3;i*i<=n;i+=2){
    if(marked[i]==false){
      for(int j=i*i;j<=n;j+=i+i){
        marked[j]=true;
      }
    }
  }
}
bool isprime(ll n){
  if(n<2)return false;
  if(n==2)return true;
  if(n%2==0)return false;
  return marked[n]==false;
}
//-----end prime----

//-----prime factors----

vector< pair<ll,ll> > pf;
void primeFact(ll n){
  for(int i=0;i<prime.size();i++){
    ll cnt = 0;
    while((n%prime[i]) == 0){
      n/=prime[i];
      cnt++;
    }
    if(cnt)pf.pb(mkp(prime[i],cnt));
  }
  if(n>1)pf.pb(mkp(n,1));
}

//---Prime factor end---

//---Big Mod-----

ll bigmod (ll a,ll b, int M){
  if(b == 0) return 1%M;
  ll x  = bigmod(a, b/2 , M);
  x = ((x%M)*(x%M))%M;
  if(b%2 == 1)x = ((x%M)*(a%M)) % M;
  return x;
}

//----big mod end----


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

int main(){
  sieve(66000);
  for(int i=1;i<=66000;i++)if(isprime(i))prime.pb(i);
  int TC;
  scanf("%d", &TC);
  for(int ii=1;ii<=TC;ii++){
    ll n,m;
    pf.clear();
    scanf("%lld%lld",&n,&m);
    primeFact(n);
    ll bm,mod_inv,ans = 1,val,k,p;
    for(int i=0;i<pf.size();i++){
      p = pf[i].ff; k = pf[i].ss;
      bm = bigmod(p,(k*m + 1),mod);
      bm = ( ( (bm%mod) - 1) + mod ) % mod;
      mod_inv = modInverse( p-1 , mod );
      bm = ((bm%mod) * (mod_inv%mod)) % mod;
      ans = ( (ans%mod) * (bm%mod) ) % mod;
    }
    printf("Case %d: %lld\n",ii,ans);

  }
  return 0;
}
