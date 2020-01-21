#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=20005;
int fa[N],parent[N][20],depth[N],child[N][100],cnt[N],len[N],dis[N];
bool isRoot[N];
int n,a,b,c;

void makeDepth(int u){
    int v;
    for(int i=0;i<cnt[u];++i){
        v=child[u][i];
        depth[v]=depth[u]+1;
        dis[v]=dis[u]+len[v];
        makeDepth(v);
    }
}

void findParent(){
    for(int up=1;(1<<up)<=n;++up){
        for(int i=1;i<=n;++i)
            parent[i][up]=parent[parent[i][up-1]][up-1];
    }
}

int LCA(int u,int v){
    if(depth[u]<depth[v]) swap(u,v);//U节点更深，在下方
    int i=-1,j;
    while((1<<(i+1))<=depth[u]) ++i;

    for(j=i;j>=0;--j){
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

int Distance(int u,int v){
    if(u==v) return 0;
    return dis[u]+dis[v]-2*dis[LCA(u,v)];
}

int main() {
    memset(fa,-1,sizeof(fa));
    memset(parent,-1, sizeof(parent));
    memset(depth,-1, sizeof(depth));
    memset(cnt,0, sizeof(cnt));
    memset(len,0, sizeof(len));
    memset(dis,0,sizeof(dis));
    memset(isRoot,true, sizeof(isRoot));

    int u,v,w;
    scanf("%d%d%d%d",&n,&a,&b,&c);
    for(int i=0;i<n-1;++i){
        scanf("%d%d%d",&u,&v,&w);
        if(cnt[u]!=0){
            fa[v]=u;
            child[u][cnt[u]++]=v;
            len[v]=w;
            parent[v][0]=u;
            isRoot[v]=false;
        }
        else if(cnt[v]!=0){
            fa[u]=v;
            child[v][cnt[v]++]=u;
            len[u]=w;
            parent[u][0]=v;
            isRoot[u]=false;
        }
        else{
            fa[v]=u;
            child[u][cnt[u]++]=v;
            len[v]=w;
            parent[v][0]=u;
            isRoot[v]=false;
        }
    }


    int root=0;
    for(int i=1;i<=n;++i){
        if(isRoot[i]){
            root=i;
            break;
        }
    }
    depth[root]=1;
    makeDepth(root);
    findParent();
    int ans=200000000,tmp,pos=0;

    for(int i=1;i<=n;++i){
        tmp=Distance(i,a)+Distance(i,b)+Distance(i,c);
        if(tmp<ans) {
            ans=tmp;
            pos=i;
        }
    }
    printf("%d\n",pos);
    printf("%d",ans);
    return 0;
}