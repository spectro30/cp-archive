//Modified Sieve

#define pb push_back
#define ff first
#define ss second
#define ll long long
#define set0(x)  memset(x,0,sizeof x)
#define MX 1000005
#include <bits/stdc++.h>
using namespace std;

ll numDiffPF[MX+5];

int main(int argc, char const *argv[]) {
    numDiffPF[1] = 1;
    for(int i = 2; i<=MX ; i++){
        if(!numDiffPF[i]){
            for(int j=i;j<=MX;j+=i){
                numDiffPF[j] ++;
            }
        }
    }
    while(1){
        ll n, ans = 0;
        scanf("%lld", &n);
        if(!n)break;
        printf("%lld : %lld\n", n, numDiffPF[n]);

    }
    return 0;
}
