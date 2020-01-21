#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int N=100005;

struct Edge{
    int beg,end,w;
}edge[N];
int cnt=0;

int queue[N];
int curSize=0;

void enqueue(int x){
    int hole=++curSize;
    for(;hole>1;hole/=2){
        if(edge[queue[hole/2]].w>edge[x].w) queue[hole]=queue[hole/2];
        else break;
    }
    queue[hole]=x;
}

int dequeue(){
    int ans=queue[1];
    queue[1]=queue[curSize--];
    int hole=1,x=queue[hole];
    int child;
    for(;hole*2<=curSize;hole=child){
        child=hole*2;
        if(hole*2+1<=curSize&&edge[queue[child+1]].w<edge[queue[child]].w)++child;
        if(edge[queue[child]].w<edge[x].w) queue[hole]=queue[child];
        else break;
    }
    queue[hole]=x;
    return ans;
}

bool isEmpty(){
    return curSize==0;
}

int father[N];

int Find(int x){
    return father[x]<0?x:father[x]=Find(father[x]);
}

void Union(int x,int y){
    int xp=Find(x),yp=Find(y);
    if(xp!=yp){
        if(xp<yp){
            father[xp]+=father[yp];
            father[yp]=xp;
        }
        else {
            father[yp]+=father[xp];
            father[xp]=yp;
        }
    }
}


int main() {
    memset(father,-1, sizeof(father));
   int n,m,a,b,p,edgeAccept=0,u,v,sum=0;
   scanf("%d%d",&n,&m);
   while(m--){
       scanf("%d%d%d",&a,&b,&p);
       edge[cnt++].beg=a;
       edge[cnt-1].end=b;
       edge[cnt-1].w=p;
       enqueue(cnt-1);
   }

   while(edgeAccept<n-1){
       int cur=dequeue();
       u=Find(edge[cur].beg);
       v=Find(edge[cur].end);
       if(u!=v){
           edgeAccept++;
           Union(u,v);
           sum+=edge[cur].w;
       }
   }
   printf("%d",sum);
    return 0;
}