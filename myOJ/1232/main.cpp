#include <iostream>
#include <cstdio>
using namespace std;

const int N=100005;
int fa[N];
int row[N];
bool rec[N];
int n,Start,End;

inline int find(int x){
    return (fa[x]<0)?x:(fa[x]=find(fa[x]));
}

int neighbour(int x,int opt){
    int y=0;
    switch (opt){
        case 0:
            if(x>1&&row[x]==row[x-1])
                y=x-row[x];
            break;
        case 1:
            if(x>1&&row[x]==row[x+1])
                y=x-row[x]+1;
            break;
        case 2:
            if(row[x]<n)
                y=x+row[x];
            break;
        case 3:
            if(row[x]<n)
                y=x+row[x]+1;
            break;
        default:break;
    }
    return y;
}

void merge(int x,int opt){
    int y=neighbour(x,opt);
    if(!y)return;

    int fx=find(x),fy=find(y);
    if(fx<fy){
        fa[fx]+=fa[fy];
        fa[fy]=fx;
    }
    else if(fx>fy){
        fa[fy]+=fa[fx];
        fa[fx]=fy;
    }
}


void print(){
    int cur=Start,next;
    while(cur!=End){
        printf("%d ",cur);
        rec[cur]=true;
        for(int i=0;i<4;++i){
            next=neighbour(cur,i);
            if(next&&find(cur)==find(next)&&!rec[next])break;
        }
        cur=next;
    }
    printf("%d",End);
}

int main() {
    scanf("%d%d%d",&n,&Start,&End);
    for(int i=0;i<N;++i)
        fa[i]=-1;
    for(int i=0;i<N;++i)
        rec[i]=false;
    int j=1,cur=1;
    while(j<=n){
        for(int k=0;k<j;++k)
            row[cur++]=j;
        ++j;
    }
    int x,opt;
    while(scanf("%d%d",&x,&opt)){
        merge(x,opt);
        if(find(Start)==find(End)) break;
    }
    print();
    return 0;
}