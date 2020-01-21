#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int a[N];
bool vis[N];

int main() {
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        vis[i]=false;
    for(int i=0;i<n;++i){
        if(vis[i]) continue;
        int tmp=a[i];
        vis[i]=true;
        while(tmp!=i){
            vis[tmp]=true;
            tmp=a[tmp];
        }
        ++cnt;
    }
    printf("%d",cnt-1);
    return 0;
}