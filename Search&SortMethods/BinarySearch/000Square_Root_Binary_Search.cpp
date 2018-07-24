#include<bits/stdc++.h>
using namespace std;
double squrt(double n)
{
    double high,low,mid;
    low=0.0;
    high=n;
    while(high- low >0.00000000000001){
        mid=(high+low)/2;
        //cout<<high<<" "<<low<<" "<<mid<<" "<<mid*mid<<endl;
        if(mid*mid>n)high=mid;
        else low=mid;

    }
    return mid;
}
double mysqrt(double n)
{
    double high,low,mid;
    low=0.0;
    high=n;
    for(int i=0;i<=64;i++){
        mid=(high+low)/2;
        //cout<<high<<" "<<low<<" "<<mid<<" "<<mid*mid<<endl;
        if(mid*mid>n)high=mid;
        else low=mid;

    }
    return mid;
}
int main()
{
    int n;
    cin>>n;
    printf("%.100lf\n",mysqrt(n));
    printf("%.100lf\n",squrt(n));
}
