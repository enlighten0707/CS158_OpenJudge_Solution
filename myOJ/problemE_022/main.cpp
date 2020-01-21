#include <iostream>
#include <cstdio>
#include <cmath>

using  namespace std;
const int N=200005;
int a[N],b[N],dpmax[N][33],dpmin[N][33];
int n;

void makeMaxRmq(){
    for(int i=0;i<n;++i)
        dpmax[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<(j-1))<=n;++i)
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}

void makeMinRmq(){
    for(int i=0;i<n;++i)
        dpmin[i][0]=b[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;i+(1<<(j-1))<=n;++i)
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}

int getMax(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return max(dpmax[left][k],dpmax[right-(1<<k)+1][k]);
}

int getMin(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return min(dpmin[left][k],dpmin[right-(1<<k)+1][k]);
}

int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    makeMaxRmq();
    makeMinRmq();
    long long ans=0;
    int le,ri,vb,va,mid,tmp1,tmp2;
    for(int i=0;i<n;++i){
        le=i;
        ri=n-1;
        tmp1=-1;
        while(le<=ri){
            mid=(le+ri)/2;
            va=getMax(i,mid);
            vb=getMin(i,mid);
            if(va==vb){
                ri=mid-1;
                tmp1=mid;
            }
            else if(va>vb) ri=mid-1;
            else le=mid+1;
        }
        if(tmp1!=-1){
            le=i;
            ri=n-1;
            while(le<=ri){
                mid=(le+ri)/2;
                va=getMax(i,mid);
                vb=getMin(i,mid);
                if(va==vb){
                    le=mid+1;
                    tmp2=mid;
                }
                else if(va>vb) ri=mid-1;
                else le=mid+1;
            }
            ans+=tmp2-tmp1+1;
        }
    }
    printf("%lld",ans);
    return 0;
}