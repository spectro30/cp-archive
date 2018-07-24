#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#define NEG_MAX (-1)*INT_MAX
#include <bits/stdc++.h>
using namespace std;

struct data{
    ll sum, pref, suff, ans;
};
ll a[MX];
data t[(4*MX)];

data make_data(ll val){
    data res;
    res.sum = val;
    res.pref = res.suff = res.ans = val;
    return res;
}

data combine(data l, data r){
    data res;
    res.sum = l.sum + r.sum;
    res.pref = max(l.pref, l.sum + r.pref);
    res.suff = max(r.suff, r.sum + l.suff);
    res.ans = max(max(l.ans, r.ans), l.suff+  r.pref);
    return res;
}

data update(ll v, ll tl, ll tr, ll pos, ll new_val){
    if(tl == tr){
        t[v] = make_data(new_val);
    } else{
        ll tm = (tl + tr) / 2;
        if(pos <= tm){
            update(v*2, tl, tm, pos, new_val);
        } else{
            update(v*2+1, tm+1, tr, pos, new_val);
        }
        t[v] = combine(t[v*2], t[v*2+1]);
    }
}

data query(ll v, ll tl, ll tr, ll l, ll r){
    if(l > r) return make_data( NEG_MAX );
    if(l == tl && r == tr) return t[v];
    ll tm = (tr + tl) / 2;
    return combine(query(v*2, tl, tm, l, min(r,tm)),
                   query(v*2+1, tm+1, tr, max(l, tm+1), r));
}


void build(ll v, ll tl, ll tr){
    if(tl ==  tr){
        t[v] = make_data(a[tl]);
        return;
    }
    ll tm = (tl + tr) / 2;
    build(v*2 , tl, tm);
    build( v*2+1, tm+1, tr);
    t[v] = combine(t[v*2], t[v*2+1]);
}

int main(int argc, char const *argv[]) {
    ll n;
    scanf("%lld", &n);
    for(int i=1;i<=n;i++){
        scanf("%lld", &a[i]);
    }
    build(1, 1, n);
    ll q;
    scanf("%lld", &q);
    for(int i=1;i<=q;i++){
        ll l,r,f;
        scanf("%lld", &f);
        if(f==0){
            scanf("%lld%lld", &l, &r);
            update(1, 1, n, l, r);
        }
        else{
            scanf("%lld%lld", &l, &r);
            data f = query(1, 1, n, l, r);
            printf("%lld\n", f.ans);
        }
    }

    return 0;
}
