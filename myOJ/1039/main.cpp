#include <iostream>
#include <cstdio>
using namespace std;
const int MAXSIZE=100005;
int a[MAXSIZE]={0},b[MAXSIZE]={0};

void postOrder(int root){
    if(b[2*root])postOrder(2*root);
    if(b[2*root+1])postOrder(2*root+1);
    printf("%d ",b[root]);
}
int main() {
    int n,lc,rc,num;
    scanf("%d",&n);
    scanf("%d%d%d",&num,&lc,&rc);
    a[num]=1;
    if(lc!=-1)a[lc]=2*a[num];
    if(rc!=-1)a[rc]=2*a[num]+1;
    for(int i=1;i<n;++i){
        scanf("%d%d%d",&num,&lc,&rc);
        if(lc!=-1)a[lc]=2*a[num];
        if(rc!=-1)a[rc]=2*a[num]+1;
    }

    for(int i=1;i<=n;++i)
        printf("%d ",a[i]);
    printf("\n");
    for(int i=1;i<=n;++i)
        b[a[i]]=i;
    postOrder(1);
    return 0;
}