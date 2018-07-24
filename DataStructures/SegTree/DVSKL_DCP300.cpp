#include<bits/stdc++.h>
using namespace std;
#define MX 100006
int arr[MX];
int tree[MX*3];
void init(int node, int b, int e)
{
    if(b==e)
    {
        if(arr[b]==0)tree[node]=1;
        return ;
    }
    int left,right,mid;
    left=(2*node);
    right=(2*node)+1;
    mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node]=tree[left]+tree[right];
}
void update(int node, int b, int e, int i)
{
    if (i > e || i < b)
        return;
    if (b >= i && e <= i)
    {
        if(tree[node])tree[node] =0;
        else tree[node] =1;
        return;
    }
    int Left = node * 2;
    int Right = node * 2 + 1;
    int mid = (b + e) / 2;
    update(Left, b, mid, i);
    update(Right, mid + 1, e, i);
    tree[node] = tree[Left] + tree[Right];
}
int query(int node, int b, int e, int i, int j)
{
    if(i>e || j<b)
    {
        return 0;
    }
    if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left,right,mid;
    left=(2*node);
    right=(2*node)+1;
    mid = (b+e)/2;
    int p1=query(left,b,mid,i,j);
    int p2=query(right,mid+1,e,i,j);
    return (p1+p2);
}
int main()
{


    int n,m,a,b,ans,x,y;
    string s;
    scanf("%d%d",&n,&m);
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='0')arr[i+1]=0;
        else arr[i+1]=1;
    }
    init(1,1,n);
    for(int i=1; i<=m; i++)
    {
        cin>>x;
        if(x==1){
            cin>>x;
            update(1,1,n,x);
        }
        else {
            cin>>x>>y;
            cout<<query(1,1,n,x,y)+1<<endl;
        }
    }

    return 0;
}
