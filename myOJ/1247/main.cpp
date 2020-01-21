#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=10005;
bool f[N];

int main() {
    int n,m,l,r,cnt=0;
    memset(f,false, sizeof(f));
    scanf("%d%d",&n,&m);
    while(m--){
        scanf("%d%d",&l,&r);
        for(int i=l;i<=r;++i)
            f[i]=true;
    }
    for(int i=0;i<=n;++i){
        if(!f[i]) ++cnt;
    }
    printf("%d",cnt);
    return 0;
}