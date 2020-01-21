#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int MAXSIZE=200003;
const double LOG2=0.69314718;
int a[MAXSIZE];
int dp[MAXSIZE][33]={0};
int n,T,tmp,k;

//int Log2(int num);

int main() {
    cin>>n>>T;
    for(int i=1;i<=n;++i)
        cin>>a[i];

    for(int i=1;i<=n;++i)
        dp[i][0]=a[i];

    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=1;i<=n;++i)
        {
            dp[i][j]=dp[i][j-1];
            k=1;
            k<<=(j-1);
            if(i+k<=n)
                dp[i][j]=max(dp[i][j],dp[i+k][j-1]);
        }
    }
/*
    for(int j=0;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
            cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<' ';
        cout<<endl;
    }
*/
    int left,right,cnt,num;
    for(int i=0;i<T;++i){
        cin>>left>>right;
        k=(int)(log(right-left+1.0)/LOG2);
        tmp=(1<<k);
        cout<<max(dp[left][k],dp[right-tmp+1][k])<<'\n';
    }
    return 0;
}
/*
int Log2(int num)
{
    int cnt=0;
    while(num>0)
    {
       num/=2;
       ++cnt;
    }
    return (--cnt);
}*/