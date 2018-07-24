#define ll long long
#define pb push_back
#define mpr make_pair
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;

vector<ll> pf( ll n){
  vector<ll> v;
  for(int i=1; i*i<=n;i++){
    if(n%i == 0){
      v.pb(n/i);
      if(i != n/i)v.push_back(i);
    }
  }
  return v;
}

ll lcm(ll a,ll b){
  return (a*b)/(__gcd(a,b));
}


int main(int argc, char const *argv[]) {
  ll n;
  while(cin>>n){
    if(!n)break;
    ll ans = 0;
    vector<ll>v;
    v = pf(n);
    for(ll i=0;i<v.size();i++){
      for(ll j=i;j<v.size();j++){
        if(lcm(v[i],v[j])==n)ans++;
      }
    }
    cout<<n<<" "<<ans<<endl;
  }
  return 0;
}
