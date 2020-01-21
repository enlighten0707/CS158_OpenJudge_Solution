#include <iostream>
#include <cstdio>
#include <cstring>
const int N=1005;
bool f[N][N],vis[N];
int a[N],queue[N];
int curSize=0;

//优先级队列
void enqueue(int x){
    int hole=++curSize;
    for(;hole>1;hole/=2){
        if(a[queue[hole/2]]<a[x]) queue[hole]=queue[hole/2];
        else break;
    }
    queue[hole]=x;
}

int dequeue(){
    int tmp=queue[1];
    queue[1]=queue[curSize--];
    int hole=1;
    int child,x=queue[hole];

    for(;hole*2<=curSize;hole=child){
        child=hole*2;
        if(hole*2+1<=curSize&&a[queue[child+1]]>a[queue[child]]) ++child;
        if(a[queue[child]]>a[x]) queue[hole]=queue[child];
        else break;
    }
    queue[hole]=x;
    return tmp;
}

bool isEmpty(){
    return curSize==0;
}

int main() {
    memset(vis,false,sizeof(vis));
    int n,k,x,opt;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    while(k--){
        scanf("%d",&x);
        enqueue(x);
        vis[x]=true;
    }
    memset(f,false, sizeof(f));
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            scanf("%d",&opt);
            if(opt) f[i][j]=true;
        }
    }
    while(!isEmpty()){
        int cur=dequeue();
        printf("%d\n",cur);
        vis[cur]=true;
        for(int j=1;j<=n;++j){
            if(f[cur][j]&&!vis[j]) {
                enqueue(j);
                vis[j]=true;
            }

        }
    }
    return 0;
}