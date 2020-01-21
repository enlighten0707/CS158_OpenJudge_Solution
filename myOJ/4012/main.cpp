#include <iostream>
#include <cstdio>
using namespace std;
const int MAXSIZE=10005;
int queue[MAXSIZE];
int n,cnt=0;

void push(int x){
    int hole=++cnt;
    for(;hole>1;hole/=2){
        if(queue[hole/2]>x) queue[hole]=queue[hole/2];
        else break;
    }
    queue[hole]=x;
}

int pop(){
    int ans=queue[1];
    queue[1]=queue[cnt--];
    int hole=1,tmp=queue[1];
    int child;
    for(;hole*2<=cnt;hole=child){
        child=hole*2;
        if(child!=cnt&&queue[child+1]<queue[child]) ++child;
        if(queue[child]<tmp) queue[hole]=queue[child];
        else break;
    }
    queue[hole]=tmp;
    return ans;
}

int main() {
    int x;
    unsigned long long sum=0,tmp1,tmp2;
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",&x);
        push(x);
    }
    //for(int i=1;i<=n;++i)
        //cout<<queue[i]<<' ';
    for(int i=0;i<n-1;++i){
        tmp1=pop();
        tmp2=pop();
        //cout<<tmp1<<' '<<tmp2<<" poped\n";
        sum+=tmp1+tmp2;
        push(tmp1+tmp2);
        //cout<<tmp1+tmp2<<" pushed\n";
    }
    cout<<sum;
    return 0;
}