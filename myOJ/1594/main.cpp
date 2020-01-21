#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE=1e4+3;
int population[MAXSIZE][MAXSIZE];

class LongLongInt
{
    friend LongLongInt operator+(const LongLongInt&,const LongLongInt&);
    friend ostream&operator<<(ostream&,const LongLongInt&);

private:
    char *num;
public:
    LongLongInt(const char *n="");
    LongLongInt(const LongLongInt&);
    LongLongInt& operator=(const LongLongInt&);
    ~LongLongInt(){delete num;}
};

char* add(const char*s1 ,const char* s2);

LongLongInt::LongLongInt(const char *n) {
    int len=strlen(n);
    num=new char[len+1];
    for(int i=0;i<len;++i)num[len-1-i]=n[i];
    num[len]='\0';
}

LongLongInt::LongLongInt(const LongLongInt & other) {
    num=new char[strlen(other.num)+1];
    strcpy(num,other.num);
}

LongLongInt&  LongLongInt::operator=(const LongLongInt &right) {
    if(this==&right)return *this;
    delete num;
    num=new char[strlen(right.num)+1];
    strcpy(num,right.num);
    return *this;
}

ostream& operator<<(ostream& os,const LongLongInt &obj)
{
    if(strlen(obj.num)==0)os<<0;
    else
    {
        for(int i=strlen(obj.num);i>=0;--i)
            os<<obj.num[i];
    }
    return os;
}

LongLongInt operator+(const LongLongInt &n1, const LongLongInt &n2) {
    LongLongInt n;
    delete n.num;
    n.num=add(n1.num,n2.num);
    return n;
}

char* add(const char* s1,const char* s2)
{
    int len1=strlen(s1),len2=strlen(s2);
    int minLen=(len1<len2?len1:len2);
    int len=(len1>len2?len1:len2)+1;
    int carry=0,result,i;

    char* num=new char[len+1];
    for(i=0;i<minLen;++i)
    {
        result=s1[i]-'0'+s2[i]-'0'+carry;
        num[i]=result%10+'0';
        carry=result/10;
    }

    while(i<len1)
    {
        result=s1[i]-'0'+carry;
        num[i]=result%10+'0';
        carry=result/10;
        ++i;
    }

    while(i<len2)
    {
        result=s2[i]-'0'+carry;
        num[i]=result%10+'0';
        carry=result/10;
        ++i;
    }
    if(carry!=0)num[i++]=carry+'0';
    num[i]='\0';

    return num;
}

int main()
{
    int n,m,q,pos;
    int x1,x2,y1,y2;
    int tmpNum;
    char *tmpChar;

    cin>>n>>m>>q;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            cin>>population[i][j];
    }

    for (int k=0;k<q;++k)
    {
        LongLongInt res("0");
        cin>>x1>>y1>>x2>>y2;
        for(int i=x1-1;i<x2;++i)
        {
            for(int j=y1-1;j<y2;++j)
            {
                tmpNum=population[i][j];
                pos=0;
                tmpChar=new char[11];
                while(tmpNum>0)
                {
                    tmpChar[pos]=tmpNum%10+'0';
                    tmpNum/=10;
                    ++pos;
                }
                tmpChar[pos]='\0';
                LongLongInt tmp(tmpChar);
                res=res+tmp;
            }
        }
        cout<<res<<'\n';
        delete []tmpChar;
    }

    return 0;
}

