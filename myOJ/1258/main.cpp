#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=100005;
int segT[N<<2],a[N];
#define LSON rt<<1
#define RSON rt<<1|1


void modify(int rt,int l,int r,int x){
    if(l==r){
        segT[rt]++;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(LSON,l,mid,x);
    else modify(RSON,mid+1,r,x);
    segT[rt]=segT[LSON]+segT[RSON];
}

int Query(int rt,int l,int r,int ll ,int rr){
    if(ll==l&&rr==r){
        return segT[rt];
    }
    int mid=(l+r)>>1;
    int res=0;
    if(rr<=mid ) res+=Query(LSON,l,mid,ll,rr);
    else if(ll>mid ) res+=Query(RSON,mid+1,r,ll,rr);
    else res+=Query(LSON,l,mid,ll,mid)+Query(RSON,mid+1,r,mid+1,rr);
    return res;
}

int main() {
    int n;
    scanf("%d",&n);
    memset(segT,0,sizeof(segT));
    int sum=0;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        sum+=Query(1,1,N,a[i]+1,N);
        modify(1,1,N,a[i]);
    }
    printf("%d",sum);
    return 0;
}