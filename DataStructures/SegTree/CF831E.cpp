#define pb push_back
#define ff first
#define ss second
#define ll long long
#define pii pair<ll,ll>

#include <bits/stdc++.h>
using namespace std;
ll n, a[1000005], sum[1000005];
ll ans;
pii tnode[1000005];

pii combine(pii l, pii r){
    pii res;
    if(l.ff <= r.ff)res.ss = l.ss;
    else res.ss = r.ss;
    res.ff = min(l.ff, r.ff);
    return res;
}

void buildSum(ll node, ll start, ll end){
    if(start == end){
        sum[node] = 1;
        return;
    }
    ll mid = (start + end) / 2;
    buildSum(node*2, start, mid);
    buildSum((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

void updateSum(ll node, ll start, ll end, ll i){
    if(start > i || end<i)return;
    if(i<=start && end<=i){
        sum[node] = 0;
        return;
    }
    ll mid = (start + end) / 2;
    updateSum(node*2, start, mid, i);
    updateSum((node*2)+1, mid+1, end, i);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

ll querySum(ll node, ll start, ll end, ll i, ll j){
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sum[node];
    }
    ll p,q;
    ll mid = (start+end) / 2;
    p = querySum(node*2 ,start, mid, i, j);
    q = querySum((node*2)+1, mid+1, end, i, j);
    return p+q;
}

void build(ll node, ll start, ll end){
    if(start == end){
        tnode[node] = make_pair(a[start], start);
        return;
    }
    ll mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    tnode[node] = combine(tnode[node*2],  tnode[(node*2)+1]);
}


void update(ll node, ll start, ll end, ll i){
    if(start > i || end<i)return;
    if(i<=start && end<=i){
        tnode[node].ff = INT_MAX;
        tnode[node].ss = -1;
        updateSum(1, 1, n, i);
        return;
    }
    ll mid = (start + end) / 2;
    update(node*2, start, mid, i);
    update( (node*2)+1 , mid+1, end, i);
    tnode[node] = combine(tnode[node*2],  tnode[(node*2)+1]);
}

pii query(ll node, ll start, ll end, ll i, ll j){
    if(start>j || end<i || start>end)return make_pair(INT_MAX,-1);
    if(i<=start && end<=j){
        return tnode[node];
    }
    pii p,q;
    ll mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return combine(p,q);
}


int main(int argc, char const *argv[]) {
    cin >> n;
    for(int i=1;i<=n;i++)cin>>a[i];
    build(1, 1, n);
    buildSum(1, 1, n);
    ll previous = 1;
    for(int i=1;i<=n;i++){
        pii l, r;
        l = query(1, 1, n, 1, previous-1);
        r = query(1, 1, n, previous, n);
        if(l.ff >= r.ff){
            ans += querySum(1, 1, n, previous, r.ss);
            previous = r.ss;
        }
        else{
            ans += querySum(1, 1, n, previous, n) + querySum(1, 1, n, 1, l.ss);
            previous = l.ss;
        }
        update(1, 1, n, previous);
    }
    cout<< ans<< endl;
    return 0;
}
