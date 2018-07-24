#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;

vector<int>sum[(4*MX)];
int a[MX];

vector<int> merge(vector<int>m1,vector<int>m2){
    vector<int>temp;
    int sz1, sz2, pnt1, pnt2 ;
    pnt1 = pnt2 = 0; sz1 = m1.size(); sz2 = m2.size();
    for(int i=1;i<= (sz1+sz2) ;i++){
        if(m1[pnt1]<=m2[pnt2]){
            temp.pb(m1[pnt1]);
            pnt1++;
        }
        else{
            temp.pb(m2[pnt2]);
            pnt2++;
        }
        if(pnt1==sz1 || pnt2==sz2)break;
    }
    while(pnt1<sz1){
        temp.pb(m1[pnt1]);
        pnt1++;
    }
    while(pnt2<sz2){
        temp.pb(m2[pnt2]);
        pnt2++;
    }
    return temp;
}

void build(int node, int start, int end){
    if(start == end){
        sum[node].pb(a[start]);
        return ;
    }
    int mid = (start + end) / 2;
    build(node*2, start, mid);
    build((node*2)+1 , mid+1, end);
    sum[node] = merge(sum[node*2],sum[(node*2)+1]);
}

int query(int node, int start, int end, int i, int j, int k){
    if(start>j || end<i || start>end)return 0;
    if(i<=start && end<=j){
        int idx = upper_bound(sum[node].begin(),sum[node].end(),k) - sum[node].begin();
        return idx;
    }
    int p,q;
    int mid = (start+end) / 2;
    p = query(node*2 ,start, mid, i, j, k);
    q = query((node*2)+1, mid+1, end, i, j, k);
    return p+q;
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
        int x,y,z,ans;
        scanf("%d%d%d", &x, &y, &z);
        ans = query(1,1,n,x,y,z);
        printf("%d\n", ans);
    }
    return 0;
}
