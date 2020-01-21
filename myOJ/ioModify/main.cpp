#include <iostream>
#include <cstdio>
using namespace std;

void read(int &x){
    int f=1;
    x=0;
    char s=getchar();
    while(s<'0'||s>'9'){
        if(s=='-')f=-1;
        s=getchar();
    }
    while(s>='0'&&s<='9'){
        x=x*10+s-'0';
        s=getchar();
    }
    x*=f;
}

void print(int x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) print(x/10);
    putchar(x%10+'0');
}

int main() {
    int test1,test2;
    read(test1);
    read(test2);
    print(test1);
    print(test2);
    return 0;
}