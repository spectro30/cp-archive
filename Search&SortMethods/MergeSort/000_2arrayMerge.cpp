#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int x,y;
    x=0,y=0;
    for(int i=0;i<(2*n);i++){
        if(a[x]>=b[y]){
            c[i]=b[y];
            y++;
        }
        else if(a[x]<b[y]){
            c[i]=a[x];
            x++;
        }
    }

    for(int i=0;i<(2*n);i++){
        cout<<c[i]<<" ";
    }

    return 0;
}
