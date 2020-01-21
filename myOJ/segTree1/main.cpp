#include <iostream>
#include <cstdio>

using namespace std;

const int N=100005;
int a[N],tag[N<<2]={0};
long long segT[N<<2];
#define LSON rt<<1
#define RSON rt<<1|1

inline void pushUp(int rt){
    segT[rt]=segT[LSON]+segT[RSON];
}

void build(int rt,int l,int r){
    if(l==r){
        segT[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(LSON,l,mid);
    build(RSON,mid+1,r);
    pushUp(rt);
}

void pushDown(int rt,int l,int r){
    if(tag[rt]){
        int mid=(l+r)>>1;
        segT[LSON]+=(long long)tag[rt]*(mid-l+1);
        segT[RSON]+=(long long)tag[rt]*(r-mid);
        tag[LSON]+=tag[rt];
        tag[RSON]+=tag[rt];
        tag[rt]=0;
    }
}

void upDate(int rt,int l,int r,int ll,int rr,int c){
    if(ll<=l&&r<=rr){
        segT[rt]+=(long long)c*(r-l+1);
        tag[rt]+=c;
        return;
    }
    pushDown(rt,l,r);
    int mid=(l+r)>>1;
    if(ll<=mid) upDate(LSON,l,mid,ll,rr,c);
    if(rr>mid) upDate(RSON,mid+1,r,ll,rr,c);
    pushUp(rt);
}

long long Query(int rt,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr) return segT[rt];
    pushDown(rt,l,r);
    int mid=(l+r)>>1;
    long long ans=0;
    if(ll<=mid) ans+=Query(LSON,l,mid,ll,rr);
    if(rr>mid) ans+=Query(RSON,mid+1,r,ll,rr);
    return ans;
}

int main() {
    int n,m,l,r,c;
    char ch;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    while(m--){
        getchar();
        scanf("%c",&ch);
        if(ch=='C'){
            scanf("%d%d%d",&l,&r,&c);
            upDate(1,1,n,l,r,c);
        }
        else if(ch=='Q'){
            scanf("%d%d",&l,&r);
            printf("%lld\n",Query(1,1,n,l,r));
        }
    }
    return 0;
}