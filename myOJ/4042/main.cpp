#include <iostream>
using namespace std;
const int MAXSIZE=300003;
int x[MAXSIZE],Left[MAXSIZE],Right[MAXSIZE];
int record[MAXSIZE];
int n;
long long sum=0;

int quickMod(int a,int b,int c)
{
    int ans=1;
    a=a%c;
    while(b>0)
    {
        if(b%2==1)
            ans=(ans*a)%c;
        b/=2;
        a=(a*a)%c;
    }
    return ans;
}
void Merge(int left,int mid,int right)
{
    int n1=mid-left+1;
    int n2=right-mid;
    int i,j,k;
    for(k=left,i=0;i<n1;++i,++k)
        Left[i]=x[k];
    for(k=mid+1,j=0;j<n2;++j,++k)
        Right[j]=x[k];
    for(i=0,j=0,k=left;i<n1&&j<n2;++k)
    {
        if(Left[i]<Right[j])
        {
            x[k]=Left[i];
            ++i;
        }
        else
        {
            x[k]=Right[j];
            ++j;
        }
    }
    if(i<n1)
    {
        for(;i<n1;++i,++k)
            x[k]=Left[i];
    }
    if(j<n2)
    {
        for(;j<n2;++j,++k)
            x[k]=Right[j];
    }
}
void mergeSort(int left,int right)
{
    if(left>=right) return;
    int mid=(left+right)/2;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    Merge(left,mid,right);
}
int main() {
    cin>>n;
    for(int i=0;i<n;++i)
        cin>>x[i];
    mergeSort(0,n-1);
    /*
    for(int i=0;i<n;++i)
        cout<<x[i]<<' ';
    cout<<endl;
    */
    record[0]=1;
    for(int i=1;i<n;++i)
        record[i]=quickMod(2,i,1000000009);

    for(int i=0;i<n;++i)
    {
        //cout<<x[i]<<"*("<<record[i]-record[n-i-1]<<")="<<x[i]*(record[i]-record[n-i-1])<<endl;
        sum+=(long long)(x[i])*(record[i]-record[n-i-1]);
        //cout<<sum<<endl;
    }

    cout<<sum;
    return 0;
}