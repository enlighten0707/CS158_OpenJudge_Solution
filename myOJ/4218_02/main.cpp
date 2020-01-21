#include <iostream>
#include <cstdio>
using namespace std;
const int N=2000005;
int a[N],q[N];
bool counted[N]={false};

int main() {
    int n,d,cnt=0;
    scanf("%d%d",&n,&d);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int head,tail;
    head=tail=1;
    q[tail]=1;
    for(int i=2;i<=n;++i){
        while(head<=tail&&a[i]>a[q[tail]])--tail;
        q[++tail]=i;
        while(head<=tail&&q[head]<i-d) ++head;
        if(a[q[head]]>2*a[i]){
            ++cnt;
            counted[i]=true;
        }
    }
    head=tail=1;
    q[tail]=n;
    for(int i=n-1;i>=1;--i){
        while(head<=tail&&a[i]>a[q[tail]])--tail;
        q[++tail]=i;
        while(head<=tail&&q[head]>i+d) ++head;
        if(a[q[head]]>2*a[i]&&!counted[i])
            ++cnt;
    }
    printf("%d",cnt);
    return 0;
}