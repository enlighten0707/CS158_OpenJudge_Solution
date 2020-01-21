#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
const int MAXSIZE=50005;
int dpmax[MAXSIZE][33],dpmin[MAXSIZE][33];
int a[MAXSIZE];
int n;

void makeMaxRmq(){
    for(int i=0;i<n;++i)
        dpmax[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;(i+(1<<j))-1<n;++i)
            dpmax[i][j]=max(dpmax[i][j-1],dpmax[i+(1<<(j-1))][j-1]);
}
int getMax(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return max(dpmax[left][k],dpmax[right-(1<<k)+1][k]);
}

void makeMinRmq(){
    for(int i=0;i<n;++i)
        dpmin[i][0]=a[i];
    for(int j=1;(1<<j)<=n;++j)
        for(int i=0;(i+(1<<j))<=n;++i)
            dpmin[i][j]=min(dpmin[i][j-1],dpmin[i+(1<<(j-1))][j-1]);
}
int getMin(int left,int right){
    int k=(int)(log(right-left+1.0)/log(2.0));
    return min(dpmin[left][k],dpmin[right-(1<<k)+1][k]);
}

int main() {
    int Q;
    int left,right;
    cin>>n>>Q;
    for(int i=0;i<n;++i)
        scanf("%d",&a[i]);
    makeMaxRmq();
    makeMinRmq();
    for(int i=0;i<Q;++i){
        scanf("%d%d",&left,&right);
        --left;--right;
        //printf("%d\n",getMax(left,right));
        //printf("%d\n",getMin(left,right));
        printf("%d\n",getMax(left,right)-getMin(left,right));
    }
}