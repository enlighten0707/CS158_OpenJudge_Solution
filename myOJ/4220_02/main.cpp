#include <iostream>
#include <cstdio>
#include <cmath>

const int N=200005;
int a[N],dp[N][33];
int n;

inline int Max(int a,int b){return a>b?a:b;}

void build(){
    for(int i=0;i<n;++i)
        dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<(j-1))<=n;++i)
            dp[i][j]=Max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
}

int Query(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return Max(dp[left][k],dp[right-(1<<k)+1][k]);
}

int main(){
    int q,left,right;
    scanf("%d%d",&n,&q);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    build();
    while(q--){
        scanf("%d%d",&left,&right);
        --left;--right;
        printf("%d\n",Query(left,right));
    }
    return 0;
}