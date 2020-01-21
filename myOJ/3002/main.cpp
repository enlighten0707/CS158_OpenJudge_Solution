#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool f[1005];

int main() {
    memset(f,false, sizeof(f));
    int n,a,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&a);
        if(!f[a]){
            ++cnt;
            f[a]=true;
        }
    }

    printf("%d\n",cnt);
    for(int i=1;i<=1000;++i){
        if(f[i]) printf("%d ",i);
    }
    return 0;
}