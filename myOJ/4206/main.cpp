#include <iostream>

using namespace std;

const int MAXSIZE=1003;

char image[MAXSIZE][MAXSIZE];
int Compress(int n,int m,int k);

int main()
{
    int n,m;
    cin>>n>>m;
    cin.get();
    for(int i=0;i<n;++i)
        cin.getline(image[i],1003);

    int maxL=(n>m?n:m);
    int mincnt=m*n;
    int tmp;

    tmp=Compress(n,m,2);
    if(tmp<mincnt)
        mincnt=tmp;

    for(int k=3;k<maxL;k+=2)
    {
        tmp=Compress(n,m,k);
        if(tmp<mincnt)
            mincnt=tmp;
    }
    cout<<mincnt;

    return 0;

}

int Compress(int n,int m,int k)
{
    int cnt=0;
    int tmp;
    int startRow,startCol;
    for(startRow=0;startRow+k<=n;startRow+=k)
    {
        for(startCol=0;startCol+k<=m;startCol+=k)
        {
            tmp=0;
            for(int i=startRow;i<startRow+k;++i)
            {
                for(int j=startCol;j<startCol+k;++j)
                {
                    if(image[i][j]=='1')++tmp;
                }
            }
            if(tmp<=k*k/2)cnt+=tmp;
            else cnt+=k*k-tmp;
        }
    }

    for(int i=startRow;i<n;++i)
    {
        for(int j=0;j<m;++j)
        {
            if(image[i][j]=='1') ++cnt;
        }
    }

    for(int i=0;i<startRow;++i)
    {
        for(int j=startCol;j<m;++j)
        {
            if(image[i][j]=='1') ++cnt;
        }
    }

    return cnt;
}
