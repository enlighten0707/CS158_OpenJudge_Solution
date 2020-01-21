#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXSIZE=1005;
const double LOG2=0.69314718;
int dp[MAXSIZE][33];
int a[MAXSIZE];
int n;

int Max(int a,int b){
    return (a>b?a:b);
}
void makeMaxRmq(){
    for(int i=0;i<n;++i)
        dp[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j){
        for(int i=0;i+(1<<j)-1<n;++i)
            dp[i][j]=Max(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);
    }
}
int getMax(int left,int right){
    int k=(int)(log(right-left+1.0)/LOG2);
    return Max(dp[left][k],dp[right-(1<<k)+1][k]);
}

int main() {
    int T,q,left,right;
    scanf("%d",&T);
    for(int i=0;i<T;++i){
        scanf("%d",&n);
        for(int j=0;j<n;++j)
            scanf("%d",&a[j]);
        makeMaxRmq();
        scanf("%d",&q);
        for(int j=0;j<q;++j){
            scanf("%d%d",&left,&right);
                --left;--right;
                printf("%d\n",getMax(left,right));
            }
        }
    return 0;
}