#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const int N=200005;
#define LSON rt<<1
#define RSON rt<<1|1

int a[N],segT[N<<2];
int n;
inline int max(int x,int y){return x>y?x:y;}
inline void pushup(int rt){
    segT[rt]=max(segT[LSON],segT[RSON]);
}
void build(int rt,int l,int r){
    if(l==r){
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
        segT[rt]=w;
        return;
    }
    int mid=(l+r)>>1;
    if(x<=mid) Update(LSON,l,mid,x,w);
    else Update(RSON,mid+1,r,x,w);
    pushup(rt);
}

int Query(int rt,int l,int r,int ll,int rr){
    if(ll<=l&&rr>=r)
        return segT[rt];
    int mid=(l+r)>>1;
    int ans=0;
    if(ll<=mid) ans+=Query(LSON,l,mid,ll,rr);
    if(rr>mid) ans=max(ans,Query(RSON,mid+1,r,ll,rr));
    return ans;
}


int main() {
    int m;
    char ch;
    int A,B;
    while(scanf("%d%d",&n,&m)!=EOF) {
        for (int i = 1; i <= n; ++i)
            scanf("%d", &a[i]);

        build(1, 1, n);

        while (m--) {
            getchar();
            scanf(" %c%d%d", &ch, &A, &B);
            if (ch == 'U')
                Update(1, 1, n, A, B);
            else if (ch == 'Q') {
                printf("%d\n", Query(1,1,n,A,B));
            }
        }
    }
    return 0;
}