#include<iostream>
#include<cstring>
using namespace std;
int f[30][30],root[30][30];

int getnum(int l,int r)
{
    if(l>r)return 1;
    if(f[l][r]==-1)
    {
        for(int k=l;k<=r;k++)
        {
            int now=getnum(l,k-1)*getnum(k+1,r)+f[k][k];
            if(now>f[l][r])
            {
                f[l][r]=now;
                root[l][r]=k;
            }
        }
    }
    return f[l][r];
}
void dfs(int l,int r)
{
    if(l>r)return;
    cout<<root[l][r]<<' ';
    dfs(l,root[l][r]-1);
    dfs(root[l][r]+1,r);
}
int main()
{
    int n;
    scanf("%d",&n);
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++)
    {
        cin>>f[i][i];
        root[i][i]=i;
    }
    printf("%d\n",getnum(1,n));
    dfs(1,n);
    return 0;
}