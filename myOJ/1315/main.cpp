#include <iostream>
#include <cstdio>
using namespace std;
const int N=30005;

struct Node{
    int a;
    int b;
    Node(int aa=0,int bb=1):a(aa),b(bb){}
}node[N];

int gcb(int x,int y){
    return y==0?x:gcb(y,x%y);
}

bool comp(Node x,Node y){
    if(x.a*y.b<x.b*y.a) return true;
    else return false;
}

int cnt=0;

void Merge(int low,int mid,int high){
    Node tmp[N];
    int i=low,j=mid,k=0;
    while(i<mid&& j<=high){
        if(comp(node[i],node[j])) tmp[k++]=node[i++];
        else tmp[k++]=node[j++];
    }
    while(i<mid) tmp[k++]=node[i++];
    while(j<=high) tmp[k++]=node[j++];

    for(i=0,k=low;k<=high;) node[k++]=tmp[i++];
}

void mergeSort(int low,int high){
    if(low>=high) return;
    int mid=(low+high)>>1;
    mergeSort(low,mid);
    mergeSort(mid+1,high);
    Merge(low,mid+1,high);
}

int main() {
    int n;
    scanf("%d",&n);
    for(int i=2;i<=n;++i){
        for(int j=1;j<i;++j){
            if(gcb(i,j)==1){
                node[cnt++].a=j;
                node[cnt-1].b=i;
            }
        }
    }
    mergeSort(0,cnt-1);
    printf("0/1\n");
    for(int i=0;i<cnt;++i)
        printf("%d/%d\n",node[i].a,node[i].b);
    printf("1/1\n");
    return 0;
}