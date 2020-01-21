#include <iostream>
#include <cstdio>
using namespace std;

const int N=3400;
int num[N];

int main() {
    int n;
    scanf("%d",&n);
    num[0]=1;
    num[1]=1;
    for(int i=2;i<=n;++i){
        num[i]=num[i-1];
        for(int j=1;j<i;++j){
            num[i]+=num[j-1]*num[i-j-1];
            num[i]%=19301;
        }

    }
    printf("%d",num[n]);
    return 0;
}