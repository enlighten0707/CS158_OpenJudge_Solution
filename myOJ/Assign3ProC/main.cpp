#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int Cnt[5];

int main() {
    int n;
    char ch[105];

    while(scanf("%d",&n)!=EOF){
        cin.get();
        for(;n>0;--n){
            for(int i=0;i<5;++i)
                Cnt[i]=0;

            cin.getline(ch,105);
            for(int i=0;i<strlen(ch);++i){
                switch(ch[i]){
                    case 'a':++Cnt[0];break;
                    case 'e':++Cnt[1];break;
                    case 'i':++Cnt[2];break;
                    case 'o':++Cnt[3];break;
                    case 'u':++Cnt[4];break;
                    default:break;
                }
            }
            printf("%s%d\n","a:",Cnt[0]);
            printf("%s%d\n","e:",Cnt[1]);
            printf("%s%d\n","i:",Cnt[2]);
            printf("%s%d\n","o:",Cnt[3]);
            printf("%s%d\n","u:",Cnt[4]);
            if(n>1) printf("\n");
        }
    }
}