#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[(MX*4)];

void build(int node, int start, int end){
    if(start == end){
        sum[node] = a[end];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = min(sum[node*2] , sum[(node*2)+1]);
}

int query(int node, int start, int end, int i, int j){
    if(start>j || end<i || start>end)return INT_MAX;
    if(i<=start && end<=j){
        return sum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return min(p,q);
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);

    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i=1;i<=n;i++){
            scanf("%d", &a[i]);
        }
        build(1,1,n);
        printf("Case %d:\n",ii);
        for(int i=1;i<=q;i++){
            int l, r, ans;
            scanf("%d%d", &l, &r);
            ans = query(1,1,n,l,r);
            printf("%d\n",ans);
        }
    }
    return 0;
}
