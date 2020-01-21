#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE=10003;
int population[MAXSIZE][MAXSIZE];
long long res[MAXSIZE];

int main()
{
    int n,m,q;
    int x1,x2,y1,y2;
    cin>>n>>m>>q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cin>>population[i][j];
    }

    for (int k=0;k<q;++k)
    {
        res[k]=0;
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1-1;i<x2;++i)
        {
            for(int j=y1-1;j<y2;++j)
            {
                res[k]+=population[i][j];
            }
        }


    }
    for(int i=0;i<q;++i)
        cout<<res[i]<<'\n';

    return 0;
}

