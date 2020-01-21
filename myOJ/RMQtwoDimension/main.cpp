#include <iostream>
#include <cmath>
using namespace std;
const int MAXSIZE=6;
int dp[MAXSIZE][MAXSIZE][4];
int x[MAXSIZE][MAXSIZE];

int Max(int a,int b,int c,int d);
int Log2(int n);
int Max2(int a,int b);

int main()
{
    int n,b;
    cin>>n>>b;

    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
        {
            cin>>x[i][j];
            dp[i][j][0]=x[i][j];
        }
    }
    int m=Log2(n)+1;
    for(int ii=1;ii<=m;++ii)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                int tmp=1;
                tmp<<=(ii-1);
                if(i+tmp<=n&&j+tmp<=n)
                    dp[i][j][ii]=Max(dp[i][j][ii-1],dp[i][j+tmp][ii-1],dp[i+tmp][j][ii-1],dp[i+tmp][j+tmp][ii-1]);
                else {
                    if (i+tmp <= n)
                        dp[i][j][ii] = Max2(dp[i][j][ii - 1], dp[i + tmp][j][ii - 1]);
                    else if (j + tmp <= n)
                        dp[i][j][ii] = Max2(dp[i][j][ii - 1], dp[i][j + tmp][ii - 1]);
                    else
                        dp[i][j][ii] = dp[i][j][ii - 1];
                }
            }
        }
    }
    /*
    for(int ii=0;ii<=m;++ii)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
                cout<<dp[i][j][ii]<<' ';
            cout<<endl;
        }
        cout<<endl;
    }
     */
    int startX,startY;
    cin>>startX>>startY;
    int k=Log2(b);
    int tmp=1;
    tmp<<=k;
    cout<<dp[startX][startY][k]<<endl;
    cout<<dp[startX][startY+b-tmp][k]<<endl;
    cout<<dp[startX+b-tmp][startY][k]<<endl;
    cout<<dp[startX+b-tmp][startY+b-tmp][k]<<endl;
    int res=Max(dp[startX][startY][k],dp[startX][startY+b-tmp][k],dp[startX+b-tmp][startY][k],dp[startX+b-tmp][startY+b-tmp][k]);
    cout<<res;
    return 0;

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

int Max(int a,int b,int c,int d)
{
    int tmp1=(a>b?a:b);
    int tmp2=(c>d?c:d);
    return (tmp1>tmp2?tmp1:tmp2);
}

int Max2(int a,int b)
{return (a>b?a:b);}
