#include<iostream>
#include <cstdio>
using namespace std;

const int MAXN=1e5+10;

#define LSON p<<1
#define RSON p<<1|1

typedef long long ll;
ll s[MAXN<<2],col[MAXN<<2];

void up(int p){
    s[p]=s[LSON]+s[RSON];
}

void down(int p,int l,int r){
    if(col[p]){
        int mid=(l+r)/2;
        s[LSON]+=(ll)col[p]*(mid-l+1);
        s[RSON]+=(ll)col[p]*(r-mid);
        col[LSON]+=col[p];
        col[RSON]+=col[p];
        col[p]=0;
    }
}

void modify(int p,int l,int r,int x,int y,ll c){
    if(x<=l&&y>=r){
        s[p]+=(ll)c*(r-l+1);
        col[p]+=(ll)c;
        return;
    }
    down(p,l,r);
    int mid=(l+r)>>1;
    if(y<=mid) modify(LSON,l,mid,x,y,c);
    else if(x>mid) modify(RSON,mid+1,r,x,y,c);
    else{
        modify(LSON,l,mid,x,mid,c);
        modify(RSON,mid+1,r,mid+1,y,c);
    }
    /*
    if(x<=mid){
        modify(LSON,l,mid,x,y,c);
    }
    if(y>mid){
        modify(RSON,mid+1,r,x,y,c);
    }*/
    up(p);
}

ll query(int p,int l,int r,int x,int y){
    if(x==l&&y==r){
        return s[p];
    }
    down(p,l,r);
    int mid=(l+r)>>1;
    if(y<=mid) return query(LSON,l,mid,x,y);
    else if(x>mid) return query(RSON,mid+1,r,x,y);
    else return query(LSON,l,mid,x,mid)+query(RSON,mid+1,r,mid+1,y);
}

int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    int ip1,ip2;
    ll ip3;
    for(int i=1;i<=n;i++){
        scanf("%d",&ip1);
        modify(1,1,n,i,i,ip1);
    }
    char ch;
    for(int i=1;i<=m;i++){
        getchar();
        scanf(" %c",&ch);
        if(ch=='Q'){
            scanf("%d%d",&ip1,&ip2);
            printf("%lld\n",query(1,1,n,ip1,ip2));
        }
        else {
            scanf("%d%d%lld",&ip1,&ip2,&ip3);
            modify(1,1,n,ip1,ip2,ip3);
        }
    }
    return 0;
}
