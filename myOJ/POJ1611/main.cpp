#include <iostream>
#include <cstdio>
using namespace std;

const int N=30005;
int parent[N],a[N];

int Find(int x){
    int i=x,j;
    while(x!=parent[x])
        x=parent[x];
    while(i!=x){
        j=parent[i];
        parent[i]=x;
        i=j;
    }
    return x;
}

void Merge(int x,int y){
    int xx=Find(x);
    int yy=Find(y);
    if(xx==yy) return;
    parent[xx]=yy;
    a[yy]+=a[xx];
}

int main() {
    int n,m,k,x,y;
    while(~scanf("%d%d",&n,&m)){
        if(n==0&&m==0) break;
        for(int i=0;i<n;++i){
            parent[i]=i;
            a[i]=1;
        }

        while(m--){
            scanf("%d%d",&k,&x);
            k--;
            while(k--){
                scanf("%d",&y);
                Merge(x,y);
            }
        }
        printf("%d\n",a[Find(0)]);
    }
    return 0;
}