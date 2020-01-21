#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int a[N],tag[N<<2]={0};
long long segT[N<<2],ans[N<<2];
int cnt=0;

#define  LSON rt<<1
#define  RSON rt<<1|1

inline void pushup(int rt){
    segT[rt]=segT[LSON]+segT[RSON];
}

void build(int rt,int l,int r){
    if(l==r){
        scanf("%lld",&segT[rt]);
        return ;
    }
    int mid=(l+r)>>1;
    build(LSON,l,mid);
    build(RSON,mid+1,r);
    pushup(rt);
}

void pushdown(int rt,int l,int r){
    if(tag[rt]){
        int mid=(l+r)>>1;
        tag[LSON]+=tag[rt];
        tag[RSON]+=tag[rt];
        segT[LSON]+=(long long )tag[rt]*(mid-l+1);
        segT[RSON]+=(long long) tag[rt]*(r-mid);
        tag[rt]=0;
    }
}

void upDate(int rt,int l,int r,int ll,int rr,int w){
    if(ll<=l&&r<=rr){
        tag[rt]+=w;
        segT[rt]+=(long long)w*(r-l+1);
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(ll<=mid) upDate(LSON,l,mid,ll,rr,w);
    if(rr>mid) upDate(RSON,mid+1,r,ll,rr,w);
    pushup(rt);
}

long long query(int rt,int l,int r,int ll,int rr){
    if(ll<=l&&r<=rr) return segT[rt];
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    long long ans=0;
    if(ll<=mid) ans+=query(LSON,l,mid,ll,rr);
    if(rr>mid) ans+=query(RSON,mid+1,r,ll,rr);
    return ans;
}
int main() {
    int n,q,x,y,z;
    char opt;
    scanf("%d%d",&n,&q);

    build(1,1,n);
    while(q--){
        cin>>opt>>x>>y;
        if(opt=='C'){
            scanf("%d",&z);
            upDate(1,1,n,x,y,z);
        }
        else if(opt=='Q')
            ans[cnt++]=query(1,1,n,x,y);
    }
    for(int i=0;i<cnt;++i)
        printf("%lld\n",ans[i]);
    return 0;
}