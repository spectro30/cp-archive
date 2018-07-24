#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[100006];
int main(){
  ll n,q,x;
  cin>>n;
  for(int i=1;i<=n;i++)cin>>a[i];
  cin>>q;
  while(q--){
    cin>>x;
    ll up,low;
    up = upper_bound(a+1,a+n+1,x)- a+1;
    low = lower_bound(a+1,a+n+1,x)- a+1;
    cout<<"LOW = "<<low<<endl;
    cout<<"UP = "<<up<<endl;
  }
}
