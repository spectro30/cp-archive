#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#define set0(x) memset(x,0,sizeof x)
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[(MX*4)],lazy[(MX*4)];

void relax(int node, int start, int end){
    sum[node] = (end - start + 1) * lazy[node];
    if(start != end){
        lazy[2*node] = lazy[node];
        lazy[(2*node)+1] = lazy[node];
    }
    lazy[node] = -1;
}

void update(int node, int start, int end, int i, int j, int val){
    if(lazy[node] != -1)relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node] = val;
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i, j, val);
    update((node*2)+1, mid+1, end, i, j, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int query(int node, int start, int end, int i, int j){
    if(lazy[node] != -1)relax(node,start,end);
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return p+q;
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        printf("Case %d:\n", ii);
        set0(sum);memset(lazy,-1,sizeof lazy);
        int n, q;
        scanf("%d%d", &n, &q);
        for(int i=1;i<=q;i++){
            int f,l,r,x,g,y;
            scanf("%d", &f);
            if(f == 1){
                scanf("%d%d%d", &l, &r, &x);
                update(1,1,n,l+1,r+1,x);
            }
            else{
                scanf("%d%d", &l, &r);
                x = query(1,1,n,l+1,r+1);
                y = r - l + 1;
                g = __gcd(x,y);
                x /= g;
                y /= g;
                printf("%d", x);
                if(y>1)printf("/%d\n", y);
                else printf("\n");
            }
        }
    }
    return 0;


}
