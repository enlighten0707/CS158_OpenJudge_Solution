#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,m;
const int N=25;
long long a[N],b[N];

template <class T>
bool read(T &re) {
    re=0;
    int flag=1;
    char c=getchar();
    if(c=='-') flag=-1,c=getchar();
    while(c>='0'&&c<='9') re=re*10+c-'0',c=getchar();
    re*=flag;
    if(c=='\n') return false;
    return true;
}

int main() {
    int T;
    scanf("%d",&T);
    while(T--){
        memset(a,0,sizeof(a));
        memset(b,0, sizeof(b));
        scanf("%d%d",&n,&m);
        for(int i=1;i<=m;++i){

        }
    }
}