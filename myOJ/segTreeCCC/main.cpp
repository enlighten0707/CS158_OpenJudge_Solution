#include <iostream>
#include <cstdio>
using  namespace std;
const int N=100005;
int a[N],tag[N<<2]={0};
long long segT[N<<2];

#define LSON rt<<1
#define RSON rt<<1|1

void pushUp(int rt){
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
    if(ll<=l&&rr>=r){
        segT[rt]+=(long long)c*(r-l+1);
        tag[rt]+=c;
        return;
    }
    pushDown(rt,l,r);
    int mid=(l+r)>>1;
    if(rr<=mid) upDate(LSON,l,mid,ll,rr,c);
    else if(ll>mid) upDate(RSON,mid+1,r,ll,rr,c);
    else{
        upDate(LSON,l,mid,ll,mid,c);
        upDate(RSON,mid+1,r,mid+1,rr,c);
    }
    pushUp(rt);
}

long long Query(int rt,int l,int r,int ll,int rr){
    if(ll==l&&rr==r) return segT[rt];
    pushDown(rt,l,r);
    int mid=(l+r)>>1;
    if(rr<=mid) return Query(LSON,l,mid,ll,rr);
    else if(ll>mid) return Query(RSON,mid+1,r,ll,rr);
    else return Query(LSON,l,mid,ll,mid)+Query(RSON,mid+1,r,mid+1,rr);
}

int main() {
    int n,m,left,right,value;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    build(1,1,n);
    char ch;
    while(m--){
        getchar();
        scanf("%c",&ch);
        if(ch=='C'){
            scanf("%d%d%d",&left,&right,&value);
            upDate(1,1,n,left,right,value);
        }
        else if(ch=='Q'){
            scanf("%d%d",&left,&right);
            printf("%lld\n",Query(1,1,n,left,right));
        }
        //for(int i=1;i<=4*n;++i) cout<<segT[i]<<' ';
    }
}