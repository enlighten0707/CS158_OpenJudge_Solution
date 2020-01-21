#include <iostream>
#include <cstdio>
using namespace std;

const int MAXSIZE=1000005;
int a[MAXSIZE]={0},child[MAXSIZE]={0};
int main() {
    int n,parent;
    bool f=true;
    scanf("%d",&n);
    a[0]=1;
    for(int i=1;i<n;++i){
        scanf("%d",&parent);
        if(child[parent]==0){
            a[i]=a[parent]*2;
            ++child[parent];
        }
        else if(child[parent]==1){
            a[i]=a[parent]*2+1;
            ++child[parent];
        }
        else{
            f=false;
            break;
        }
        if(a[i]>n){
            f=false;
            break;
        }
    }
    if(f)cout<<"true";
    else cout<<"false";
    return 0;
}