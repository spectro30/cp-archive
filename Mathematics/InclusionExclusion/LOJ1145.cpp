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

int main(int argc, char const *argv[]) {
  //freopen("0uput.txt","w",stdout);
  factorials();
  int TC;
  scanf("%d",&TC);
  for(int ii=1;ii<=TC;ii++){
    memset(a,0,sizeof(a));
    scanf("%lld%lld%lld",&n,&k,&sum);
    sum-=n;
    if(sum<0){
      printf("Case %d: %lld\n",ii,0LL);
      continue;
    }
    ll ans,pns,p,cal;
    vector<ll>v;
    ans = nCr(sum+n-1,n-1);
    pns = 0;p = 1;
    for(int i=1;i<=n;i++){
      p = ( p * (n-i+1)%mod)%mod;
      p = ( p * modInverse(i,mod)%mod)%mod;
      cal = (p * nCr(sum-(i*k)+n-1,n-1)%mod )%mod;
      //cout<<i<<" "<<cal<<" "<<p<<endl;
      if(i*k > sum)break;
      if(i&1)pns = (pns + cal%mod)%mod;
      else pns = ((pns - cal%mod)+mod)%mod;
    }
    //cout<<ans<<" "<<pns<<endl;
    ans =  (( (ans%mod) - (pns%mod))+mod)%mod;
    printf("Case %d: %lld\n",ii,ans);
  }

  return 0;
}
