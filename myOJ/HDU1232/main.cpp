#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=1005;
int parent[N];

int Find(int x){
    int r=x;
    while(r!=parent[r])
        r=parent[r];
    int i=x,j;
    while(i!=r){
        j=parent[i];
        parent[i]=r;
        i=j;
    }
    return r;
}

void Combine(int a,int b){
    int aa=Find(a),bb=Find(b);
    if(aa!=bb)
        parent[aa]=bb;
}

int main() {
    int n,m,a,b;
    while(~scanf("%d",&n)) {
        if(!n) break;
        int sum = 0;
        for (int i = 1; i <=n; ++i)
            parent[i] = i;
        scanf("%d", &m);
        while (m--) {
            scanf("%d%d", &a, &b);
            Combine(a, b);
        }
        for (int i = 1; i <=n; ++i) {
            if (parent[i] == i)
                ++sum;
        }
        printf("%d\n", sum - 1);
    }
    return 0;
}