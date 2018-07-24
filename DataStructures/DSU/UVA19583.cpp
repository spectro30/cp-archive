#include<bits/stdc++.h>
using namespace std;
int par[10000];
int findd(int r)
{
    if (par[r]==r) return r;
    par[r]=findd(par[r]);
    return par[r];
}
int unionn(int a,int b)
{
    int u=findd(a);
    int v=findd(b);
    par[u]=v;
}
int main()
{
    //freopen("output.txt","w",stdout);
    int TC;
    cin>>TC;
    for(int k=0;k<TC;k++){
        int n,e,x,y;
        cin>>n>>e;
        vector<int>v;
        for(int i=1; i<=n; i++)
        {
            par [i] = i;
        }
        for(int i=0;i<e;i++){
            cin>>x>>y;
            unionn(x,y);
        }
        for(int i=1; i<=n; i++){
            v.push_back(findd(i));
        }
        map<int,int>ms;
        int ans=0;
        for(int i=0;i<v.size();i++){
            ms[v[i]]++;
        }
        for(int i=0;i<v.size();i++){
            ans=max(ans,ms[v[i]]);
        }
        cout<<ans<<endl;
        v.clear();
        par[10000]= {0};
    }
    return 0;
}



