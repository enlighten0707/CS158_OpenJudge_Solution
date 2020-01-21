#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int N=10005;
int n;
int parent[N][20],fa[N],depth[N];
int child[N][100];
int cnt[N];

void makeDepth(int u){
    int v;
    int len=cnt[u];
    for(int i=0;i<len;++i){
        v=child[u][i];
        depth[v]=depth[u]+1;
        makeDepth(v);
    }
}

void findParent(){
    for(int up=1;1<<up<=n;++up){
        for(int i=1;i<=n;++i)
            parent[i][up]=parent[parent[i][up-1]][up-1];
    }
}

int LCA(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);
    int i=-1,j;
    while(1<<(i+1)<=depth[u]) ++i;

    for(int j=i;j>=0;--j){
        if(depth[u]-(1<<j)>=depth[v])
            u=parent[u][j];
    }

    if(u==v) return u;

    for(j=i;j>=0;--j){
        if(parent[u][j]!=parent[v][j]){
            u=parent[u][j];
            v=parent[v][j];
        }
    }
    return parent[u][0];

}

int main() {
    int T,u,v,root=0;
    scanf("%d",&T);
    while(T--){
        memset(parent,-1,sizeof(parent));
        memset(fa,-1,sizeof(fa));
        memset(depth,-1, sizeof(depth));
        memset(cnt,0, sizeof(cnt));

        scanf("%d",&n);
        for(int i=0;i<n-1;++i){
            scanf("%d%d",&u,&v);
            fa[v]=u;
            child[u][cnt[u]++]=v;
            parent[v][0]=u;
        }
        for(int i=1;i<=n;++i){
            if(fa[i]==-1){
                root=i;
                break;
            }
        }
        depth[root]=1;
        makeDepth(root);
        findParent();
        scanf("%d%d",&u,&v);
        printf("%d\n",LCA(u,v));
    }
    return 0;
}