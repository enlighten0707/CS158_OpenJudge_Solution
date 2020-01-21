#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int a[N],tmp[N];
long long cnt=0;

void Merge(int low,int mid,int high){
    int i=low,j=mid+1;
    int cur=0;
    while(i<=mid&&j<=high){
        if(a[i]<=a[j])
            tmp[cur++]=a[i++];
        else{
            tmp[cur++]=a[j++];
            cnt+=(long long)mid-i+1;
        }
    }
    while(i<=mid) tmp[cur++]=a[i++];
    while(j<=high) tmp[cur++]=a[j++];
    for(int m=0;m<cur;++m)
        a[low+m]=tmp[m];
}

void mergeSort(int low,int high){
    if(low>=high) return;
    int mid=(low+high)>>1;
    mergeSort(low,mid);
    mergeSort(mid+1,high);
    Merge(low,mid,high);
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    mergeSort(0,n-1);
    printf("%lld",cnt);
    //for(int i=0;i<n;++i)
        //printf("%d ",a[i]);
    return 0;
}