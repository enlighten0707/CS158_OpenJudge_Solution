#include <iostream>
#include <cstdio>

#define LSON rt<<1;
#define RSON rt<<1|1;
const int maxn=1e6+7;
int a[maxn];
int segT[maxn<<2];
int tag[maxn<<2];

void pushup(int rt){
    segT[rt]=segT[LSON]+segT[RSON];
}
void build(int l,int r,int rt){
    if(l==r){
        segT[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,LSON);
    build(mid+1,r,RSON);
    pushup(rt);
}

inline void pushDown(int rt,int ln,int rn){
    if(tag[rt]){//
        segT[LSON]+=tag[rt]*ln;
        segT[RSON]+=tag[rt]*rn;
        tag[LSON]+=tag[rt];
        tag[RSON]+=tag[rt];//+= 累加
        tag[rt]=0;
    }
}
/*
void Update(int L,int C,int l,int r,int rt){
    if(l==r){
        segT[rt]+=C;
        return;
    }
    int mid=(l+r)>>1;
    if(l<=mid) Update(L,C,l,mid,LSON);
    else Update(L,C,mid+1,r,RSON);
    pushup(rt);
}*/
void Update(int L,int R,int C,int l,int r,int rt){
    if(L<=l&&r<=R){
        segT[rt]+=(r-l+1)*C;
        tag[rt]=C;
        return;
    }
    int mid=(l+r)>>1;
    pushDown(rt,mid-l+1,r-mid);
    if(L<=mid) Update(L,R,C,l,mid,LSON);
    if(R>mid) Update(L,R,C,mid+1,r,RSON);
    pushup(rt);
}

int Query(int L,int R,int l,int r,int rt){//查询时需要下推
    if(L==l&&r==R){
        return segT[rt];
    }
    int mid=(l+r)>>1;
    pushDown(rt,mid-l+1,)//
    int ans=0;
    if(L<=mid)ans+=Query(L,R,l,)//
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
//覆盖：区间求和，下推 不同

