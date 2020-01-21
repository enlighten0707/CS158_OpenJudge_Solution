#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef unsigned long long ull;

long long n;
const int MOD=1000000007;

long long f(long long k){
    long long m[2][2]={1,1,1,0};
    long long result[2][2]={1,0,0,1};
    long long temp[2][2];
    while(k){
        if(k&1){
            temp[0][0] = (result[0][0] * m[0][0]%MOD + result[0][1] * m[1][0]%MOD)%MOD;
            temp[0][1] = (result[0][0] * m[0][1]%MOD + result[0][1] * m[1][1]%MOD)%MOD;
            temp[1][0] = (result[1][0] * m[0][0]%MOD + result[1][1] * m[1][0]%MOD)%MOD;
            temp[1][1] = (result[1][0] * m[0][1]%MOD + result[1][1] * m[1][1]%MOD)%MOD;
            memcpy(result,temp, sizeof(long long)*4);
        }
        temp[0][0] = (m[0][0] * m[0][0]%MOD + m[0][1] * m[1][0]%MOD)%MOD;
        temp[0][1] = (m[0][0] * m[0][1]%MOD + m[0][1] * m[1][1]%MOD)%MOD;
        temp[1][0] = (m[1][0] * m[0][0]%MOD + m[1][1] * m[1][0]%MOD)%MOD;
        temp[1][1] = (m[1][0] * m[0][1]%MOD+ m[1][1] * m[1][1]%MOD)%MOD;
        memcpy(m,temp, sizeof(long long)*4);
        k>>=1;
    }
    return result[1][0];
}

int main(){
    scanf("%lld",&n);
    printf("%lld",f(n+1));
    return 0;
}
