#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;



int a[MX];
pair<int,int> sum[MX*4];

pair<int,int> combine(pair<int,int> l, pair<int,int> r){
    pair<int,int> res;
    vector<int>v;
    v.pb(l.ff); v.pb(l.ss); v.pb(r.ff); v.pb(r.ss);
    sort(v.begin(),v.end());
    res = make_pair(v[2],v[3]);
    return res;
}

void update(int node, int start, int end, int i, int val){
    if(start>i || end<i || start>end)return ;
    if(i<=start && end<=i){
        sum[node].ff = val;
        sum[node].ss = 0;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i, val);
    update((node*2)+1, mid+1, end, i, val);
    sum[node] = combine(sum[node*2] , sum[node*2+1] );
}

pair<int,int> query(int node, int start, int end, int i, int j){
    pair <int,int> temp;
    if(start>j || end<i || start>end)return temp = make_pair(0,0) ;
    if(i<=start && end<=j){
        return sum[node];
    }

    pair<int,int> p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j);
    q = query((node*2)+1, mid+1, end, i, j);
    return combine(p,q);
}

void build(int node,int start, int end){
    if(start == end){
        sum[node].ff = a[start];
        sum[node].ss = 0;
        return;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = combine(sum[node*2] , sum[node*2+1] );
}


int main(int argc, char const *argv[]) {
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
    }
    build(1,1,n);
    int q;
    scanf("%d", &q);
    for(int i=1;i<=q;i++){
        int l,r;
        char c;
        getchar();
        scanf("%c", &c);
        if(c=='Q'){
            scanf("%d%d", &l, &r);
            pair<int,int> ans;
            ans = query(1, 1, n, l, r);
            printf("%d\n",ans.ff + ans.ss);
        }
        else{
            scanf("%d%d", &l, &r);
            update(1, 1, n, l, r);
        }
    }

}
