#include <iostream>
#include <cstdio>
using namespace std;
const int N=200005;
int a[N];
int curSize=0;

void enQueue(int x){
    int hole=++curSize;
    for(;hole>1;hole/=2){
        if(a[hole/2]>x) a[hole]=a[hole/2];
        else break;
    }
    a[hole]=x;
}

void Down(int hole){
    int tmp=a[hole];
    int child;
    for(;hole*2<=curSize;hole=child){
        child=hole*2;
        if(child!=curSize&&a[child+1]<a[child]) ++child;
        if(a[child]<tmp) a[hole]=a[child];
        else break;
    }
    a[hole]=tmp;
}

void deQueue(){
    a[1]=a[curSize--];
    Down(1);
}

int main() {
    int m,x;
    char s[9];
    scanf("%d",&m);
    while(m--){
        getchar();
        scanf("%s",s);
        if(s[0]=='i'){
            scanf("%d",&x);
            enQueue(x);
        }
        else if(s[0]=='d')deQueue();
        else if(s[0]=='m') printf("%d\n",a[1]);
    }
    return 0;
}