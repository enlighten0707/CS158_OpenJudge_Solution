#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int num[30];

int main() {
    char str[1000005];
    while(gets(str)){
        memset(num,0, sizeof(num));
        int len=strlen(str);
        for(int i=0;i<len;++i){
            if(str[i]>='a'&&str[i]<='z')
                ++num[(int)(str[i]-'a')];
        }

        for(int i=0;i<26;++i)
            printf("%c:%d\n",i+'a',num[i]);
        printf("\n");
    }
    return 0;
}