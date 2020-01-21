#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

const int N=40005;

int n,m;
int depth[N],fa[N],len[N],parent[N][20],dis[N];
vector<int> child[N];

void getDepth_dfs(int u) // DFS求深度,同时更新前缀和
{
    int length = child[u].size();
    for (int i = 0; i < length; ++i) {
        int v = child[u][i];
        depth[v] = depth[u] + 1;
        dis[v]=dis[u]+len[v];
        getDepth_dfs(v);
    }
}

void getParents()
{
    for (int up = 1; (1 << up) <= n; ++up) {
        for (int i = 1; i <= n; ++i) {
            parent[i][up] = parent[parent[i][up - 1]][up - 1];
        }
    }
}

int Lca(int u, int v)
{
    if (depth[u] < depth[v]) swap(u, v); // 使满足u深度更大, 便于后面操作
    int i = -1, j;
    // i求的是最大二分跨度
    while ((1 << (i + 1)) <= depth[u]) ++i;

    // 下面这个循环是为了让u和v到同一深度
    for (j = i; j >= 0; --j) {
        if (depth[u] - (1 << j) >= depth[v]) { // 是>=, 因为如果<,代表跳过头了,跳到了上面.
            u = parent[u][j];
        }
    }

    if (u == v) return u; // 刚好是祖宗

    // u和v一起二分找祖宗
    for (j = i; j >= 0; --j) {
        if (parent[u][j] != parent[v][j]) {
            u = parent[u][j];
            v = parent[v][j];
        }
    }
    return parent[u][0]; // 说明上个循环迭代到了Lca的子结点
}



int main() {//root=1
    int T,u,v,w;
    scanf("%d",&T);
    while(T--){
        memset(depth,-1,sizeof(depth));
        memset(parent,-1, sizeof(parent));
        memset(len,0, sizeof(len));
        memset(fa,-1, sizeof(fa));
        memset(dis,0, sizeof(dis));

        scanf("%d%d",&n,&m);
        for(int i=0;i<n-1;++i){
            scanf("%d%d%d",&u,&v,&w);
            if(u>v)swap(u,v); //统一成，u小，为父亲
            parent[v][0]=u;
            fa[v]=u;
            len[v]=w;
            child[u].push_back(v);
        }
        depth[1]=1;
        getDepth_dfs(1);
        getParents();

        while(m--){
            scanf("%d%d",&u,&v);
            printf("%d\n",dis[u]+dis[v]-2*dis[Lca(u,v)]);
        }
    }
    return 0;
}
