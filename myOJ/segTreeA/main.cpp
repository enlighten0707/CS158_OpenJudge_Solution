#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=50005;
int a[N],segT[N<<2];

#define LSON rt<<1
#define RSON rt<<1|1

inline void pushup(int rt){
    segT[rt]=segT[LSON]+segT[RSON];
}
void build(int rt,int l,int r){
    if(l==r) {
        segT[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(LSON,l,mid);
    build(RSON,mid+1,r);
    pushup(rt);
}
void Update(int rt,int l,int r,int x,int w){
    if(l==r){
        segT[rt]+=w;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) Update(LSON,l,mid,x,w);
    else Update(RSON,mid+1,r,x,w);
    pushup(rt);
}

void subUpdate(int rt,int l,int r,int x,int w){
    if(l==r){
        segT[rt]-=w;
        return ;
    }
    int mid=(l+r)>>1;
    if(x<=mid) subUpdate(LSON,l,mid,x,w);
    else subUpdate(RSON,mid+1,r,x,w);
    pushup(rt);
}

int Query(int rt,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr) return segT[rt];
    int mid=(l+r)>>1;
    long long ans=0;
    if(ll<=mid) ans+=Query(LSON,l,mid,ll,rr);
    if(rr>mid) ans+=Query(RSON,mid+1,r,ll,rr);
    return ans;
}


int main(){
    int n,cnt=1,t,i,j;
    scanf("%d\n",&t);
    while(t--)
    {
        scanf("%d\n",&n);
        for(int k=1;k<=n;++k)
            scanf("%d",&a[k]);

        build(1,1,n);

        char command[10];
        printf("Case %d:\n",cnt);
        ++cnt;

        while(scanf("%s",command)&&command[0]!='E'){
            scanf("%d%d",&i,&j);
            if(command[0]=='A')
                Update(1,1,n,i,j);
            else if(command[0]=='S')
                subUpdate(1,1,n,i,j);
            else if(command[0]=='Q')
                printf("%d\n",Query(1,1,n,i,j));
        }
    }
    return 0;
}