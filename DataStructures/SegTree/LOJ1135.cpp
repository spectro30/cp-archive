#define pb push_back
#define ff first
#define ss second
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[3][(MX*4)],lazy[(MX*4)],temp[3];

void relax(int node, int start, int end){
    memset(temp, 0, sizeof temp);
    for(int i=0;i<3;i++){
        int idx = (i + lazy[node]) % 3;
        temp[idx] = sum[i][node];
    }
    for(int i=0;i<3;i++)sum[i][node] = temp[i];
    if(start != end){
        lazy[2*node] += lazy[node];
        lazy[(2*node)+1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int start, int end){
    if(start == end){
        int idx = a[start] % 3;
        sum[idx][node] = 1;
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    for(int i=0;i<3;i++){
        sum[i][node] = sum[i][node*2] + sum[i][(node*2)+1];
    }
}

void update(int node, int start, int end, int i, int j){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return ;
    if(i<=start && end<=j){
        lazy[node] ++;
        relax(node,start,end);
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i , j);
    update((node*2)+1 , mid+1, end, i, j);
    for(int i=0;i<3;i++){
        sum[i][node] = sum[i][node*2] + sum[i][(node*2)+1];
    }
}

int query(int node, int start, int end, int i, int j){
    if(lazy[node])relax(node,start,end);
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sum[0][node];
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
        mem(a);mem(sum);mem(lazy);
        int n,q;
        scanf("%d%d", &n, &q);
        build(1,1,n);
        printf("Case %d:\n", ii);
        for(int i=1;i<=q;i++){
            int f,x,y;
            scanf("%d", &f);
            if(!f){
                scanf("%d%d", &x, &y);x++;y++;
                update(1,1,n,x,y);
            }
            else{
                scanf("%d%d", &x, &y);x++;y++;
                int ans = query(1,1,n,x,y);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
