#include <iostream>
#include <cstdio>
using namespace std;

const int N=40005;
int a[N]={0};
int curSize=0;
int queue[N];
int front=0,rear=0;
int ans[20005];
int cnt=0;

void enqueue(int x){
    rear=(rear+1)%N;
    queue[rear]=x;
}

int dequeue(){
    front=(front+1)%N;
    return queue[front];
}

bool isEmpty(){return front==rear;}

void insert(int x){
    int hole=++curSize;
    for(;hole>1;hole/=2){
        if(a[hole/2]<=x)break;
        else a[hole]=a[hole/2];
    }
    a[hole]=x;
}

void decrease(int i,int v){
    a[i]-=v;
    int hole=i;
    int x=a[i];
    for(;hole>1;hole/=2){
        if(a[hole/2]<=x) break;
        else a[hole]=a[hole/2];
    }
    a[hole]=x;
}

int find(int x){
    enqueue(1);
    int cur;
    while(!isEmpty()){
        cur=dequeue();
        if(a[cur]>x) return cur;
        if(2*cur<=curSize) enqueue(2*cur);
        if((2*cur+1)<=curSize) enqueue(2*cur+1);
    }
}






int find(int x){
    int minn=2147483647,res;
    for(int i=1;i<=curSize;++i){
        if(a[i]-x>0&&(a[i]-x)<minn){
            minn=a[i]-x;
            res=i;
        }
    }
    return res;
}

int main() {
    int m,x,i,v;
    char s[15];
    scanf("%d",&m);
    while(m--){
        getchar();
        scanf("%s",s);
        if(s[0]=='i'){
            scanf("%d",&x);
            insert(x);
        }
        else if(s[0]=='f'){
            scanf("%d",&x);
            ans[cnt++]=find(x);
        }
        else if(s[0]=='d'){
            scanf("%d%d",&i,&v);
            decrease(i,v);
        }
    }
    for(int j=0;j<cnt;++j)
        printf("%d\n",ans[j]);
    return 0;
}