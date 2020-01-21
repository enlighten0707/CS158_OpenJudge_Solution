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
        for(int i=0;i+(1<<(j-1))-1<n;++i)
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
        for(int i=0;i+(1<<(j-1))-1<n;++i)
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}

int getMin(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return min(dpmin[left][k],dpmin[right-(1<<k)+1][k]);
}

void binarySearch(){
    int left,right,tmp1,tmp2,curMax,curMin,mid;
    for(int i=0;i<n;++i){
        left=i;
        right=n-1;
        tmp1=-1;
        tmp2=-1;
        while(left<=right){
            mid=(left+right)/2;
            curMax=getMax(i,mid);
            curMin=getMin(i,mid);
            if(curMax==curMin){
                tmp1=mid;
                right=mid-1;
            }
            else if(curMax>curMin) right=mid-1;
            else left=mid+1;
        }
        if(tmp1!=-1){
            left=i;
            right=n-1;
            while(left<=right){
                mid=(left+right)/2;
                curMax=getMax(i,mid);
                curMin=getMin(i,mid);
                if(curMax==curMin){
                    tmp2=mid;
                    left=mid+1;
                }
                else if(curMax>curMin) right=mid-1;
                else left=mid+1;
            }
        if(tmp2!=-1)
            cnt+=tmp2-tmp1+1;
        }
    }
}
int main() {
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&b[i]);
    makeMaxRmq();
    makeMinRmq();
    binarySearch();
    printf("%I64d\n",cnt);

    return 0;
}