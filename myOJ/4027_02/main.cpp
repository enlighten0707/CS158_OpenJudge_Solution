#include<cstdio>
#include<iostream>

using namespace std;

const int N=100005;
int a[N],b[N],f[N];
int n;

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        b[x]=i;
    }
    for(int i=1;i<=n;i++){
        int x;
        scanf("%d",&x);
        a[i]=b[x];
    }
    int len=1;
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        if(f[len]<a[i]) f[++len]=a[i];
        else{
            int mid,l=1,r=len;
            while(l<r){
                mid=(l+r)/2;
                if(f[mid]>a[i]) r=mid;
                else l=mid+1;
            }
            if(f[l]>a[i]) f[l]=a[i];
        }
    }
    printf("%d",len);
    return 0;
}
