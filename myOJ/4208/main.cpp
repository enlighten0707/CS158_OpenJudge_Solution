#include <iostream>
using namespace std;

const int MAXSIZE=12;
int res[MAXSIZE];

int main() {
    int n,tmp1,tmp2,a,b,x1,y1,x2,y2;
    cin>>n;

    for(int i=0;i<n;++i)
    {
        cin>>a>>b>>x1>>y1>>x2>>y2;
        /*
        if(a[i]==1||b[i]==1)
        {
            if(x1[i]<x2[i])
                tmp1=(x2[i]-x1[i]-1)/2;
            else tmp1=(x1[i]-x2[i]-1)/2;
            if(y1[i]<y2[i])
                tmp2=(y2[i]-y1[i]+1)/2;
            else tmp2=(y1[i]-y2[i]+1)/2;
            res[i]=tmp1+tmp2;
        }
         */

            tmp1=(x1+y1)/(2*a);
            tmp2=(x2+y2)/(2*a);
            int tmp3,tmp4;
            if(tmp1>0&&tmp2<0)
                tmp3=tmp1-tmp2-1;
            else if(tmp1<0&&tmp2>0)
                tmp3=tmp2-tmp1-1;
            else
            {
                if(tmp1>=tmp2)
                    tmp3=tmp1-tmp2;
                else
                    tmp3=tmp2-tmp1;
            }

            tmp1=(x1-y1)/(2*b);
            tmp2=(x2-y2)/(2*b);
            if(tmp1>0&&tmp2<0)
                tmp4=tmp1-tmp2-1;
            else if(tmp1<0&&tmp2>0)
                tmp4=tmp2-tmp1-1;
            else
            {
                if(tmp1>=tmp2)
                    tmp4=tmp1-tmp2;
                else
                    tmp4=tmp2-tmp1;
            }


            res[i]=tmp3>tmp4?tmp3:tmp4;


    }
    for(int i=0;i<n;++i)
        cout<<res[i]<<'\n';
    return 0;
}