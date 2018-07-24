#define pb push_back
#define ff first
#define ss second
#define ll long long

#include <bits/stdc++.h>
using namespace std;
int n,a[1000006],mx;
vector<pair<int,int> > v;
int main(int argc, char const *argv[]) {

    cin >> n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int j;
        for(j=i;j<=n;j++){
            if( (abs(a[j]-a[i])==1) || ((a[j]%7) == (a[i]%7)) ){
                v.pb(make_pair(i,j));
            }
            else{
                break;
            }
        }
        //cout<< i <<" "<<j<<endl;
        v.pb(make_pair(i,j-1));
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i].ff<<" "<<v[i].ss<<endl;
        for(int j=i+1;j<v.size();j++){
            if ( (v[i].ff < v[j].ff && v[i].ss < v[j].ff) || (v[i].ff > v[j].ss && v[i].ss > v[j].ss) ){
                mx = max(mx, v[j].ss-v[j].ff+1+v[i].ss-v[i].ff+1 );
            }
        }
    }
    cout<< mx<<endl;
    return 0;
}
