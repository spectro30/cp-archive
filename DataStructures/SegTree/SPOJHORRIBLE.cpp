#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

ll a[MX],sum[(MX*4)],lazy[(MX*4)];

void relax(int node, int start, int end){
    sum[node] += (end - start + 1) * lazy[node];
    if(start != end){
        lazy[2*node] += lazy[node];
        lazy[(2*node)+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int start, int end, int i, int j, ll val){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node] += val;
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i, j, val);
    update((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

ll query(int node, int start, int end, int i, int j){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sum[node];
    }
    ll p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return p+q;
}

void build(int node,int start, int end){
    if(start == end){
        sum[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}


int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        memset(a,0,sizeof a);
        memset(sum,0,sizeof sum);
        memset(lazy,0,sizeof lazy);
        int n,q,x,y,val;
        ll ans;
        scanf("%d%d", &n, &q);
        build(1,1,n);
        for(int i=1;i<=q;i++){
            scanf("%d", &x);
            if(!x){
                scanf("%d%d%d", &x, &y, &val);
                update(1,1,n,x,y,val);
            }
            else{
                scanf("%d%d", &x, &y);
                ans = query(1,1,n,x,y);
                printf("%lld\n", ans);
            }
        }
    }


}
