#define pb push_back
#define ff first
#define ss second
#define ll long long
#define set0(x)  memset(x,0,sizeof x)
#include <bits/stdc++.h>
using namespace std;
// 1 2 5 4

int main(int argc, char const *argv[]) {
    while(1){
        ll x1, x2, y1, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
        if(!x1 && !x2 && !y1 && !y2)break;
        if(x1> x2){
            swap(y1, y2);
            swap(x1, x2);
        }
        if(x1 == x2){
            printf("%lld\n", abs(y2-y1));
            continue;
        }
        else if(y1 == y2){
            if(y1 % 2){
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", ((x2-x1)*2) );
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+1 );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 );
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2)+1 );
                    }
                }
            }
            else {
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", (x2-x1)*2 );
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2)+1 );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 );
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+1 );
                    }
                }
            }
            continue;
        }

        if(abs(y2 - y1) == 1){
            if(y1 % 2){
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", (x2-x1)*2 -1 );
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+2 );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 +1);
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2) );
                    }
                }
            }
            else {
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", (x2-x1)*2 +1);
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2) );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 -1);
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+2 );
                    }
                }
            }
            continue;
        }
        else{
            int t = abs(y1-y2) - 2;
            if(y2>y1) y2 = y1+2;
            else y2 = y1 - 2;
            cout<<t<<endl;
            cout<< x2<<" "<<y2<<endl;
            if(y1 % 2){
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", (x2-x1)*2 + t );
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+1 + t );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 +2 + t);
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2) +t+1);
                    }
                }
            }
            else {
                if(x1 % 2){
                    if(x2%2){
                        printf("%lld\n", (x2-x1)*2 + t);
                    }
                    else{
                        printf("%lld\n", ((x2-x1)*2) + 1+ t );
                    }
                }
                else{
                    if(x2%2 == 0){
                        printf("%lld\n", (x2-x1)*2 +t );
                    }
                    else{
                        printf("%lld\n", ((x2-x1-1)*2)+1 + t );
                    }
                }
            }
            continue;
        }


    }
    return 0;
}
