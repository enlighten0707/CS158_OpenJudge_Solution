#include <iostream>
#include <cstdio>
#include <cstring>
using  namespace std;

const int MAXSIZE=2005;
char s[MAXSIZE],a[MAXSIZE],b[MAXSIZE];
bool flag1[MAXSIZE],flag2[MAXSIZE];

int main() {
    cin.getline(s,MAXSIZE);
    cin.getline(a,MAXSIZE);
    cin.getline(b,MAXSIZE);
    int len=strlen(s),len1=strlen(a),len2=strlen(b);
    for(int i=0;i+len2<=len;++i){
        flag2[i+len2-1]=true;
        for(int j=0;j<len2;++j){
            if(s[j+i]!=b[j]){
                flag2[i+len2-1]=false;
                break;
            }
        }
    }
    for(int i=0;i+len1<=len;++i){
        flag1[i]=true;
        for(int j=0;j<len1;++j){
            if(s[j+i]!=a[j]){
                flag1[i]=false;
                break;
            }
        }
    }
    for(int i=0;flag1[i]&&i+len1<=len;++i){
        for(int j=i;j<len;++j){
            if(i+len1<=j&&j-len2>=i)
                Hash(i,j);
        }
    }


}