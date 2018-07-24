#include<bits/stdc++.h>
using namespace std;
int segtree[300000];
int ara[300000];
int lazy[300000];
void relax(int node,int beg,int ed)
{
    int mid=(beg+ed)/2;
    int lft=2*node;
    int rgh=2*node+1;
    lazy[rgh]+=lazy[node];
    lazy[lft]+=lazy[node];
    segtree[node]+=(ed-beg+1)*lazy[node];
    lazy[node]=0;
}

void init(int node,int beg,int ed)
{
    if(beg>ed)return;
    if(beg==ed){
        segtree[node]=ara[beg];
        return;
    }
    int mid=(beg+ed)/2;
    int lft=2*node;
    int rgh=2*node+1;
    init(lft,beg,mid);
    init(rgh,mid+1,ed);
    segtree[node]=segtree[lft]+segtree[rgh];
}

int query(int node,int beg,int ed,int i,int j)
{
    if(lazy[node])relax(node,beg,ed);
    if(beg>ed || beg>j || ed<i)return 0;
    if(beg>=i && ed<=j)return segtree[node];
    int p=0,q=0;
    int mid=(beg+ed)/2;
    int lft=2*node;
    int rgh=2*node+1;
    p=query(lft,beg,mid,i,j);
    q=query(rgh,mid+1,ed,i,j);
    return (p+q);
}

void update(int node,int beg,int ed,int i,int j,int val)
{
    if(beg>ed || beg>j || ed<i)return;
    if(beg>=i && ed<=j){
        lazy[node]+=val;
        relax(node,beg,ed);
        return;
    }
    int mid=(beg+ed)/2;
    int lft=2*node;
    int rgh=2*node+1;
    update(lft,beg,mid,i,j,val);
    update(rgh,mid+1,ed,i,j,val);
    segtree[node]=segtree[lft]+segtree[rgh];
}

int main()
{
    int n,q,x,y,z,ch;
    cin>>n;
    for(int i=1;i<=n;i++)cin>>ara[i];
    init(1,1,n);
    cin>>q;
    for(int i=1;i<=q;i++){
        cin>>ch;
        if(ch==1){
            cin>>x>>y>>z;
            update(1,1,n,x,y,z);
        }
        else{
            cin>>x>>y;
            cout<<query(1,1,n,x,y)<<endl;
        }
    }
    return 0;
}
