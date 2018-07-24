#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

int a[MX],sumMax[(MX*4)],sumMin[(MX*4)];

void buildMax(int node, int start, int end){
    if(start == end){
        sumMax[node] = a[start];
        return ;
    }
    int mid = (start + end) / 2;
    buildMax(node*2, start, mid);
    buildMax((node*2)+1 , mid+1, end);
    sumMax[node] = max(sumMax[node*2],sumMax[(node*2)+1]);
}

void buildMin(int node, int start, int end){
    if(start == end){
        sumMin[node] = a[start];
        return ;
    }
    int mid = (start + end) / 2;
    buildMin(node*2, start, mid);
    buildMin((node*2)+1 , mid+1, end);
    sumMin[node] = min(sumMin[node*2],sumMin[(node*2)+1]);
}

int queryMax(int node, int start, int end, int i, int j){
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        return sumMax[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = queryMax(node*2 ,start, mid, i, j);
    q = queryMax((node*2)+1, mid+1, end, i, j);
    return max(p,q);
}

int queryMin(int node, int start, int end, int i, int j){
    if(start>j || end<i || start>end)return INT_MAX;
    if(i<=start && end<=j){
        return sumMin[node];
    }
    int p,q;
    int mid = (start+end) / 2;
    p = queryMin(node*2 ,start, mid, i, j);
    q = queryMin((node*2)+1, mid+1, end, i, j);
    return min(p,q);
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);
    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        int n,d,mx=0;
        scanf("%d%d", &n, &d);
        for(int i=1;i<=n;i++)scanf("%d", &a[i]);
        buildMin(1,1,n);
        buildMax(1,1,n);
        for(int i=1;i<=(n-d+1);i++){
            mx = max(mx, (queryMax(1,1,n,i,i+d-1)-queryMin(1,1,n,i,i+d-1)));
        }
        printf("Case %d: %d\n", ii, mx);
    }


}
