#define pb push_back
#define ff first
#define ss second
#define ll long long
#define set0(x)  memset(x,0,sizeof x)
#define MX 1000005
#include <bits/stdc++.h>
using namespace std;

ll numDiffPF[MX+5], mobius[MX+5], mertens[MX+5];
bool squFree[MX+5];

int wordSize(ll n){
    int temp = 0;
    if(n<=0)temp++;
    n = abs(n);
    while(n){
        temp++;
        n/=10;
    }
    return 8-temp;
}

int main(int argc, char const *argv[]) {
    numDiffPF[1] = 1;
    for(int i = 2; i<=MX ; i++){
        if(!numDiffPF[i]){
            for(int j=i;j<=MX;j+=i){
                if(j%(i*i) == 0)squFree[j] = true;
                numDiffPF[j] ++;
            }
        }
    }
    mobius[1] = 1;
    for(int i=2;i<=MX;i++){
        if(squFree[i]){
            mobius[i] = 0;
        }
        else if(numDiffPF[i] % 2) mobius[i] = -1;
        else mobius[i] = 1;
    }
    for(int i=1;i<=MX;i++){
        mertens[i] = mertens[i-1] + mobius[i];
    }
    while(1){
        ll n, ans = 0;
        scanf("%lld", &n);
        if(!n)break;
        //cout<<n<<" "<<mobius[n]<<" "<<mertens[n]<<endl;
        for(int i=1;i<=wordSize(n);i++)printf(" ");printf("%lld",n);
        for(int i=1;i<=wordSize(mobius[n]);i++)printf(" ");printf("%lld",mobius[n]);
        for(int i=1;i<=wordSize(mertens[n]);i++)printf(" ");printf("%lld\n",mertens[n]);
    }
    return 0;
}
