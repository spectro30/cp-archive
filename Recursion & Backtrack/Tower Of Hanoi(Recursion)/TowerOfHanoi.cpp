#include<bits/stdc++.h>
using namespace std;
void TOWER(int N, char BEG, char AUX, char END)
{
    if(N==1){
        cout<<BEG<<"--->"<<END<<endl;
        return;
    }
    TOWER(N-1,BEG,END,AUX);
    TOWER(1,BEG,AUX,END);
    TOWER(N-1,AUX,BEG,END);
}
int main()
{
    int N;
    cin>>N;
    char BEG='A',AUX='B',END='C';
    TOWER(N,BEG,AUX,END);
    return 0;
}



