#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int a[N];
int n,m;

bool check(int k){
    int cnt=0,i=0,tmp=0;
    while(i<n){
        while(tmp+a[i]<=k&&i<n){
            tmp+=a[i];
            ++i;
        }
        ++cnt;
        tmp=0;
    }
    if(cnt<=m) return true;
    return false;
}

int main() {
    int sum=0,maxs=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%d",&a[i]);
        sum+=a[i];
        if(a[i]>maxs) maxs=a[i];
    }

    int l=maxs,r=sum;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d",l);
    return 0;
}