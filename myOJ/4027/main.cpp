#include <iostream>
#include <cstdio>
using namespace std;

const int N=100005;
int a[N],b[N];
int dp[2][N];

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    int cur=1,pre=0;
    for(int i=0;i<=n;++i)dp[0][i]=0;
    dp[1][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i-1]==b[j-1])
                dp[cur][j]=dp[pre][j-1]+1;
            else
                dp[cur][j]=max(dp[cur][j-1],dp[pre][j]);
        }
        swap(cur,pre);
    }
    printf("%d",dp[pre][n]);
    return 0;
}
