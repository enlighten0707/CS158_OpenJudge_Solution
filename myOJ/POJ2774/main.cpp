#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=1000005,BASE=13331;
typedef unsigned long long ull;
ull xp[N],hash1[N],hash2[N],a[N];

void init(){
    xp[0]=1;
    for(int i=1;i<N;++i)
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

char str[N],str2[N];
int len1,len2;

int Search(int low,int high,int x){
    int mid;
    while(low<=high){
        mid=(low+high)>>1;
        if(x==a[mid]) return mid;
        if(x<a[mid]) high=mid-1;
        else low=mid+1;
    }
    return -1;
}
bool check(int L){
    int cnt=0;
    for(int i=0;i+L-1<len1;++i)
        a[cnt++]=getHash(i,L,hash1);
    sort(a,a+cnt);
    for(int i=0;i+L-1<len2;++i){
        ull tmp=getHash(i,L,hash2);
        if(binary_search(a,a+cnt,tmp)) return true;
    }
    return false;
}

int main() {
    init();
    while( scanf("%s%s",str,str2)!=EOF)
    {
        len1=makeHash(str,hash1);
        len2=makeHash(str2,hash2);
        int l=0,r=min(len1,len2),mid;
        while(l<=r)
        {
            mid=(l+r)>>1;
            if(check(mid)) l=mid+1;
            else r=mid-1;
        }
        printf("%d\n",r);
    }
    return 0;
}