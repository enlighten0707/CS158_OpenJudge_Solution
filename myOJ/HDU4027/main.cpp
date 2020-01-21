#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int N=100005;
long long  a[N],sum[N<<2],maxn[N<<2];
#define LSON rt<<1
#define RSON rt<<1|1

int Max(int x,int y){return x>y?x:y;}
void Swap(int &x,int &y){int tmp=x;x=y;y=tmp;}
void pushUp(int rt){
    sum[rt]=sum[LSON]+sum[RSON];
    maxn[rt]=Max(maxn[LSON],maxn[RSON]);
}

void build(int rt,int l, int r){
    if(l==r){
        sum[rt]=a[l];
        maxn[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(LSON,l,mid);
    build(RSON,mid+1,r);
    pushUp(rt);
}

void upDate(int rt,int l,int r, int ll,int rr){
    if(maxn[rt]==1) return;
    if(l==r){
        sum[rt]=(long long)sqrt(1.0*sum[rt]);
        maxn[rt]=(long long)sqrt(1.0*maxn[rt]);
        return;
    }
    int mid=(l+r)>>1;
    if(rr<=mid) upDate(LSON,l,mid,ll,rr);
    else if(ll>mid) upDate(RSON,mid+1,r,ll,rr);
    else{
        upDate(LSON,l,mid,ll,mid);
        upDate(RSON,mid+1,r,mid+1,rr);
    }
    pushUp(rt);
}

long long Query(int rt,int l,int r,int ll,int rr){
    if(ll==l&&rr==r)return sum[rt];
    int mid=(l+r)>>1;
    if(rr<=mid) return Query(LSON,l,mid,ll,rr);
    else if(ll>mid) return Query(RSON,mid+1,r,ll,rr);
    else return Query(LSON,l,mid,ll,mid)+Query(RSON,mid+1,r,mid+1,rr);
}

int main() {
    int n,m,cas=1,op,left,right;
    while(scanf("%d",&n)!=EOF){
        printf("Case #%d\n",cas++);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        build(1,1,n);
        scanf("%d",&m);
        while(m--){
            scanf("%d%d%d",&op,&left,&right);
            if(left>right) Swap(left,right);
            if(op==0) upDate(1,1,n,left,right);
            else if(op==1) printf("%lld\n",Query(1,1,n,left,right));
            //for(int i=1;i<=4*n;++i) cout<<sum[i]<<' ';
        }
        printf("\n");
    }
}