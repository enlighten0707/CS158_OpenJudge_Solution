#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;


long long a[N],segT[N<<2],tag[N<<2]={0};
long long ans;

inline void pushUp(int rt){
    segT[rt]=segT[rt<<1]+segT[rt<<1|1];
}
void Build(int rt,int l,int r){
    if(l==r){
        segT[rt]=a[l];
        return;
    }
    int mid=(l+r)>>1;
    Build(rt<<1,l,mid);
    Build(rt<<1|1,mid+1,r);
    pushUp(rt);
}

inline void pushDown(int rt,int l,int r){
    if(tag[rt]){
        int mid=(l+r)>>1;
        segT[rt<<1]+=tag[rt]*(long long)(mid-l+1);
        segT[rt<<1|1]+=tag[rt]*(long long)(r-mid);
        tag[rt<<1]=tag[rt];
        tag[rt<<1|1]=tag[rt];
        tag[rt]=0;
    }
}

void upDate(int rt ,int l ,int r,int ll,int rr,int w){
    if(ll==l&&rr==r){
        segT[rt]+=(long long)w*(l-r+1);
        tag[rt]+=(long long)w;
        return;
    }
    pushDown(rt,l,r);
    int mid=(l+r)>>1;
    if(ll<=mid) upDate(rt<<1,l,mid,ll,mid,w);
    if(rr>mid) upDate(rt<<1|1,mid+1,r,mid+1,rr,w);
    pushUp(rt);
}

void Query(int rt,int l,int r,int ll,int rr){
    if(ll==l&&rr==r){
        ans+=segT[rt];
        return;
    }
    int mid=(l+r)>>1;
    pushDown(rt,l,r);
    if(rr<=mid) Query(rt<<1,l,mid,ll,rr);
    else if(ll>mid) Query(rt<<1|1,mid+1,r,ll,rr);
    else{
        Query(rt<<1,l,mid,ll,mid);
        Query(rt<<1|1,mid+1,r,mid+1,rr);
    }
}

int main(){
    int n,q,left,right,value;
    char ch;
    while(scanf("%d%d",&n,&q)!=EOF){
        for(int i=1;i<=n;++i)
            scanf("%lld",&a[i]);
        Build(1,1,n);
        while(q--){
            scanf(" %c",&ch);
            if(ch=='C'){
                scanf("%d%d%d",&left,&right,&value);
                upDate(1,1,n,left,right,value);
            }
            else if(ch=='Q'){
                ans=0;
                scanf("%d%d",&left,&right);
                Query(1,1,n,left,right);
                printf("%lld\n",ans);
            }
        }
    }
    return 0;
}