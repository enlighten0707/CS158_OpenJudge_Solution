#include <iostream>
using namespace std;

const int MAXSIZE=10;
int a[MAXSIZE],Left[MAXSIZE],Right[MAXSIZE];

void merge(int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    for(k=left,i=0;i<n1;++i,++k)
        Left[i]=a[k];
    for(k=mid+1,j=0;j<n2;++j,++k)
        Right[j]=a[k];
    for(i=0,j=0,k=left;i<n1&&j<n2;++k)
    {
        if(Left[i]<Right[j])
        {
            a[k]=Left[i];
            ++i;
        }
        else
        {
            a[k]=Right[j];
            ++j;
        }
    }
    if(i<n1)
    {
        for(;i<n1;++i,++k)
            a[k]=Left[i];
    }
    if(j<n2)
    {
        for(;j<n2;++j,++k)
            a[k]=Right[j];
    }
}

void mergeSort(int left,int right)
{
    if(left>=right)return;
    int mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    merge(left,mid,right);
}


int main() {
    for(int i=0;i<6;++i)cin>>a[i];
    mergeSort(0,5);
    for(int i=0;i<6;++i)cout<<a[i]<<' ';
    return 0;
}

