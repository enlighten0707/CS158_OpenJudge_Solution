#include <iostream>
using namespace std;
const int MAXSIZE=1003;
int dp[MAXSIZE][33];

void init(int x[],int n);
int Log2(int n);
int Max(int a,int b);
int compFrequency(int num[],int n,int left,int right);

int main()
{
    int n;
    cin>>n;
    int a[MAXSIZE],f[MAXSIZE];
    for(int i=1;i<=n;++i)
        cin>>a[i];
    int pre=0,i=1;
    f[0]=0;
    while(i<=n)
    {
        if(a[i]==pre)
            f[i]=f[i-1]+1;
        else
            f[i]=1;
        pre=a[i];
        ++i;

    }

    for(int i=1;i<=n;++i)
        cout<<f[i]<<' ';
    int left,right;
    cin>>left>>right;
    int res=compFrequency(f,n,left,right);
    cout<<res;
    return 0;
}

void init(int x[],int n)
{
    int m=Log2(n)+1;
    for(int i=1;i<=n;++i)
    {
        dp[i][0]=x[i];
        for(int j=1;j<=m;++j)
            dp[i][j]=0;
    }
    for(int j=1;j<=m;++j)
    {
        for(int i=1;i<=n;++i)
        {
            int tmp=1;
            tmp<<=(j-1);
            if(i+tmp<=n)
                dp[i][j]=Max(dp[i][j-1],dp[i+tmp][j-1]);
            else
                dp[i][j]=dp[i][j-1];

        }
    }
}

int Log2(int n)
{
    int res=0;
    while(n>0)
    {
        n>>=1;
        ++res;
    }
    return --res;
}

int Max(int a,int b)
{
    return (a>b?a:b);
}

int RMQ(int num[],int n,int left,int right)
{
    if(left==right)return num[left];
    init(num,n);
    int res;
    int k=Log2(right-left);
    int tmp=1;
    tmp<<=k;
    res=Max(dp[left][k],dp[right-tmp+1][k]);
    return res;
}

int compFrequency(int num[],int n,int left,int right)
{
    int t=left;
    while(num[t]!=1)++t;
    int tmp=RMQ(num,n,t,right);
    return Max(tmp,t-left);
}
