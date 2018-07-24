#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 100005
#define set0(x) memset(x,0,sizeof x)
#include <bits/stdc++.h>
using namespace std;

int a[MX],sum[(MX*4)],arr[MX],pos[MX],n,q;
vector<int>v[MX];
vector< pair< int, pair<int,int> > > qr;
vector<pair<int,int> > ans;
map<int,int>mp;

void clearAll(){
    set0(a); set0(sum); set0(arr); set0(pos);
    for(int i=0;i<=MX;i++)v[i].clear();
    qr.clear(); ans.clear(); mp.clear();
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

void update(int node, int start, int end, int i, int val){
    if(start>i || end<i)return;
    if(start == end){
        sum[node] = val;
        return;
    }
    int mid = (start + end) / 2;
    update(node*2, start, mid, i,val);
    update((node*2)+1, mid+1, end, i, val);
    sum[node] = sum[node*2] + sum[(node*2)+1];
}

void findNext(int next){
    if(pos[next] >= v[next].size())return;
    update(1,1,n,v[next][pos[next]-1],0);
    update(1,1,n,v[next][pos[next]],1);
    pos[next] ++;
}

int main(int argc, char const *argv[]) {
    //freopen("0uput.txt","w",stdout);

    int TC;
    scanf("%d", &TC);
    for(int ii=1;ii<=TC;ii++){
        clearAll();
        scanf("%d%d", &n, &q);
        for(int i=1;i<=n;i++)scanf("%d", &arr[i]);
        for(int i=1;i<=n;i++){
            if(!mp[arr[i]]){
                mp[arr[i]] = 1;
                a[i] = 1;
                pos[arr[i]] = 1;
            }
        }
        build(1,1,n);
        for(int i=1;i<=n;i++){
            v[arr[i]].pb(i);
        }
        for(int i=1;i<=q;i++){
            int l,r;
            scanf("%d%d", &l, &r);
            qr.pb(make_pair(l,make_pair(r,i)));
        }
        printf("Case %d:\n", ii);
        sort(qr.begin(),qr.end());
        int prev  = 0;
        for(int i=0;i<q;i++){
            for(int j=prev+1;j<qr[i].ff;j++){
                findNext(arr[j]);
            }
            int temp ;
            temp = query(1,1,n,qr[i].ff,qr[i].ss.ff);
            ans.pb(make_pair(qr[i].ss.ss,temp));
            prev = qr[i].ff-1;
        }
        sort(ans.begin(),ans.end());
        for(int i=0;i<q;i++){
            printf("%d\n",ans[i].ss);
        }
    }

    return 0;


}
