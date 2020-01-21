#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=5005;
int segT[N<<2],a[N];
int ans;
#define LSON rt<<1
#define RSON rt<<1|1

inline void pushUp(int rt){
    segT[rt]=segT[LSON]+segT[RSON];
}

void modify(int rt,int l,int r,int x){
    if(l==r){
        segT[rt]++;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) modify(LSON,l,mid,x);
    else modify(RSON,mid+1,r,x);
    pushUp(rt);
}

void Query(int rt,int l,int r,int ll ,int rr){
    if(ll==l&&rr==r){
        ans+=segT[rt];
        return;
    }
    int mid=(l+r)>>1;
    if(rr<=mid ) Query(LSON,l,mid,ll,rr);
    else if(ll>mid ) Query(RSON,mid+1,r,ll,rr);
    else{
        Query(LSON,l,mid,ll,mid);
        Query(RSON,mid+1,r,mid+1,rr);
    }
}

inline int Min(int x,int y){ return  x<y?x:y;}

int main() {
    int n;
    while(~scanf("%d",&n)){
        memset(segT,0,sizeof(segT));
        int sum=0;
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
            ans=0;
            Query(1,1,n,a[i]+1,n);
            sum+=ans;
            modify(1,1,n,a[i]);
        }
        int res=sum;
        for(int i=1;i<=n;++i){
            sum+=n-2*a[i]-1;

            res=Min(res,sum);
        }
        printf("%d\n",res);
    }
}