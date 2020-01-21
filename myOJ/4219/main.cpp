#include <iostream>
using namespace std;

const int MAXSIZE=200003,MAXQ=1e6,BASE=1000000007;
int a[MAXSIZE],sum[MAXSIZE],res[MAXQ],Left[MAXSIZE],Right[MAXSIZE];
int n,T;

void merge(int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    for(k=left,i=0;i<n1;++i,++k)
        Left[i]=a[k];
    for(k=mid+1,j=0;j<n2;++j,++k)
        Right[j]=a[k];
    //for(i=0;i<n1;++i)cout<<Left[i];
    //for(j=0;j<n2;++j)cout<<Right[j];
    for(i=0,j=0,k=left;i<n1&&j<n2;++k)
    {
        if(Left[i]>Right[j])
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
    cin>>T>>n;
    int k;
    long long tmp;
    for(int i=0;i<n;++i)
        cin>>a[i];
    mergeSort(0,n-1);

    sum[0]=a[0];
    for(int i=1;i<n;++i)
    {
        tmp=(long long)(sum[i-1]+a[i])%BASE;
        sum[i]=(int)tmp;
    }

    for(int i=0;i<T;++i)
    {
        cin>>k;
        res[i]=sum[k-1];
    }

    for(int i=0;i<T;++i)
        cout<<res[i]<<'\n';
    return 0;
}
