#define pb push_back
#define ff first
#define ss second
#define ll long long
#define MX 300005
#define inf 0x3f3f3f3f
#define mod 998244353
#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(){
        x = y = 0;
    }
};

bool on_Segment( point pi, point pj, point pk ){
    if ( min(pi.x,pj.x) <= pk.x && pk.x <= max(pi.x,pj.x) && min(pi.y,pj.y) <= pk.y && pk.y <= max(pi.y,pj.y) ) return true;
    else return false;
}


int direction(point pi, point pj, point pk){
    return ( (pi.x * pj.y) + (pj.x * pk.y) + (pk.x * pi.y) - (pj.x * pi.y) - (pk.x * pj.y) - (pi.x * pk.y) );
}

bool segments_Intersect(point p1, point p2, point p3, point p4){
    int d1, d2, d3, d4;
    d1 = direction(p3, p4, p1);
    d2 = direction(p3, p4, p2);
    d3 = direction(p1, p2, p3);
    d4 = direction(p1, p2, p4);
    if( ( (d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0) ) && ( ( d3 > 0 && d4 < 0 ) || (d3 < 0 && d4 > 0) ) ){
        return true;
    }
    else if( d1 == 0 && on_Segment(p3, p4, p1) ){
        return true;
    }
    else if( d2 == 0 && on_Segment(p3, p4, p2) ){
        return true;
    }
    else if( d3 == 0 && on_Segment(p1, p2, p3) ){
        return true;
    }
    else if( d4 == 0 && on_Segment(p1, p2, p4) ){
        return true;
    }
    else return false;
}


int main(int argc, char const *argv[]) {
    point p1, p2, p3, p4;
    cin >> p1.x >> p1.y;
    cin >> p2.x >> p2.y;
    cin >> p3.x >> p3.y;
    cin >> p4.x >> p4.y;
    bool sol = segments_Intersect(p1, p2, p3, p4);
    if(sol)cout<< "OK"<<endl;

    return 0;
}
