#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#define set0(x) memset(x,0,sizeof x)
#include <bits/stdc++.h>
using namespace std;



int a[MX],sum[(MX*4)];


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

void build(int node,int start, int end){
    if(start == end){
        sum[node] = a[start];
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = min( sum[node*2], sum[(node*2)+1] );
}


int main(int argc, char const *argv[]) {
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        set0(a); set0(sum);
        int n,q;
        scanf("%d%d", &n, &q);
        printf("Scenario #%d:\n", ii);
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        build(1,1,n);
        for(int i=1;i<=q;i++){
            int l, r, ans;
            scanf("%d%d", &l, &r);
            ans = query(1,1,n,l,r);
            printf("%d\n", ans);
        }
    }

}
