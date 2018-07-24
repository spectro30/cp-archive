#include<bits/stdc++.h>
using namespace std;
int recfact(int n)
{
    int sum;
    if(n==1)return n;
    sum=n*recfact(n-1);
    return sum;
}
int shortfact(int n)
{
    if (n==1) return n;
    return n*shortfact(n-1);
}
int main()
{
    int n;
    cin>>n;
    cout<<recfact(n)<<endl;
    cout<<shortfact(n)<<endl;
}
