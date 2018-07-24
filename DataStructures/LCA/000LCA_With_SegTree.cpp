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
int frstOc[MX], hgt[MX], ne, LCAsum[(4*MX)];
bool LCAvisited[MX];

void LCAdfs(int node, int h){
    LCAvisited[node] = true;
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
        LCAsum[node] = euler[start-1];
        return;
    }
    int mid = (start + end) / 2;
    LCAbuild(node*2, start, mid);
    LCAbuild((node*2)+1 , mid+1, end);
    if(hgt[node*2] >= hgt[(node*2)+1]) LCAsum[node] = LCAsum[(node*2)+1];
    else LCAsum[node] = LCAsum[node*2];
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

void LCAclear(){
    euler.clear();
    memset(frstOc, 0, sizeof frstOc);
    memset(hgt, 0, sizeof hgt);
    memset(LCAsum, 0, sizeof LCAsum);
    memset(LCAvisited, 0, sizeof LCAvisited);

}

void LCAinit(int root){
    LCAclear();
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
    int n,x,y,q,ans;
    scanf("%d", &n);
    for(int i=1;i<n;i++){
        scanf("%d%d", &x, &y);
        ed[x].pb(y);
        ed[y].pb(x);
    }
    LCAinit(1);
    for(int i=0;i<ne;i++){
        cout<<euler[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){
        cout<<frstOc[i]<<" ";
    }
    cout<<endl;
    scanf("%d", &q);
    for(int i=1;i<=q;i++){
        scanf("%d%d", &x, &y);
        ans = LCA(x,y);
        printf("%d\n", ans);
    }

    return 0;
}
