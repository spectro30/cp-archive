#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int par[MAX];
int find(int a)
{
    if(par[a]==a)
        return a;

    return par[a]=find(par[a]);;
}
void un(int a,int b)
{
    int u=find(a);
    int v=find(b);
    if(u!=v)
        par[v]=u;
}
int main()
{
    vector<int>v;
    int n,e;
    char nn;
    cin>>nn;
    n=nn-'A'+1;
    for(int i=0;i<=n;i++)
        par[i]=i;
    int a,b;
    char aa,bb;
    for(int i=0;i<4;i++)
    {
        cin>>aa>>bb;
        a=aa-'A'+1;
        b=bb-'A'+1;
        un(a,b);
    }
    for(int i=0;i<=n;i++)v.push_back(find(i));
    int pal=1,mx=0;
    sort(v.begin(),v.end());
        for(int i=1;i<=n;i++){
        if(v[i]==v[i+1]){
            pal++;
        }
        else{
            mx=max(pal,mx);
            pal=1;
        }
    }
    cout<<mx;
}
