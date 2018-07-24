#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100010
#include <bits/stdc++.h>
using namespace std;
ll a[MX],l[MX],r[MX],d[MX],sum[(MX*4)],lazy[(MX*4)],flag[MX];

void relax(ll node, ll start, ll end){
    sum[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[2*node] += lazy[node];
        lazy[(2*node)+1] += lazy[node];
    }
    lazy[node] = 0LL;
}

void build(ll node, ll start, ll end){
    if(start ==  end){
        sum[node] = a[start];
        return ;
    }
    ll mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

void update(ll node, ll start, ll end, ll i, ll j, ll val){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node] += val;
        relax(node,start,end);
        return;
    }
    ll mid = (start + end) / 2;
    update(node*2, start, mid, i, j, val);
    update((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

ll query(ll node, ll start, ll end, ll x){
    if(lazy[node])relax(node, start, end);
    if(start>x || end<x)return 0LL;
    if(start == end){
        return sum[node];
    }
    ll p,q;
    ll mid = (start+end) / 2;
    p = query(node*2 ,start, mid, x);
    q = query((node*2)+1, mid+1, end, x);
    return (p+q);
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    ll n,m,k;
    cin >> n >> m >> k;
    for(ll i=1;i<=n;i++){
        cin >> a[i];
    }
    build(1,1,n);
    for(ll i=1;i<=m;i++){
        cin>> l[i] >> r[i] >> d[i];
    }
    for(ll i=1;i<=k;i++){
        ll l,r;
        cin >> l >> r;
        flag[l]++;
        flag[r+1]--;
    }
    for(int i=1;i<=m;i++){
        flag[i] += flag[i-1];
    }
    for(ll i=1;i<=m;i++){
        update(1,1,n,l[i],r[i],(flag[i]*d[i]) );
    }
    for(ll i=1;i<=n;i++){
        ll ans = query(1,1,n,i);
        cout<<ans<<" ";
    }
    return 0;
}
