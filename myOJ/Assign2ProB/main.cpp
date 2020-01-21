#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int OFFSET=500000,MAXSIZE=1000005;
int a[MAXSIZE];
bool f[MAXSIZE];

int main() {
    int n,m;
    while(scanf("%d",&n)!=EOF){
        scanf("%d",&m);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<MAXSIZE;++i)
            f[i]=false;
        for(int i=0;i<n;++i)
            f[a[i]+OFFSET]=true;
        int i=1000000;
        while(m>0){
            if(f[i]&&m>1){
                printf("%d ",i-OFFSET);
                --m;
                --i;
            }
            else if(f[i]&&m==1){
                printf("%d\n",i-OFFSET);
                --m;
                --i;
            }
            else --i;
        }
    }
    return 0;
}