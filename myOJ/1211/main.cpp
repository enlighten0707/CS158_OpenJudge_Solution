#include <iostream>
#include <cstdio>
using namespace std;
const int MAXSIZE=100005;
int a[MAXSIZE]={0},child[MAXSIZE]={0},parent[MAXSIZE]={0};
bool root[MAXSIZE]={true};

int main() {
    int n,lchild,rchild;
    bool f=true;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) root[i]=true;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&lchild,&rchild);
        if(lchild) {
            if(parent[lchild]){
                f=false;
                break;
            }
            parent[lchild]=i;
            child[lchild]=1;
            root[lchild]=false;
        }
        if(rchild){
            if(parent[rchild]){
                f=false;
                break;
            }
            parent[rchild]=i;
            child[rchild]=2;
            root[rchild]=false;
        }
    }

    if(f) {
        for (int i = 1; i <= n; ++i) {
            if (root[i]) {
                a[i] = 1;
                break;
            }
        }

        for (int i = n - 1; i >= 1; --i) {
            if (child[i] == 1)
                a[i] = a[parent[i]] * 2;
            else if (child[i] == 2)
                a[i] = a[parent[i]] * 2 + 1;
            else {
                f = false;
                break;
            }
            if (a[i] > n) {
                f = false;
                break;
            }
        }
    }
    if(f) cout<<"Y";
    else cout<<"N";
    return 0;
}