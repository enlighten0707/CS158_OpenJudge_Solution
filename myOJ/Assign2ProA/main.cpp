#include <iostream>
#include <cstdio>
using namespace std;
const int MAXSIZE=100005,MAXN=3005;
int a[MAXN],Cnt[MAXSIZE];

int main() {
    int n,m,tmp;
    while(scanf("%d", &n) != EOF){
        scanf("%d",&m);
        for(int i=0;i<n;++i)
            scanf("%d",&a[i]);
        for(int i=0;i<=10000;++i)
            Cnt[i]=0;
        for(int i=0;i<n;++i){
            for(int j=i+1;j<n;++j){
                tmp=a[i]+a[j];
                ++Cnt[tmp];
            }
        }
        int i=10000;
        while(m>0){
            if(Cnt[i]&&m>1){
                printf("%d ",i);
                --m;
                --Cnt[i];
            }
            else if(Cnt[i]&&m==1){
                printf("%d\n",i);
                --m;
                --Cnt[i];
            }
            else --i;
        }
    }

    return 0;
}