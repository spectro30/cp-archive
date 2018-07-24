#include<bits/stdc++.h>
using namespace std;
typedef long long unsigned llu;
typedef long long ll;
int used[20],number[20];
int cnt=0;
char a[20];
void permutation(int rec,int n)
{
    if(rec==n+1){
        cnt++;
        for(int i=1;i<=n;i++){
            cout<<a[number[i]-1];//for number just print number[i]
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)if(!used[i]){
        used[i]=1;
        number[rec]=i;
        permutation(rec+1,n);
        used[i]=0;
    }
}
int main ()
{
    int n;
    gets(a);
    n=strlen(a);
    permutation(1,n);
    cout<<cnt;
    cnt=0;
    memset(number,0,sizeof(number));
}
