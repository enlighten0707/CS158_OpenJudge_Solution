#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSIZE=200005;
const int MAXQ=1000005;
const int BASE=1000000007;
int a[MAXSIZE],res[MAXQ],Left[MAXSIZE],Right[MAXSIZE];

void Merge(int l,int mid,int r){
    int i,j,k;
    int n1=mid-l+1,n2=r-mid,n=r-l+1;
    for(k=l,i=0;k<=mid;++k,++i)
        Left[i]=a[k];
    for(k=mid+1,j=0;k<=r;++k,++j)
        Right[j]=a[k];
    for(k=l,i=0,j=0;k<=r&&i<n1&&j<n2;++k){
        if(Left[i]>Right[j]){
            a[k]=Left[i];
            ++i;
        }
        else{
            a[k]=Right[j];
            ++j;
        }
    }
    if(i<n1){
        for(;i<n1;++i,++k)
            a[k]=Left[i];
    }
    if(j<n2){
        for(;j<n2;++j,++k)
            a[k]=Right[j];
    }
}

void mergeSort(int l,int r){
    if(l>=r) return;
    int mid=(l+r)>>1;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    Merge(l,mid,r);
}

int main(){
    int T,n,k;
    scanf("%d%d",&T,&n);
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    mergeSort(0,n-1);
    res[0]=a[0];
    for(int i=1;i<n;++i)
        res[i]=(res[i-1]+a[i])%BASE;
        while(T--){
        scanf("%d",&k);
        printf("%d\n",res[k-1]);
    }
    return 0;
}
