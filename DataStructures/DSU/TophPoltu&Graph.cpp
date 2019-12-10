#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
#define ff first
#define pb push_back
#define ss second
#define maxn 200005
using namespace std;


int res[maxn], pt, par[maxn], sz[maxn];
vector< pair<int, pair<int, int> > >  v, p;

void initDSU(int x){
    for(int i=1;i<=x;i++){
        par[i] = i;
        sz[i] = 1;
    }
}

int rep(int x){
    if(par[x] == x) return x;
    return par[x] = rep(par[x]);
}

void join(int x, int y){
    int pa, pb;
    pa = rep(x);
    pb = rep(y);
    if(pa != pb){
        par[pa] = par[pb];
        sz[pb] += sz[pa];
    }
}

int main() {
    int n, m, q;
    cin >> n >> m;
    initDSU(n);
    for(int i=1;i<=m;i++){
        int x, y, w;
        cin >> x >> y >> w;
        v.pb({w, {x, y}});
    }
    sort(v.begin(), v.end());
    cin >> q;
    for(int i=1;i<=q;i++){
        int x, w;
        cin >> x >> w;
        p.pb({w, {x, i}});
    }
    sort(p.begin(), p.end());
    for(int i=0;i<q;i++){
        int x, w, pos;
        x = p[i].ss.ff;
        pos = p[i].ss.ss;
        w = p[i].ff;
        while(pt<n && v[pt].ff<=w){
            join(v[pt].ss.ff, v[pt].ss.ss);
            pt++;
        }
        int bp = rep(x);
        res[pos] = sz[bp];
    }
    for(int i=1;i<=q;i++){
        cout << res[i] << endl;
    }

    return 0;
}
