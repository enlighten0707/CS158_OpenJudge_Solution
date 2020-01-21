#include <iostream>
#include <cstdio>
using namespace std;

const int N=100005;
typedef long long ll;
struct node{
    int len;
    int value;
}leg[N];
int cost[205]={0};
ll Back[N];
int num[N]={0};

void Merge(int left,int mid,int right){
    int n1=mid-left+1,n2=right-mid;
    node a[N],b[N];
    int i,j,k;
    for(i=0,k=left;i<n1;++k,++i)
        a[i]=leg[k];
    for(j=0,k=mid+1;j<n2;++k,++j)
        b[j]=leg[k];
    for(i=0,j=0,k=left;i<n1&&j<n2;++k){
        if(a[i].len<b[j].len){
            leg[k]=a[i];
            ++i;
        }
        else{
            leg[k]=b[j];
            ++j;
        }
    }
    if(i<n1){
        for(;i<n1;++i,++k)
            leg[k]=a[i];
    }
    if(j<n2){
        for(;j<n2;++j,++k)
            leg[k]=b[j];
    }
}

void mergeSort(int left,int right){
    if(left>=right) return;
    int mid=(left+right)>>1;
    mergeSort(left,mid);
    mergeSort(mid+1,right);
    Merge(left,mid,right);
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d",&leg[i].len);
        ++num[leg[i].len];
    }
    for(int i=0;i<n;++i)
        scanf("%d",&leg[i].value);
    mergeSort(0,n-1);
    ll sum=0;
    for(int i=n-1;i>0;--i){
        sum+=(ll)leg[i].value;
        if(leg[i].len!=leg[i-1].len)
            Back[leg[i-1].len]=sum;
    }
    ll ans=Back[leg[0].len];
    ++cost[leg[0].value];
    for(int i=1;i<n;++i){
        if(leg[i].len!=leg[i-1].len){
            int an=i-num[leg[i].len]+1;
            sum=Back[leg[i].len];
            if(an>0){
                for(int j=1;j<=200;++j){
                    if(cost[j]){
                        if(cost[j]<an){
                            sum+=cost[j]*j;
                            an-=cost[j];
                        }
                        else{
                            sum+=an*j;
                            an=0;
                            break;
                        }
                    }
                }
            }
            ans=min(ans,sum);
        }
        cost[leg[i].value]++;
    }
    printf("%d",ans);
    return 0;
}