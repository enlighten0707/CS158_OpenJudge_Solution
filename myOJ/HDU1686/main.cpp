#include <iostream>
#include <cstdio>
#include <cstring>

using  namespace std;

const int BASE=13331,MAXSIZE=1000005;
typedef unsigned long long ull;
ull xp[MAXSIZE],hash1[MAXSIZE],hash2[MAXSIZE];

void init(){
    xp[0]=1;
    for(int i=1;i<MAXSIZE;++i)
        xp[i]=xp[i-1]*BASE;
}

int makeHash(char str[],ull hash[]){
    int len=strlen(str);
    hash[len]=0;
    for(int i=len-1;i>=0;--i)
        hash[i]=hash[i+1]*BASE+(str[i]-'a'+1);
    return len;
}

ull getHash(int i,int L,ull hash[]){
    return hash[i]-hash[i+L]*xp[L];
}

char str[MAXSIZE],str2[MAXSIZE];

int main() {
    init();
    int t;
    scanf("%d",&t);
    while(t--){
        int ans=0;
        scanf("%s%s",str,str2);
        int len1=makeHash(str,hash1);
        int len2=makeHash(str2,hash2);
        ull tmp=getHash(0,len1,hash1);
        for(int i=0;i<len2-len1+1;++i){
            if(getHash(i,len1,hash2)==tmp)
                ++ans;
        }
        printf("%d\n",ans);
    }
    return 0;
}