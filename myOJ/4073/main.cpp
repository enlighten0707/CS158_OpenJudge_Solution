#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;
const int N=100005;
int a[N],c[N];
int Left[N],Right[N];


void Merge(int low,int mid,int high){
    int i,j,k;
    int n1=mid-low+1,n2=high-mid;
    for(k=low,i=0;i<n1;++i,++k)
        Left[i]=c[k];
    for(k=mid+1,j=0;j<n2;++j,++k)
        Right[j]=c[k];
    for(i=0,j=0,k=low;i<n1&&j<n2;){
        if(Left[i]<Right[j])
            c[k++]=Left[i++];
        else c[k++]=Right[j++];
    }
    while(i<n1)
        c[k++]=Left[i++];
    while(j<n2)
        c[k++]=Right[j++];
}

void mergeSort(int low,int high){
    if(low>=high) return;
    int mid=(low+high)>>1;
    mergeSort(low,mid);
    mergeSort(mid+1,high);
    Merge(low,mid,high);
}

int main()
{
    int n;
    cin>>n;
    long long sum=0,x=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum+=a[i];
    }

    for(int i=2;i<=n;i++)   c[i]=c[i-1]+a[i];
    mergeSort(1,n);

    for(int i=1;i<=n;i++) {
        if(c[i]!=c[(n+1)/2]) ++x;
    }
    printf("%lld\n",x);
    return 0;
}