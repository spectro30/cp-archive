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
int a[1000006];
int main(){
  for(int i=1;i<=1000000;i++)a[i] = (a[i-1]%mod) * (a[i]%mod) %mod;
  int TC;
  cout<<a[5]<<endl;
  scanf("%d", &TC);
  for(int ii=1;ii<=TC;ii++){

  //  printf("Case %d: %lld\n",ii,ans);

  }
  return 0;
}
