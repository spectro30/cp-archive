#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;


//-------------LCA Starts Here-------------//
///ne = euler Size//---Clear these if TC---//
vector<int> ed[MX], euler;
int frstOc[MX], hgt[MX], ne, LCAsum[(4*MX)], LCAvisited[MX];

void LCAdfs(int node, int h){
    LCAvisited[node] = 1;
    hgt[node] = h;
    frstOc[node] = euler.size();
    euler.pb(node);
    for(int i=0;i<ed[node].size();i++){
        if(LCAvisited[ed[node][i]])continue;
        LCAdfs(ed[node][i],h+1);
        euler.pb(node);
    }
}

void LCAbuild(int node, int start, int end){
    if(start == end){
        LCAsum[node] = euler[start];
        return;
    }
    int mid = (start + end) / 2;
    LCAbuild(node*2, start, mid);
    LCAbuild((node*2)+1 , mid+1, end);
    LCAsum[node] = min(LCAsum[node*2] , LCAsum[(node*2)+1]);
}

int LCAquery(int node, int start, int end, int i, int j){
    if(start>j || end<i || start>end)return INT_MAX;
    if(i<=start && end<=j){
        return LCAsum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = LCAquery(node*2 ,start, mid, i, j);
    q = LCAquery((node*2)+1, mid+1, end, i, j);
    return min(p,q);
}

void LCAinit(int root){
    LCAdfs(root,0);
    ne = euler.size();
    LCAbuild(1,1,ne);
}

int LCA(int x, int y){
    if(x == y)return x;
    int left, right;
    left = frstOc[x];
    right = frstOc[y];
    if(left>right)swap(left,right);
    return LCAquery(1,1,ne,left,right);
}


//------------------LCA Ends Here-------///

int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for(int i=0;i<n;i++)ed[i].clear();
    for(int i=0;i<n;i++){
        int x,t;
        scanf("%d", &x);
        for(int j=1;j<=x;j++){
            scanf("%d", &t);
            ed[i].pb(t);
            ed[t].pb(i);
        }
    }
    LCAinit(0);
    int q;
    scanf("%d", &q);
    for(int i=1;i<=q;i++){
        int l,r;
        scanf("%d%d", &l, &r);
        printf("%d\n", LCA(l,r));
    }

    return 0;
}
