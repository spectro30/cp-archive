#include<bits/stdc++.h>
using namespace std;
int cnt=0;
int fib(int n)
{
    cnt++;
    if(n<=1)return n;
    return fib(n-1)+fib(n-2);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)cout<<fib(i)<<" ";

}


