#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAXSIZE=200005;
int dpmax[MAXSIZE][33],dpmin[MAXSIZE][33];
int a[MAXSIZE],b[MAXSIZE];
int n;
unsigned long long cnt=0;

void makeMaxRmq(){
    for(int i=0;i<n;++i)
        dpmax[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1<n;++i)
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}

int getMax(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return max(dpmax[left][k],dpmax[right-(1<<k)+1][k]);
}

void makeMinRmq(){
    for(int i=0;i<n;++i)
        dpmin[i][0]=b[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<j)-1<n;++i)
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}

int getMin(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return min(dpmin[left][k],dpmin[right-(1<<k)+1][k]);
}

int main(){
    long long ans=0,le,ri,tmp1,tmp2,va,vi;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    makeMinRmq();
    makeMaxRmq();
    for(int i=0;i<n;i++){
        le=i;
        ri=n-1;
        tmp1=-1;
        while(le<=ri){
            int mid=(le+ri)>>1;
            vi=getMin(i,mid);
            va=getMax(i,mid);
            if(vi==va){
                ri=mid-1;
                tmp1=mid;
            }
            else if(vi>va){
                le=mid+1;
            }
            else{
                ri=mid-1;
            }
        }
        if(tmp1!=-1)
        {
            le=i;
            ri=n-1;
            while(le<=ri)
            {
                int mid=(le+ri)>>1;
                vi=getMin(i,mid);
                va=getMax(i,mid);
                if(vi==va){
                    le=mid+1;
                    tmp2=mid;
                }
                else if(vi>va){
                    le=mid+1;
                }
                else{
                    ri=mid-1;
                }
            }
            ans+=tmp2-tmp1+1;
        }
    }
    printf("%lld\n",ans);

    return 0;
}
