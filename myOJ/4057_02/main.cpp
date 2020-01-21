#include <iostream>
#include <cstring>

using namespace std;

const int MAXSIZE=10003;

int findMaxReverse(char* s);

int main()
{
    char ch[MAXSIZE];
    cin.getline(ch,MAXSIZE);
    int len=strlen(ch);
    int maxLen=0,maxPos=0,curLen;
    for(int i=0;i<len-1;++i)
    {
        curLen=findMaxReverse(ch+i);
        if(curLen>maxLen)
        {
            maxLen=curLen;
            maxPos=i;
        }
    }
    cout<<maxLen;
    if(maxLen>0)
    {
        cout<<endl;
        for(int i=0;i<maxLen;++i)
            cout<<*(ch+maxPos+i);
    }
    return 0;
}

int findMaxReverse(char* s)
{
    int maxlen=strlen(s);
    bool f;
    int i,j;
    for(int len=maxlen;len>=2;--len)
    {
        f=true;
        i=0;
        j=len-1;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                f=false;
                break;
            }
            else
            {
                ++i;
                --j;
            }
        }
        if(f) return len;
    }
    return 0;
}
