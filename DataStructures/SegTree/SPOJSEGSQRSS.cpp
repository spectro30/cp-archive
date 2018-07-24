#define pb push_back
#define ff first
#define ss second
#define ll long long
#define set0(x)  memset(x,0,sizeof x)
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[(MX*4)],sqsum[(MX*4)];
vector< pair<int, int> > lazy[(MX*4)];

void relax(int node, int start, int end){
    int sz = (end - start + 1);
    for(int i=0;i<lazy[node].size();i++){
        if(lazy[node][i].ss){
            sqsum[node] += (2 * lazy[node][i].ff * sum[node]) + (sz * lazy[node][i].ff * lazy[node][i].ff);
            sum[node] += sz * lazy[node][i].ff;
        }
        else{
            sum[node] = sz * lazy[node][i].ff;
            sqsum[node] = sz * lazy[node][i].ff * lazy[node][i].ff;

        }
        if(start != end){
            lazy[2*node].pb(make_pair(lazy[node][i].ff,lazy[node][i].ss));
            lazy[(2*node)+1].pb(make_pair(lazy[node][i].ff,lazy[node][i].ss));
        }
    }

    lazy[node].clear();

}


void build(int node, int start, int end){
    if(start == end){
        sum[node] = a[start];
        sqsum[node] = a[start]*a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
    sqsum[node] = sqsum[node*2] + sqsum[(node*2)+1];
}

void updateAdd(int node, int start, int end, int i, int j, int val){
    if(!lazy[node].empty())relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node].pb(make_pair(val,1));
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    updateAdd(node*2, start, mid, i, j, val);
    updateAdd((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
    sqsum[node] = sqsum[node*2] + sqsum[(node*2)+1];
}

void updateSet(int node, int start, int end, int i, int j, int val){
    if(!lazy[node].empty())relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node].pb(make_pair(val,0));
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    updateSet(node*2, start, mid, i, j, val);
    updateSet((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
    sqsum[node] = sqsum[node*2] + sqsum[(node*2)+1];
}

int query(int node, int start, int end, int i, int j){
    if(!lazy[node].empty())relax(node,start,end);
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sqsum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return p+q;
}

int main(int argc, char const *argv[]) {
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        set0(a);set0(sum);set0(sqsum);
        int n,q;
        scanf("%d%d", &n, &q);
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        build(1,1,n);
        printf("Case %d:\n", ii);
        for(int i=1;i<=q;i++){
            int f,l,r,x,ans;
            scanf("%d", &f);
            if(f==2){
                scanf("%d%d", &l, &r);
                ans = query(1,1,n,l,r);
                printf("%d\n", ans);
            }
            else if(f==1){
                scanf("%d%d%d", &l, &r, &x);
                updateAdd(1,1,n,l,r,x);
            }
            else{
                scanf("%d%d%d", &l, &r, &x);
                updateSet(1,1,n,l,r,x);
            }
        }
    }
    return 0;
}
