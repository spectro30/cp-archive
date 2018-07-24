#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;
int a[MX],sum[(MX*4)],lazy[(MX*4)];

void relax(int node, int start, int end){
    if(lazy[node]%2)sum[node] = (end-start+1) - sum[node];
    if(start != end){
        lazy[2*node] += lazy[node];
        lazy[(2*node)+1] += lazy[node];
    }
    lazy[node] = 0;
}

void build(int node, int start, int end){
    if(start == end){
        sum[node] = a[start];
        return ;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = sum[node*2] + sum[(node*2)+1];
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
    update(node*2, start, mid, i, j);
    update((node*2)+1, mid+1, end, i, j);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int query(int node, int start, int end, int x){
    if(lazy[node])relax(node,start,end);
    if(start>x || end<x)return 0;
    if(start == end){
        return sum[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, x);
    q = query((node*2)+1, mid+1, end, x);
    return p+q;

}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);

    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        memset(a,0, sizeof a);
        memset(sum,0, sizeof sum);
        memset(lazy,0, sizeof lazy);
        string s;
        cin >> s;
        int n,q,ans;
        n = s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='1')a[i+1] = 1;
        }
        scanf("%d", &q);
        build(1,1,n);
        printf("Case %d:\n",ii);
        for(int i=1;i<=q;i++){
            char c;
            scanf(" %c", &c);
            if(c=='I'){
                int l,r;
                scanf("%d%d", &l, &r);
                update(1,1,n,l,r);
            }
            else{
                int x;
                scanf("%d", &x);
                ans = query(1,1,n,x);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}
