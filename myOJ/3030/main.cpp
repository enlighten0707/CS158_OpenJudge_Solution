#include <iostream>

using namespace std;

int dp[1003];
int value[103],Time[103];

int Max(int a,int b);

int main()
{
    int t,n;
    int i;
    cin>>t>>n;
    for(i=1;i<=n;i++)
        cin>>Time[i]>>value[i];

    for(int i=1;i<=t;++i)
        dp[i]=0;

    for(i=1;i<=n;++i)
    {
        for(int j=t;j>=Time[i];--j)
        {
            dp[j]=Max(dp[j],dp[j-Time[i]]+value[i]);
        }
    }
    cout<<dp[t];
    return 0;
}

int Max(int a,int b)
{
    return(a>b?a:b);
}