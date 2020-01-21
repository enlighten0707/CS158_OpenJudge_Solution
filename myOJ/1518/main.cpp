#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int pre[N],mid[N];
int n;

void Solve(int preStart,int len){
    if(len==0||preStart>=n) return;
    int cur=pre[preStart];
    int rootIndex=0;
    for(;rootIndex<len;++rootIndex){
        if(mid[rootIndex]==cur)break;
    }
    Solve(preStart+1,rootIndex);
    Solve(preStart+rootIndex+1,len-rootIndex-1);
    printf("%d ",cur);
}
int main() {

    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&pre[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&mid[i]);
    Solve(0,n);
    return 0;
}