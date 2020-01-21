#include <iostream>
#include <cstdio>
using namespace std;

const int N=20005;
int a[N]={0};
int curSize=0;

void insert(int x){
    int hole=++curSize;
    for(;hole>1;hole/=2){
        if(a[hole/2]<x) break;
        else a[hole]=a[hole/2];
    }
    a[hole]=x;
}

void Down(int hole){
    int tmp=a[hole];
    int child;
    for(;hole*2<=curSize;hole=child){
        child=hole*2;
        if(child!=curSize&&a[child]<a[child+1]) ++child;
        if(a[child]>tmp) break;
        else a[hole]=a[child];
    }
    a[hole]=tmp;
}

int dequeue(){
    int ans=a[1];
    a[1]=a[curSize--];
    Down(1);
    return ans;
}

int main() {
    int n,x;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&x);
        insert(x);
    }
    long long cnt=0;
    int m=n-1,cur1,cur2;
    while(m--){
        cur1=dequeue();
        cur2=dequeue();
        cnt+=cur1+cur2;
        insert(cur1+cur2);
    }
    printf("%lld",cnt);
    return 0;
}