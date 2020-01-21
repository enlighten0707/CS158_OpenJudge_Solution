#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    double r,d,ans=0,tmp;
    while(cin>>r){
        cin>>d;
        tmp=r*r*acos(d/r)-d*sqrt(r*r-d*d);
        if(tmp>ans) ans=tmp;
    }
    printf("%.2lf",ans);
    return 0;
}