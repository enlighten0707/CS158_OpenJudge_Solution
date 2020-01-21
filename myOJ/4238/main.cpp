#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=200005;
int parent[N];
bool ans[N],exist[N];
int cnt=0;

int Find(int x){
    return parent[x]<0?x:parent[x]=Find(parent[x]);
}

void Union(int x,int y ){
    int xp=Find(x),yp=Find(y);
    if(xp==yp) return;
    if(xp<yp){
        parent[xp]+=parent[yp];
        parent[yp]=xp;
    }
    else {
        parent[yp]+=parent[xp];
        parent[xp]=yp;
    }
}

int main() {
    int n,m,opt,x,y;
    memset(exist,true,sizeof(exist));
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i)
        parent[i]=-1;

    while(m--){
        scanf("%d%d",&opt,&x);
        if(opt==1){
            scanf("%d",&y);
            Union(x,y);
        }
        else if(opt==2){
            scanf("%d",&y);
            if(Find(x)==Find(y)&&exist[x]&&exist[y]) ans[cnt++]=true;
            else ans[cnt++]=false;
        }
        else if(opt==3){
            exist[x]=false;
        }
    }

    for(int i=0;i<cnt;++i){
        if(ans[i]) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}