#include <iostream>
#include <cstdio>
#include <cstring>

const int N=500005;
int Rank[11],father[N];
bool f[N];

int Find(int x){
    return father[x]<0?x:father[x]=Find(x);
}

void Union(int x,int y){
    if(!f[x]||!f[y]) return;
    int fx=Find(x),fy=Find(y);
    if(fx==fy) return;
    if(fx<fy){
        father[fx]+=father[fy];
        father[fy]=fx;
        if(father[fx]>=Rank[10]) return;
        for(int i=1;i<=10;++i){
            if(father[fx]<Rank[i]){
                for(int j=i+1;j<=10;++j)
                    Rank[j]=Rank[j-1];
                Rank[i]=father[fx];
                break;
            }
        }
    }
    else{
        father[fy]+=father[fx];
        father[fx]=fy;
        if(father[fy]>=Rank[10]) return;
        for(int i=1;i<=10;++i){
            if(father[fy]<Rank[i]){
                for(int j=i+1;j<=10;++j)
                    Rank[j]=Rank[j-1];
                Rank[i]=father[fy];
                break;
            }
        }
    }
}

int main() {
    memset(f,true,sizeof(f));
    memset(Rank,-1,sizeof(Rank));

    int n,m,x,y;
    char opt;
    scanf("%d%d",&n,&m);
    memset(father,-1,sizeof(father));
    while(m--){
        getchar();
        scanf("%c%d",&opt,&x);
        if(opt=='C'){
            scanf("%d",&y);
            Union(x,y);
        }
        else if(opt=='D') f[x]=false;
        else if(opt=='Q')
            printf("%d\n",-Rank[x]);
    }
    return 0;
}