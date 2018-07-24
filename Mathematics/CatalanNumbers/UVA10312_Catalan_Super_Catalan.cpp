#define pb push_back
#define ll long long
#define ff first
#define ss second
#define mod 100000007
#include <bits/stdc++.h>
using namespace std;
//----------Super Catalan Number------
ll SDP[50];
ll supuerCatalan(ll n){
  if(n <= 2)   return 1;
  if(n == 3)   return 3;
  if(SDP[n])   return SDP[n];
  ll res;
  res  = ( ( ( (6*n) - 9) * supuerCatalan(n-1)) - ( (n-3) * (supuerCatalan(n-2)) ) ) /n;
  return SDP[n] = res;
}

//----------Super Catalen Number Ends----------

//-----------Catalan Number----------
ll catalan(ll n){
  bool carked[50];
  memset(carked,0,sizeof carked);
  ll res = 1;
  for(int i=n+2;i<=n+n;i++){
    res *= i;
    for(int j=1;j<=n;j++)if(res%j==0 && !carked[j]){
      res/=j;
      carked[j] = true;
    }
  }
  return res;
}
//-----------Catalan Number Ends---------



int main(int argc, char const *argv[]) {
  ll n;
  while(cin>>n){
    cout<<supuerCatalan(n)-catalan(n-1)<<endl;
  }

  return 0;
}
