#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned llu;
typedef long long ll;
vector<ll>v;
map<ll,ll>mp;
stack<ll>st;
queue<ll>qu;
ll a[1000006];
int main ()
{
    ll n,x;
    cin>>n;
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    //x=a[n-1]+a[n-2];
    //cout<<x<<endl;
    for(ll i=0;i<n-3;i++){
        x=a[i]+a[i+1];
        if(x>a[i+2]){
            cout<<"YES";
            return 0;
        }

    }
    cout<<"NO";
    return 0;

}
