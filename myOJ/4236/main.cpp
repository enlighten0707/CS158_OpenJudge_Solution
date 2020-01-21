#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=100005;
int V[N],R[N];
long long ans[N];
int main() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&V[i]);
    for(int i=1;i<=n;++i)
        scanf("%d",&R[i]);
    memset(ans,0, sizeof(ans));
    for(int i=1;i<=n;++i){
        for(int j=i;j<=n;++j){
            if(V[i]>=R[j]){
                ans[j]+=(long long)R[j];
                V[i]-=R[j];
            }

            else{
                ans[j]+=(long long)V[i];
                V[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;++i)
        printf("%lld ",ans[i]);
    return 0;
}