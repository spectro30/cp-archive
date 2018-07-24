#define pb push_back
#define ll long long
#define ff first
#define ss second
#include <bits/stdc++.h>
using namespace std;
//------- Prime Factorization--------
vector<pair<ll,ll> > pf( ll n){
    vector<pair<ll,ll> > v;
    ll temp = n,cnt ;
    for(int i=2; i*i<=n;i++){
        if(temp%i == 0){
            cnt = 0;
            while(temp%i == 0){
                cnt++;
                temp/=i;
            }
            v.push_back(make_pair(i,cnt));
        }
    }
    if(temp>1)v.push_back(make_pair(temp,1));
    return v;
}
//-------prime Factorization ends----------


int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    ll n,m;
    while(cin>>n>>m){
        vector<pair<ll,ll> > v;
        v = pf(m);
        bool ok = true;
        for(int i=0;i<v.size();i++){
            ll p,temp;
            temp  = v[i].ff;p = 0;
            while(temp<=n){
                p += n/temp;
                temp*=v[i].ff;
            }
            if(v[i].ss>p){
                ok = false;
                break;
            }
        }
        if(ok)printf("%lld divides %lld!\n",m,n);
        else printf("%lld does not divide %lld!\n",m,n);
    }

    return 0;
}
