#include <iostream>
#include <cstdio>
using namespace std;

const int N=10005;
int a[N],Left[N],Right[N];

void Merge(int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1,n2=high-mid;
    for(k=low,i=0;i<n1;++i,++k)
        Left[i]=a[k];
    for(k=mid+1,j=0;j<n2;++j,++k)
        Right[j]=a[k];
    for(i=0,j=0,k=low;i<n1&&j<n2;){
        if(Left[i]<Right[j])
            a[k++]=Left[i++];
        else a[k++]=Right[j++];
    }
    while(i<n1)
        a[k++]=Left[i++];
    while(j<n2)
        a[k++]=Right[j++];
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
    for(int i=0;i<n;++i)
        printf("%d ",a[i]);
    return 0;
}