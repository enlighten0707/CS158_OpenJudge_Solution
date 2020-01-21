#include <iostream>
using namespace std;
const int MAXSIZE=1003;
int dp[MAXSIZE][33],x[MAXSIZE];
int res[20];
int n,m;

void init();
int Log2(int n);
int Max(int a,int b);

int main()
{
    cin>>n;
    int numOfQuery;
    cin>>numOfQuery;

    for(int i=1;i<=n;++i)
        cin>>x[i];

    m=Log2(n)+1;

    init();

    int left,right;
    for(int i=0;i<numOfQuery;++i)
    {
        cin>>left>>right;
        if(left==right)res[i]=x[left];
        else
        {
            int k=Log2(right-left);
            int tmp=1;
            tmp<<=k;
            res[i]=Max(dp[left][k],dp[right-tmp+1][k]);
        }
    }
    for(int i=0;i<numOfQuery;++i)
     cout<<res[i]<<endl;

    return 0;
}

void init()
{

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