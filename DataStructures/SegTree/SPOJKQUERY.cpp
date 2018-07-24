#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#include <bits/stdc++.h>
using namespace std;
vector< pair< pair<int,int> , pair< int,int> > > v;
vector<pair<int,int> > val,ans;
int a[MX],cnt,sum[(MX*4)];

void update(int node, int start, int end, int x){
    if(start>x || end<x)return;
    if(start == end){
        sum[node] = 1;
        return ;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, x);
    update((node*2)+1, mid+1, end, x);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

int query(int node, int start, int end, int i, int j){
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
    int n;
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d", &a[i]);
        val.pb(make_pair(a[i],i));
    }
    int q;
    scanf("%d", &q);
    for(int i=1;i<=q;i++){
        int x,y,z,ans;
        scanf("%d%d%d", &x, &y, &z);
        v.pb(make_pair(make_pair(z,i),make_pair(x,y)));
    }
    sort(v.rbegin(),v.rend());
    sort(val.rbegin(),val.rend());
    for(int i=0;i<q;i++){
        int l,r,k,pos,temp;
        k = v[i].ff.ff;
        pos = v[i].ff.ss;
        l = v[i].ss.ff;
        r = v[i].ss.ss;
        temp = cnt;
        for(int j=temp;j<n;j++){
            if(k>=val[j].ff)break;
            else{
                update(1,1,n,val[j].ss);
                cnt++;
            }
        }
        int qq = query(1,1,n,l,r);
        ans.pb(make_pair(pos,qq));
    }
    sort(ans.begin(),ans.end());
    for(int i=0;i<q;i++){
        printf("%d\n",ans[i].ss);
    }
    return 0;
}
