#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=4000005,OFFSET=2000002;
bool f[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    memset(f,false, sizeof(f));
    int s,x,opt;
    cin>>s;
    while(s--){
        cin>>x;
        f[x+OFFSET]=true;
    }
    int p;
    cin>>p;
    while(p--){
        cin>>opt>>x;
        if(opt==0) f[x+OFFSET]=false;
        else if(opt==1) f[x+OFFSET]=true;
    }
    for(int i=0;i<N;++i){
        if(f[i])
            cout<<i-OFFSET<<' ';
    }
    return 0;
}